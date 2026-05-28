#pragma once

template <typename T>
class Array
{
    public:
        Array();             
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();
        
        Array& operator=(const Array& other);
        T&     operator[](unsigned int index);
        
        unsigned int size() const;

    private:
        T*           _data;
        unsigned int _size;
};

#include "Array.tpp"