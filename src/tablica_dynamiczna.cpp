#include <iostream>
#include "tablica_dynamiczna.hpp"

// konstruktor: alokacja bufora o zadanej początkowej pojemności (min. 1)
tablicaDynamiczna::tablicaDynamiczna(int initialCapacity)
    : data(nullptr), size_(0), capacity_(initialCapacity <= 0 ? 1 : initialCapacity) {
    data = new int[capacity_];
}

// destruktor: zwolnienie pamięci bufora
tablicaDynamiczna::~tablicaDynamiczna() {
    delete[] data;
}

// podwajanie pojemności i kopiowanie starych elementów do nowego bufora
void tablicaDynamiczna::grow() {
    int newCap = capacity_ * 2;
    int* newData = new int[newCap];

    for (int i = 0; i < size_; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity_ = newCap;
}

// sprawdzamy czy tablica jest pusta (size_ == 0)
bool tablicaDynamiczna::isEmpty() const {
    return size_ == 0;
}

// zwracamy aktualną liczbę elementów
int tablicaDynamiczna::getSize() const {
    return size_;
}

// zwracamy element na określonej pozycji
int tablicaDynamiczna::getAt(int index) const {
    return data[index];
}

// dodawanie na początku: ewentualny grow, przesunięcie w prawo, wstawienie na indeks 0
void tablicaDynamiczna::addToFront(int element) {
    if (size_ >= capacity_) {
        grow();
    }

    for (int i = size_; i > 0; --i) {
        data[i] = data[i - 1];
    }

    data[0] = element;
    size_++;
}

// dodawanie na końcu tablicy
void tablicaDynamiczna::addAtEnd(int element) {
    if (size_ >= capacity_) {
        grow();
    }

    data[size_++] = element;
}

// dodawanie elementu na określoną pozycję (indeks); pozycja <= 0 -> początek, >= rozmiaru -> koniec
void tablicaDynamiczna::addAtPosition(int element, int position) {
    if (position <= 0) {
        addToFront(element);
        return;
    }
    if (position >= size_) {
        addAtEnd(element);
        return;
    }

    if (size_ >= capacity_) {
        grow();
    }

    for (int i = size_; i > position; --i) {
        data[i] = data[i - 1];
    }

    data[position] = element;
    size_++;
}

// usuwanie z początku: przesunięcie w lewo o jeden indeks
void tablicaDynamiczna::removeFromBegining() {
    if (isEmpty()) {
        return;
    }

    for (int i = 0; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }

    size_--;
}

// usuwanie ostatniego elementu (zmniejszenie size_)
void tablicaDynamiczna::removeFromEnd() {
    if (!isEmpty()) {
        size_--;
    }
}

// usuwanie elementu z określonej pozycji; pozycja <= 0 -> początek, >= ostatniego indeksu -> koniec
void tablicaDynamiczna::removeFromPosition(int position) {
    if (isEmpty()) {
        return;
    }

    if (position <= 0) {
        removeFromBegining();
        return;
    }

    if (position >= size_ - 1) {
        removeFromEnd();
        return;
    }

    for (int i = position; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }

    size_--;
}

// wyszukiwanie: zwraca indeks pierwszego wystąpienia lub -1, gdy nie ma elementu
int tablicaDynamiczna::find(int element) const {
    for (int i = 0; i < size_; ++i) {
        if (data[i] == element) {
            return i;
        }
    }

    return -1;
}
