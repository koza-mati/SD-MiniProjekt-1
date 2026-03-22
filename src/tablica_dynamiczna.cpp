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


void tablicaDynamiczna::addAtPosition(int element, int position) {
    if (position <= 0) {
        addToFront(element);
        return;
    }
    if (position >= size_) {
        addAtEnd(element);
        return;
    }

    if (size_ >= capacity_)
        grow();

    for (int i = size_; i > position; --i)
        data[i] = data[i - 1];

    data[position] = element;
    size_++;
}

void tablicaDynamiczna::removeFromBeginning() {
    if (isEmpty()) return;

    for (int i = 0; i < size_ - 1; ++i)
        data[i] = data[i + 1];

    size_--;
}

void tablicaDynamiczna::removeFromEnd() {
    if (!isEmpty())
        size_--;
}

void tablicaDynamiczna::removeFromPosition(int position) {
    if (isEmpty()) return;

    if (position <= 0) {
        removeFromBeginning();
        return;
    }

    if (position >= size_ - 1) {
        removeFromEnd();
        return;
    }

    for (int i = position; i < size_ - 1; ++i)
        data[i] = data[i + 1];

    size_--;
}

int tablicaDynamiczna::find(int element) const {
    for (int i = 0; i < size_; ++i)
        if (data[i] == element)
            return i;

    return -1;
}
