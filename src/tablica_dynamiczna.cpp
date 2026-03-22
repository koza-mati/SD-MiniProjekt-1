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

bool tablicaDynamiczna::isEmpty() const {
    return size_ == 0;
}

int tablicaDynamiczna::getSize() const {
    return size_;
}

void tablicaDynamiczna::addToFront(int element) {
    if (size_ >= capacity_)
        grow();

    for (int i = size_; i > 0; --i)
        data[i] = data[i - 1];

    data[0] = element;
    size_++;
}

void tablicaDynamiczna::addAtEnd(int element) {
    if (size_ >= capacity_)
        grow();

    data[size_++] = element;
}