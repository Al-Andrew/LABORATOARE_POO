#pragma once
#include <cstdint>
#include <iostream>
#include <cmath>

template<typename Key_T, typename Value_T>
class MapElem
{
public:
    MapElem() {};
    ~MapElem() { if( next != nullptr ) delete next; };
    Key_T key;
    Value_T value;
    uint32_t index = 0;
    bool empty = true;
    MapElem<Key_T,Value_T>* next = nullptr;
};

template<typename T>
uint64_t Hash(T value);

//Good enough, simple enough
template<>
uint64_t Hash<int>(int value)
{
    constexpr static long double A = 0.6180339887498948; // (sqrt(5) -1)/2; // Magic number 
    constexpr static uint64_t M = (1ull << 63ull);
    long double param = static_cast<long double>(value)*A;
    long double fract, intp;
    fract = std::modf(param, &intp);
    return static_cast<long double>(M)*fract;
}

template<typename Key_T, typename Value_T>
class Iterator
{
    public:
    using iterator_category = std::forward_iterator_tag;
    using Elem_T = MapElem<Key_T, Value_T>;
    class Triple
    {
        public:
        Triple(Elem_T* elem)
        {
            k = elem->key;
            i = elem->index;
            v = elem->value;
        }
        Key_T k;
        Value_T v;
        uint64_t i;
    };

    public:
    Iterator(Elem_T* buffer, uint64_t capacity)
        :m_buffer(buffer), m_capacity(capacity), m_curr_index(0), m_curr_node(nullptr) { m_curr_node = get_next_node(); }
    Iterator(Elem_T* buffer, Elem_T* node)
        :m_buffer(buffer), m_curr_node(node) {}
    ~Iterator() = default;

    Triple operator*() { return Triple(m_curr_node); };
    Iterator& operator++() { m_curr_node = get_next_node(); return *this; }
    
    friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_curr_node == b.m_curr_node; }
    friend bool operator!=(const Iterator& a, const Iterator& b) { return !(a == b); }

    private:
    Elem_T* get_next_node()
    {   
        if( m_curr_node != nullptr && m_curr_node->next != nullptr )
            return m_curr_node->next;

        for(; m_curr_index < m_capacity ; ++m_curr_index)
        {
            Elem_T* c_node = (m_buffer + m_curr_index);
            if( c_node->empty == false )
            {
                ++m_curr_index;
                return c_node;
            }
        }
        return m_buffer + m_capacity;
    }

    private:
    Elem_T* m_buffer = nullptr;
    uint64_t m_curr_index = 0;
    uint64_t m_capacity = 0;
    Elem_T* m_curr_node = nullptr;
};

template <typename Key_T, typename Value_T>
class Map
{
public:
    using Elem_T = MapElem<Key_T, Value_T>;
    using Iter_T = Iterator<Key_T, Value_T>;
private:
    Elem_T* m_data;
    uint32_t m_capacity;
    uint32_t m_size;

public:
    Map()
        :m_capacity(15), m_size(0) {  m_data = new Elem_T[15]; }
    ~Map() { delete[] m_data; }

    void Set(Key_T key, Value_T val)
    {
        uint64_t index = Hash<Key_T>(key) % m_capacity;
        Elem_T* c_elem = (m_data + index);

        //Looking for our node in the chain
        while( c_elem->empty != true && c_elem->key != key && c_elem->next != nullptr )
        {
            c_elem = c_elem->next;
        }

        // 1st element in chain
        if( c_elem->empty == true )
        {
            c_elem->key = key;
            c_elem->value = val;
            c_elem->index = m_size++;
            c_elem->empty = false;
            return;
        }

        // key already exists
        if( c_elem->key == key )
        {
            c_elem->value = val;
            return;
        }

        // We need to add a new one
        if( c_elem->next == nullptr)
        {
            Elem_T* n_elem = (c_elem->next = new Elem_T);
            n_elem->key = key;
            n_elem->value = val;
            n_elem->index = m_size++;
            n_elem->empty = false;
            return;
        }
    }

    bool Get(const Key_T& key, Value_T& value) const
    {
        uint64_t index = Hash<Key_T>(key) % m_capacity;
        Elem_T* c_elem = (m_data + index);

        //Looking for our node in the chain
        while( c_elem->key != key && c_elem->next != nullptr )
        {
            c_elem = c_elem->next;
        }

        if( c_elem->empty == true )
            return false;
        
        value = c_elem->value;
        return true;
    }

    bool Delete(const Key_T& key)
    {
        uint64_t index = Hash<Key_T>(key) % m_capacity;
        Elem_T* c_elem = (m_data + index);

        //Looking for our node in the chain
        while( c_elem->key != key && c_elem->next != nullptr )
        {
            c_elem = c_elem->next;
        }

        if( c_elem->empty == true )
            return false;
        
        Elem_T* first_in_chain = (m_data + index);

        //First and last at the same time
        if(c_elem == first_in_chain && c_elem->next == nullptr )
        {
            c_elem->empty = true;
            return true;
        }
        
        //First in the chain and not the last one :P
        if( c_elem == first_in_chain && c_elem->next != nullptr)
        {
            //Copy the second's data in this one
            Elem_T* second = c_elem->next;
            c_elem->key = second->key;
            c_elem->value = second->value;
            c_elem->index = second->index;
            c_elem->next = second->next;
            c_elem->empty = second->empty;
            //Separate the second one from the chain and call it's desctructor
            second->next = nullptr;
            delete second;
            return true;
        }

        //Somewhere in the middle
        if( c_elem->next != nullptr )
        {
            //find the predecessor;
            auto predecessor = first_in_chain;
            while(predecessor->next != c_elem )
                predecessor = predecessor->next;
            //And the successor;
            auto successor = c_elem->next;
            //Link the predecessor to the successor and unlink this one
            predecessor->next = successor;
            c_elem->next = nullptr;
            //delete this one
            delete c_elem;
            return true;
        }

        //At the end
        //Here we can just delete it
        delete c_elem;
        return true;
    }

    Value_T& operator[](Key_T key)
    {
        uint64_t index = Hash<Key_T>(key) % m_capacity;
        Elem_T* c_elem = (m_data + index);

        //Looking for our node in the chain
        while( c_elem->empty != true && c_elem->key != key && c_elem->next != nullptr )
        {
            c_elem = c_elem->next;
        }

        // 1st element in chain
        if( c_elem->empty == true )
        {
            c_elem->key = key;
            c_elem->index = m_size++;
            c_elem->empty = false;
            return c_elem->value;
        }

        // key already exists
        if( c_elem->key == key )
            return c_elem->value;
        
        // We need to add a new one
        Elem_T* n_elem = (c_elem->next = new Elem_T);
        n_elem->index = m_size++;
        n_elem->empty = false;
        return n_elem->value;       
    }

    bool Includes(const Map<Key_T, Value_T>& other) const
    {
        //Check all the keys in other
        Value_T check;
        for(auto [key, value, index] : other)
        {
            std::cout << "Checking " << key << "\n";
            bool is = Get(key, check);
            std::cout << "Key " << is << "\n";
            if( is == false )
                return false;
        }
        return true;
    }

    void Clear()
    {
        for(uint64_t i=0; i < m_capacity ; ++i)
        {
            m_data[i].~Elem_T();
            new (&m_data[i]) Elem_T();
        }
        m_size = 0;
    }

    uint64_t Count() const
    {
        return m_size;
    }

    Iter_T begin() const { return Iter_T(m_data, m_capacity); }
    Iter_T end() const { return Iter_T(m_data, m_data + m_capacity); }

    void Print() const
    {
        for(uint64_t i = 0; i < m_capacity ; ++i)
        {
            std::cout << i << " : ";
            Elem_T* c_elem = &m_data[i];
            while( true )
            {
                if( c_elem->empty == false)
                    std::cout << "[" << c_elem->key << "," << c_elem->value << "," << c_elem->index << "]" << " -> ";
                if( c_elem->next != nullptr )
                    c_elem = c_elem->next;
                else
                    break;
            }
            std::cout << "\n";
        }
    }
};
