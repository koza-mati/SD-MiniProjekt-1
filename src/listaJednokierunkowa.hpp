#pragma once
#include <iostream>

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
    void addAtPosition();                 // dodaj losowe miejsce
    void removeFromPosition();             // usuń z losowe miejsce 
    void listSearch();                     // wyszukiawnie elementu w liście
};

#endif // LISTA_JEDNOKIERUNKOWA_HPP