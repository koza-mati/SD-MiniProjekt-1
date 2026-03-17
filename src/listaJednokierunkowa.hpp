#include <iostream>
#ifndef LISTAJEDNOKIER.HPP
#define LISTAJEDNOKIER.HPP

class Node{
    private:
    int data; // zmienna przechowująca wartość elementu
    Node* next; // wskaźnik na następny element listy

    friend class listaJednokierunkowa;
};

class listaJednokierunkowa{
    private:
        Node* head; // wskaźnik na pierwszy element listy
        Node* tail; // wskaźnik na ostatni element listy
    public:
        listaJednokierunkowa(); // konstruktor
        ~listaJednokierunkowa(); // destruktor
        bool isEmpty() const; // sprawdza czy lista jest pusta
        void addToFront(const int& element); // dodaje element na początek listy
        void addAtEnd(const int& element); // dodaje element na koniec listy
        void removeFromBegining(); // usuwa element z początku listy
        void removeFromEnd(); // usuwa element z końca listy
        void addAtPosition(const int& element, int position); // dodaje element na określoną pozycję
        void removeFromPosition(int position); // usuwa element z określonej pozycji
        bool isInList(const int& element) const; // sprawdza czy element znajduje się w liście
};

#endif // LISTAJEDNOKIER.HPP