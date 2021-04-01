#pragma once
#include <cstddef>
#include <memory>
#include <utility>
#include <functional>


template <typename T>
struct Iterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    Iterator() {};

    Iterator(T* pointer)
        :m_ptr(pointer) {}

    ~Iterator() = default;

    T* operator->(){ return m_ptr; }
    T& operator*(){ return (*m_ptr); }

    Iterator& operator++() { m_ptr++; return *this ; }
    Iterator operator++(int) { Iterator tmp = (*this); ++(*this); return tmp; }
    Iterator& operator--() { m_ptr--; return *this ; }
    Iterator operator--(int) { Iterator tmp = (*this); --(*this); return tmp; }
    friend Iterator operator+(const Iterator& a, difference_type diff){ return Iterator(a.m_ptr+diff); }
    friend Iterator operator+(difference_type diff, const Iterator& a){ return Iterator(a.m_ptr+diff); }
    friend Iterator operator-(const Iterator& b, difference_type diff) { return Iterator(b.m_ptr - diff); }
    friend difference_type operator-(const Iterator& b, const Iterator& a) { return static_cast<ptrdiff_t>(b.m_ptr - a.m_ptr); }


    T& operator[](size_t index) { return *(m_ptr + index); }

    friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }
    friend bool operator!=(const Iterator& a, const Iterator& b) { return !(a == b); }
    bool operator<(const Iterator& oth) { return m_ptr<oth.m_ptr; }
    bool operator<=(const Iterator& oth) { return *this < oth || *this == oth ; }
    bool operator>(const Iterator& oth) { return !(*this <= oth ); }
    bool operator>=(const Iterator& oth) { return !(*this < oth ); }

private:
    T* m_ptr;
};


template <typename T>
class Vector
{
public:
    Vector() { m_data = new T[2]; m_capacity = 2; }
    Vector(size_t size)
        :Vector()
    { for(size_t i=0; i < size; ++i) push_back(T()); }

    ~Vector()
    { clear(); ::operator delete(m_data, m_capacity*sizeof(T)); }

    void push_back(const T& value)
    {
        if( m_size >= m_capacity )
            resize(m_capacity*2);
        m_data[m_size++] = value;
    }

    void push_back(T&& value)
    {
        if( m_size >= m_capacity )
            resize(m_capacity*2);

        m_data[m_size++] = std::move(value);
    }

    void emplace(const T& value, size_t index)
    {
        if( index < m_size && index >= 0 )
        {
            if( m_size >= m_capacity )
                resize(m_capacity*2);

            for(size_t i=m_size; i > index ; --i )
                m_data[i] = m_data[i-1];

            m_data[index] = value;
            m_size++;
        }
    }

    void pop_back()
    {
        if( m_size > 0)
        {
            m_data[--m_size].~T();
        }
    }

    void erase(size_t index)
    {
        if( index < m_size && index >= 0)
        {
            for(size_t i=index; i < m_size ; ++i )
                m_data[i] = m_data[i+1];
            m_size--;
        }
    }

    void clear()
    {
        for(size_t i=0; i < m_size ; ++i)
            m_data[i].~T();

        m_size = 0;
    }

    void sort(std::function<bool(const T&, const T&)> compare = [](const T& a, const T& b){return a<b;})
    {
        for(size_t i = 0; i < m_size ; ++i)
        {
            size_t max_index = i;
            for(size_t j = i; j < m_size; ++j)
                if( compare(m_data[j], m_data[max_index] ) )
                    max_index = j;

            std::swap(m_data[i], m_data[max_index]);
        }
    }

    int find(const T& value, std::function<bool(const T&, const T&)> equals = [](const T& a, const T& b){return a==b;})
    {
        for(size_t i = 0; i < m_size ; ++i)
        {
            if( equals(value, m_data[i]) )
                return i;
        }
        return -1;
    }

    Iterator<T> begin(){ return Iterator<T>(m_data); }
    Iterator<T> end(){ return Iterator<T>(m_data+m_size); }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    size_t last_index() const { return m_size - 1; }

    const T& operator[](size_t index) const { return m_data[index]; }
    T& operator[](size_t index) { return m_data[index]; }


private:

    void resize(size_t new_capacity)
    {  
        if( new_capacity < m_size )
            m_size = new_capacity;

        T* new_data = (T*)::operator new(sizeof(T)*new_capacity);
        for(size_t i = 0; i < m_size ; ++i)
            new (&new_data[i]) T(std::move(m_data[i]));

        for(size_t i=0; i < m_size ; ++i)
            m_data[i].~T();

        ::operator delete(m_data, m_capacity*sizeof(T));
        m_data = new_data;
        m_capacity = new_capacity;
    }

    T* m_data;
    size_t m_size = 0;
    size_t m_capacity = 0;
};



