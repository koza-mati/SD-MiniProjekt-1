#pragma once
#include <iostream>
#include <fstream>
#include <string>

// Klasyczny include guard (opcjonalnie, jeśli używasz #pragma once, nie jest konieczny)
#ifndef LISTA_JEDNOKIERUNKOWA_HPP
#define LISTA_JEDNOKIERUNKOWA_HPP

class listaJednokierunkowa; // deklaracja wyprzedzająca, by użyć w friend

class Node {
private:
    int data;    // wartość elementu
    Node* next;  // wskaźnik na następny element listy

    friend class listaJednokierunkowa;
};

class listaJednokierunkowa {
private:
    Node* head; // pierwszy element listy
    Node* tail; // ostatni element listy

public:
    listaJednokierunkowa();              // konstruktor
    ~listaJednokierunkowa();             // destruktor

    bool isEmpty() const;                // czy lista pusta
    void addToFront(const int& element); // dodaj na początek
    void addAtEnd(const int& element);   // dodaj na koniec
    void removeFromBegining();           // usuń z początku 
    void removeFromEnd();                // usuń z końca                 
    void addAtPosition(const int& element, int position);                 // dodaj losowe miejsce
    void removeFromPosition(int position);             // usuń z losowe miejsce 
    bool listSearch(const int& element) const;                     // wyszukiawnie elementu w liście

    void saveToCSV(const std::string& filename) const; // zapis do pliku CSV
};

#endif // LISTA_JEDNOKIERUNKOWA_HPP