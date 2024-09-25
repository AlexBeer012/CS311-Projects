// Alex Beer
// Univeristy of Alaska Fairbanks
// CS 311 Data Structures and Algorithms
// September 15th, 2024
// Creating .hpp for msarray_test.cpp. The goal is to create a "Moderately Smart Array Class" while testing various constructors and operators

#ifndef MSARRAY_HPP
#define MSARRAY_HPP

#include <cstddef> 
#include <stdexcept> 
#include <utility>  
#include <algorithm>  

template <typename T>
class MSArray {
public:
    using value_type = T;
    using size_type = std::size_t;

    // Default constructor
    MSArray()
        : _size(8), _data(new T[8]) {}

    // 1-parameter constructor
    explicit MSArray(size_type size)
        : _size(size), _data(new T[size]) {}

    // 2-parameter constructor
    MSArray(size_type size, const T & value)
        : _size(size), _data(new T[size])
    {
        std::fill(_data, _data + _size, value);
    }

    // Copy constructor
    MSArray(const MSArray & other)
        : _size(other._size), _data(new T[other._size])
    {
        std::copy(other._data, other._data + other._size, _data);
    }

    // Move constructor
    MSArray(MSArray && other) noexcept
        : _size(other._size), _data(other._data)
    {
        other._size = 0;
        other._data = nullptr;
    }

    // Destructor
    ~MSArray()
    {
        delete[] _data;
    }

    // Copy assignment
    MSArray & operator=(const MSArray & other)
    {
        if (this != &other) {
            T * newData = new T[other._size];
            std::copy(other._data, other._data + other._size, newData);
            delete[] _data;
            _size = other._size;
            _data = newData;
        }
        return *this;
    }

    // Move assignment
    MSArray & operator=(MSArray && other) noexcept
    {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = other._data;
            other._size = 0;
            other._data = nullptr;
        }
        return *this;
    }

    // Bracket operator
    T & operator[](size_type index)
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Bracket operator
    const T & operator[](size_type index) const
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Return the size of the array
    size_type size() const
    {
        return _size;
    }

    // Return a pointer to the start
    T * begin()
    {
        return _data;
    }

    // Return a const pointer to the start
    const T * begin() const
    {
        return _data;
    }

    // Return a pointer to one past the end
    T * end()
    {
        return _data + _size;
    }

    // Return a const pointer to one past the end
    const T * end() const
    {
        return _data + _size;
    }

    // Equality operator
    bool operator==(const MSArray & other) const
    {
        return _size == other._size && std::equal(_data, _data + _size, other._data);
    }

    // Inequality operator
    bool operator!=(const MSArray & other) const
    {
        return !(*this == other);
    }

    // Lexicographic comparison operator <
    bool operator<(const MSArray & other) const
    {
        return std::lexicographical_compare(_data, _data + _size, other._data, other._data + other._size);
    }

    // Lexicographic comparison operator <=
    bool operator<=(const MSArray & other) const
    {
        return !(other < *this);
    }

    // Lexicographic comparison operator >
    bool operator>(const MSArray & other) const
    {
        return other < *this;
    }

    // Lexicographic comparison operator >=
    bool operator>=(const MSArray & other) const
    {
        return !(*this < other);
    }

private:
    size_type _size;  // Size of the array
    T * _data;        // Pointer to array
};

#endif  


// When Running. We get 1 failed and I couldn't figure it out. 