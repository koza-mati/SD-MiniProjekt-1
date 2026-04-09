#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <sstream>
#include "tablica_dynamiczna.hpp"

// Konstruktor: inicjalizuje tablica z poczatkowym rozmiarem
DynamicArray::DynamicArray() {
    size = 0;                   // Na początku struktura jest pusta
    capacity = 1;                // Początkowa pojemność
    data = new int[capacity];   // Dynamiczna alokacja tablicy
}

// destruktor: zwolnienie pamieci bufora
DynamicArray::~DynamicArray() {
    delete[] data;
}

// podwajanie pojemności i kopiowanie starych elementów do nowego bufora
void DynamicArray::grow() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];

    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCap;
}

// sprawdzamy czy tablica jest pusta (size == 0)
bool DynamicArray::isEmpty() const {
    return size == 0;
}

// zwracamy aktualna liczbe elementow
int DynamicArray::getSize() const {
    return size;
}

// zwracamy element na określonej pozycji
int DynamicArray::getAt(int index) const {
    return data[index];
}

// dodawanie na początku: ewentualny grow, przesunięcie w prawo, wstawienie na indeks 0
void DynamicArray::addToFront(int element) {
    if (size >= capacity) {
        grow();
    }

    for (int i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }

    data[0] = element;
    size++;
}

// dodawanie na końcu tablicy
void DynamicArray::addAtEnd(int element) {
    if (size >= capacity) {
        grow();
    }

    data[size++] = element;
}

// dodawanie elementu na określoną pozycję (indeks); pozycja <= 0 -> początek, >= rozmiaru -> koniec
void DynamicArray::addAtPosition(int element, int position) {
    if (position <= 0) {
        addToFront(element);
        return;
    }
    if (position >= size) {
        addAtEnd(element);
        return;
    }

    if (size >= capacity) {
        grow();
    }

    for (int i = size; i > position; --i) {
        data[i] = data[i - 1];
    }

    data[position] = element;
    size++;
}

// usuwanie z początku: przesunięcie w lewo o jeden indeks
    void DynamicArray::removeFromBeginning() {
    if (isEmpty()) {
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    size--;
}

// usuwanie ostatniego elementu (zmniejszenie size)
void DynamicArray::removeFromEnd() {
    if (!isEmpty()) {
        size--;
    }
}

// usuwanie elementu z określonej pozycji; pozycja <= 0 -> początek, >= ostatniego indeksu -> koniec
void DynamicArray::removeFromPosition(int position) {
    if (isEmpty()) {
        return;
    }

    if (position <= 0) {
        removeFromBeginning();
        return;
    }

    if (position >= size - 1) {
        removeFromEnd();
        return;
    }

    for (int i = position; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    size--;
}

// wyszukiwanie: zwraca indeks pierwszego wystąpienia lub -1, gdy nie ma elementu
int DynamicArray::find(int element) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return i;
        }
    }

    return -1;
}

// zapis zawartości tablicy do pliku CSV
void DynamicArray::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku: " << filename << std::endl;
        return;
    }

    // Nagłówek CSV
    file << "Index,Value\n";

    // Zapisanie wszystkich elementów
    for (int i = 0; i < size; ++i) {
        file << i << "," << data[i] << "\n";
    }

    file.close();
    std::cout << "Tablica zostala zapisana do pliku: " << filename << std::endl;
}

// wczytanie zawartości z pliku CSV
void DynamicArray::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku: " << filename << std::endl;
        return;
    }

    // Wyczyszczenie obecnych danych
    size = 0;

    std::string line;
    std::getline(file, line); // Pominiecie nagłówka

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string indexStr, valueStr;
        std::getline(ss, indexStr, ',');
        std::getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);
        addAtEnd(value);
    }

    file.close();
    std::cout << "Tablica zostala wczytana z pliku: " << filename << std::endl;
}

// generowanie losowej struktury o podanym rozmiarze
void DynamicArray::generateRandom(int size) {
    // Wyczyszczenie obecnych danych
    this->size = 0;

    std::mt19937 gen(12345); // Stały seed dla powtarzalności
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < size; ++i) {
        int value = dis(gen);
        addAtEnd(value);
    }
    std::cout << "Wygenerowano losowa tablice o rozmiarze: " << size << std::endl;
}
