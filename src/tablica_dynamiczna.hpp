#pragma once
#include <iostream>

class tablicaDynamiczna {
private:
    int* data;
    int size_;
    int capacity_;

    void grow();

public:
    explicit tablicaDynamiczna(int initialCapacity = 4);
    ~tablicaDynamiczna();
};