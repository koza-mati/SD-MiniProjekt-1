#include <iostream>
#include "listaJednokierunkowa.hpp"

// konstruktor inicialzujacy head i tail na nullptr
listaJednokierunkowa::listaJednokierunkowa() : head(nullptr), tail(nullptr) {}

// destruktor usuwający wszystkie elementy z listy w celu zwolnienia pamięci
listaJednokierunkowa::~listaJednokierunkowa() {
    while (!isEmpty()) {
        removeFromBegining();
    }
}

// sprwdzamy czu lsita jest pusta, jeżelei tak to zwracamy head = nullptr
bool listaJednokierunkowa::isEmpty() const {
    return head == nullptr;
}

// dodawanie na początku listy
void listaJednokierunkowa::addToFront(const int& element) {
    const bool wasEmpty = isEmpty();

    // dynamicznie alokujemy węzeł 
    Node* newNode = new Node;
    newNode->data = element;      // przypisujemy nowy element do węzła
    newNode->next = head;         // ustawiamy następny element na aktualny head listy
    head = newNode;               // przypisujemy nowy węzeł jako aktualnego head'a (aktualizujemy head'a)

    if (wasEmpty) {               // jeżeli lista była pusta, tail również przypisujemy do nowego węzła
        tail = newNode;
    }
}

// dodawanie na końcu listy
void listaJednokierunkowa::addAtEnd(const int& element) {
    Node* newNode = new Node;
    newNode->data = element;      // przypisujemy nowy element do węzła
    newNode->next = nullptr;      // ustawiamy next nowego węzła na nullptr (bo będzie ostatni)

    // sprawdzamy czy lista jest pusta
    if (isEmpty()) {
        head = tail = newNode;    // jeżeli jest pusta, ustawiamy head i tail jako nowy węzeł
    } else {
        tail->next = newNode;     // w przeciwnym wypadku do tail przypisujemy next jako nowy węzeł
        tail = newNode;           // aktualizujemy tail 
    }
}

// usuwanie z początku listy
void listaJednokierunkowa::removeFromBegining() {
    if (isEmpty()) return;

    Node* old = head;             // ustawia head na old żeby go później móc usunąć
    head = head->next;            // ustawia head'a na następny element z listy
    delete old;                   // usuwa starego head'a

    if (head == nullptr) {
        // lista stała się pusta -> wyzeruj tail
        tail = nullptr;
    }
}

// usuwanie z końca listy
void listaJednokierunkowa::removeFromEnd() {
    if (isEmpty()) return;

    if (head == tail) {
        // jeżeli lista ma tylko jeden element to czyścimy listę
        delete head;
        head = tail = nullptr;
        return;
    }

    // Znajdduje przedostatni element (ten, którego next wskazuje na tail)
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    // current to przedostatni element, później usuwa tail i aktualizuje wskaźniki
    delete tail;
    tail = current;
    tail->next = nullptr;
}

// (TODO) dodawanie losowego elementu - uzupełnij co dokładnie ma robić ta funkcja
void listaJednokierunkowa::addRandom() {

}