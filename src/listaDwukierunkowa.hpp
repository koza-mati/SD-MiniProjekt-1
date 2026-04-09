#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <fstream>
#include <string>

class DNode {
public:
    int value; // liczba wstawiana do listy
    DNode* prev; // poprzedni element
    DNode* next; // nastepny element

    DNode(int val); // konstruktor DNode'a
};

class DoublyLinkedList {
private:
    DNode* head; // glowa listy
    DNode* tail;

    // Przejście do węzła o danym indeksie
    // Zwraca wskaźnik do węzła lub nullptr, jeśli poza zakresem
    DNode* nodeAt(int index);

public:
    DoublyLinkedList(); // konstruktor
    ~DoublyLinkedList();

    // dodawanie elementu na początek listy
    void addFront(int value);

    // usuwanie elementu na początku listy
    void removeFront();

    // dodawanie elementu na końcu listy
    void addBack(int value);

    // usuwanie elementu na końcu listy
    void removeBack();

    // dodawanie elementu w "losowym" miejscu listy pod zadanym indeksem
    // Jeśli index <= 0 -> wstaw na początek.
    // Jeśli index >= aktualna długość -> wstaw na koniec.
    void insertAt(int index, int value);

    // usuwanie elementu w "losowym" miejscu listy pod zadanym indeksem
    // Jeżeli index poza zakresem, nic nie robi.
    void removeAt(int index);

    // sprawdza czy lista jest pusta
    bool isEmpty() const;

    // wyszukiwanie, które zwraca indeks pierwszego wystąpienia wartości lub -1, jeśli brak.
    int find(int value);

    void saveToCSV(const std::string& filename) const;
};

#endif // DOUBLY_LINKED_LIST_HPP