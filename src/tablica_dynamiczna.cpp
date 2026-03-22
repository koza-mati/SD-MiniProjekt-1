#include "tablica_dynamiczna.hpp"

tablicaDynamiczna::tablicaDynamiczna(int initialCapacity)
    : data(nullptr), size_(0), capacity_(initialCapacity <= 0 ? 1 : initialCapacity) {
    data = new int[capacity_];
}

tablicaDynamiczna::~tablicaDynamiczna() {
    delete[] data;
}

void tablicaDynamiczna::grow() {
    int newCap = capacity_ * 2;
    int* newData = new int[newCap];

    for (int i = 0; i < size_; ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity_ = newCap;
}