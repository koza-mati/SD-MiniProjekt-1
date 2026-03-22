#pragma once
#include <iostream>


class tablicaDynamiczna {
private:
    int* data;       // wskaźnik na bufor z elementami
    int size_;       // aktualna liczba elementów w tablicy
    int capacity_;   // pojemność bufora (rozmiar zaalokowanej tablicy)

    void grow();     // zwiększenie pojemności dwukrotnie, gdy brak miejsca

public:
    explicit tablicaDynamiczna(int initialCapacity = 4); // konstruktor
    ~tablicaDynamiczna();                                // destruktor

    bool isEmpty() const;              // czy tablica pusta
    int getSize() const;               // liczba elementów
    int getAt(int index) const; 

    void addToFront(int element);      // dodaj na początek
    void addAtEnd(int element);        // dodaj na koniec
    void addAtPosition(int element, int position); // dodaj na wybrane miejsce

    void removeFromBegining();         // usuń z początku
    void removeFromEnd();              // usuń z końca
    void removeFromPosition(int position); // usuń z wybranej pozycji

    int find(int element) const;      // wyszukiwanie indeksu elementu (-1 gdy brak)
};
