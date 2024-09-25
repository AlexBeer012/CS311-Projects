#ifndef msarray_hpp
#define msarray_hpp

#include <cstddef>  
#include <stdexcept>
#include <utility>   

template<typename t>

class msarray {
public:
    using value_type = t;
    using size_type = std::size_t;

    // default constructor: 8
    msarray() : _size(8), _data(new t[8]()) {}

    // 1-parameter constructor
    explicit msarray(size_type size) : _size(size), _data(new t[size]()) {}

    // 2-parameter constructor
    msarray(size_type size, const t& value) : _size(size), _data(new t[size]) {
        for (size_type i = 0; i < _size; ++i) {
            _data[i] = value;
        }
    }

    // copy constructor
    msarray(const msarray& other) : _size(other._size), _data(new t[other._size]) {
        for (size_type i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    // move constructor
    msarray(msarray&& other) noexcept : _size(other._size), _data(other._data) {
        other._size = 0;
        other._data = nullptr;
    }

    // copy assignment
    msarray& operator=(const msarray& other) {
        if (this != &other) {
            t* new_data = new t[other._size];
            for (size_type i = 0; i < other._size; ++i) {
                new_data[i] = other._data[i];
            }
            delete[] _data;
            _data = new_data;
            _size = other._size;
        }
        return *this;
    }

    // move assignment
    msarray& operator=(msarray&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = other._data;
            other._size = 0;
            other._data = nullptr;
        }
        return *this;
    }

    // destructor
    ~msarray() {
        delete[] _data;
    }

    // access element with bounds checking
    t& operator[](size_type index) {
        if (index >= _size) throw std::out_of_range("index out of bounds");
        return _data[index];
    }

    // access element 
    const t& operator[](size_type index) const {
        if (index >= _size) throw std::out_of_range("index out of bounds");
        return _data[index];
    }

    // return the size of the array
    size_type size() const {
        return _size;
    }

    // return pointer to the first 
    t* begin() {
        return _data;
    }

    const t* begin() const {
        return _data;
    }

    // return pointer to one-past the last 
    t* end() {
        return _data + _size;
    }

    const t* end() const {
        return _data + _size;
    }

    // equality op
    bool operator==(const msarray& other) const {
        if (_size != other._size) return false;
        for (size_type i = 0; i < _size; ++i) {
            if (_data[i] != other._data[i]) return false;
        }
        return true;
    }

    // inequality op
    bool operator!=(const msarray& other) const {
        return !(*this == other);
    }

    // less-than op
    bool operator<(const msarray& other) const {
        size_type min_size = (_size < other._size) ? _size : other._size;
        for (size_type i = 0; i < min_size; ++i) {
            if (_data[i] < other._data[i]) return true;
            if (_data[i] > other._data[i]) return false;
        }
        return _size < other._size;
    }

    // other comparison op
    bool operator<=(const msarray& other) const {
        return !(other < *this);
    }

    bool operator>(const msarray& other) const {
        return other < *this;
    }

    bool operator>=(const msarray& other) const {
        return !(*this < other);
    }

private:
    size_type _size;
    t* _data;
};

#endif 
