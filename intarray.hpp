// intarray.hpp
// notes from class cs 311
// Alex Beer
// 09-06-2024

#include <cstddef> // for std::size_t
#include <iostream>

class IntArray {
public:

    using size_type = std::size_t;
    using value_type = int;

    IntArray(size_type size) 
        :_arrayptr(new value_type[size])
    {}

    ~IntArray() {
        delte [] _arrayptr;
    }

    value_type & operator [](size_type index) {
        return _arrayptr[index];
    }

    const value_type & operator(size_type index) const {
        return _arrayptr[index];
    }

private:

    value_type * _arrayptr;

};