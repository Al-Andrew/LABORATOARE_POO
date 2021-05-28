#pragma once
#include <exception>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** List;
public:

	ArrayIterator(T** List, int current)
		:List(List), Current(current) {}

	ArrayIterator& operator++() { Current++; return *this; } 
	ArrayIterator& operator--() { Current--; return *this; }

	bool operator==(ArrayIterator<T> &oth) { return (List==oth.List) && (Current == oth.Current); }
	bool operator!=(ArrayIterator<T> &oth) { return !(*this == oth); }

	T* GetElement() { return List[Current]; }
};

class ArrayException final : public std::exception
{
public: 
	ArrayException(const char* mes)
		:msg(mes) {}
	const char* msg;
	virtual const char* what() const throw()
	{
		return msg;
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	Array()
		:List(nullptr), Capacity(0), Size(0) {} // Lista nu e alocata, Capacity si Size = 0
	~Array()
		{ 
			if ( List != nullptr )
				delete[] List;
		} // destructor
	Array(int capacity)
	{ 
		if( capacity >= 1 )
		{
			List = new T*[capacity];
			Capacity = capacity;
			Size = 0;
		} 
		else
			throw ArrayException("ArrayException: Trying to construct with null/negative capacity");
	} // Lista e alocata cu 'capacity' elemente
	Array(const Array<T> &otherArray)
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		if( otherArray.List == nullptr )
			List = nullptr;
		else
		{
			if( List != nullptr )
				delete[] List;
			List = new T*[Capacity];
			for(int i=0; i < Size ; ++i)
				new (&List[i]) T*(otherArray.List[i]);
		} 
	} // constructor de copiere

	const T& operator[] (int index) const
	{
		if( index < 0 || index >= Size )
			throw ArrayException("Index out of bounds");
		return *List[index];
	} // arunca exceptie daca index este out of range

	//This requires T to be copy constructable
	const Array<T>& operator+=(const T &newElem)
	{
		if( Size >= Capacity )
			throw ArrayException("Array capacity exceeded");

		List[Size++] = new T(newElem);
		return *this;
	} // adauga un element de tipul T la sfarsitul listei si returneaza this
	
	const Array<T>& Insert(int index, const T &newElem)
	{
		if( index < 0 || index >= Size )
			throw ArrayException("Index out of bounds");
		List[index] = new T(newElem);
		return *this;
	} // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
	const Array<T>& Insert(int index, const Array<T>& otherArray)
	{
		if( index < 0 || index >= Size )
			throw ArrayException("Index out of bounds");
		if( index + otherArray.Size > Capacity )
			throw ArrayException("Not enough space to add the array");

		for(int i = 0; i < otherArray.Size ; ++i )
		{
			if( index + i < Size )
				List[index+i] = new T(otherArray[i]);
			else
				this->operator+=(otherArray[i]);  
		}
		return *this;
	} //adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
	const Array<T>& Delete(int index)
	{
		if( index < 0 || index >= Size )
			throw ArrayException("ArrayException: Index out of bounds");
		delete List[index];
		--Size;
		for(int i = 0; i < Size; i++)
			List[index + i] = List[index + i + 1]; 
		return *this;
	} // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator==(const Array<T> &otherArray)
	{	
		if( Capacity != otherArray.Capacity || Size != otherArray.Size )
			return false;
		return ( std::mismatch(List, List + Size, otherArray.List ) == List + Size );
	}// Comparison operator

	bool operator=(const Array<T> &otherArray)
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		if( otherArray.List == nullptr )
			return false;
		else
		{
			if( List != nullptr )
				delete[] List;
			List = new T*[Capacity];
			for(int i=0; i < Size ; ++i)
				new (&List[i]) T*(otherArray.List[i]);
		} 
		return true;
	}


	T** maxElement(int Start = 0, int End = Size, int(*compare)(const T& a, const T& b) = [](const T& a, const T& b) -> int{ return a < b;})
	{
		int max = Start;
		if( Size == 0 && List == nullptr && Capacity == 0)
			throw ArrayException("Can't have max element in empty/uninitialized array");
		for(int i = Start; i < End ; ++i)
			if( compare(*List[max],*List[i]) )
				max = i;
		return (List + max);
	}

	void Sort()
	{
		Sort( [](const T& a, const T& b) -> int { return a > b; } );
	} // sorteaza folosind comparatia intre elementele din T

	void Sort(int(*compare)(const T&, const T&))
	{
		for(int i = 0; i < Size ; i++)
		{
			std::ptrdiff_t max = maxElement(i,Size,compare) - List;
 			std::swap(List[i], List[max]);
		}
	} // sorteaza folosind o functie de comparatie

	void Sort(Compare *comparator)
	{
		Sort([](const T& a, const T& b) { return comparator->CompareElements(&a, &b); });
	} // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem)
	{
		return BinarySearch(elem, [](const T& a, const T& b) -> int{ return a==b; });
	} // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int lo = 0;
		int hi = Size;
		while( lo < hi )
		{
			int mid = ( lo + hi )/2;
			if( elem <= *List[mid] )
				hi = mid;
			else
				lo = mid + 1;
		}  
		return compare(*List[lo], elem)?lo:-1;
	}//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare *comparator)
	{
		return BinarySearch(elem, [](const T& a, const T& b) -> int { return comparator->CompareElements(a,b); });	
	}//  cauta un element folosind binary search si un comparator

	int Find(const T& elem)
	{
		return Find(elem, [](const T& a, const T& b) -> int { return a == b;});
	} // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for(int i = 0; i < Size ; i++)
			if( compare(elem, *List[i]))
				return i;
		return -1;
	}//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare *comparator)
	{
		return Find(elem, [](const T& a, const T& b) -> int { return comparator->CompareElments(a,b);});
	}//  cauta un element folosind un comparator

	friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
	{
		os << "[";
		for(int i = 0; i < arr.GetSize() - 1 ; ++i)
			os << *arr.List[i] << ", ";
			os << *arr.List[arr.GetSize() - 1];
		os << "]";
		return os;
	}

	int GetSize() const { return Size; } 
	int GetCapacity() const { return Capacity; }

	ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, 0); }
	ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List, Size); }
};