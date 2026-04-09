#pragma once
#include <iostream>
#include <fstream>
#include <string>

/**
 * Klasa DynamicArray implementuje tablicę dynamiczną z automatycznym rozszerzaniem.
 * Wszystkie operacje są implementowane ręcznie bez użycia STL.
 * Złożoności czasowe:
 * - addAtEnd: O(1) amortized (ze wzrostem bufora)
 * - removeFromEnd: O(1)
 * - addToFront/removeFromBeginning: O(n) (przesunięcie elementów)
 * - addAtPosition/removeFromPosition: O(n) średnio
 * - find: O(n)
 */
class DynamicArray {
private:
    int* data;       // wskaźnik na bufor z elementami
    int size;        // aktualna liczba elementów w tablicy
    int capacity;    // pojemność bufora (rozmiar zaalokowanej tablicy)

    void grow();     // zwiększenie pojemności dwukrotnie, gdy brak miejsca - O(n)

public:
    DynamicArray();               // konstruktor - O(1)
    ~DynamicArray();              // destruktor - O(1)

    bool isEmpty() const;              // czy tablica pusta - O(1)
    int getSize() const;               // liczba elementów - O(1)
    int getAt(int index) const;        // dostęp do elementu - O(1)

    void addToFront(int element);      // dodaj na początek - O(n)
    void addAtEnd(int element);        // dodaj na koniec - O(1) amortized
    void addAtPosition(int element, int position); // dodaj na wybrane miejsce - O(n)

    void removeFromBeginning();         // usuń z początku - O(n)
    void removeFromEnd();              // usuń z końca - O(1)
    void removeFromPosition(int position); // usuń z wybranej pozycji - O(n)

    int find(int element) const;      // wyszukiwanie indeksu elementu - O(n)

    void loadFromFile(const std::string& filename); // wczytanie z pliku CSV - O(n)
    void generateRandom(int size);    // generowanie losowej struktury - O(n)
    void saveToCSV(const std::string& filename) const; // zapis do pliku CSV - O(n)
};
