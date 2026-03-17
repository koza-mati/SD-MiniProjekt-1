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

// dodawanie elementu na określoną pozycję
void listaJednokierunkowa::addAtPosition(const int& element, int position) {

    // Jeżeli lista jest pusta to dodajemy pierwszy element
    if(isEmpty() || position <= 0){
        addToFront(element);
        return;
    }
    // Szukamy miejsca do wstawienia: węzła "poprzedniego" względem pozycji
    int idx = 0;
    Node* prev = head;
    while (prev->next != nullptr && idx < position - 1) {
        prev = prev->next;
        ++idx;
    }
    // Jeśli doszliśmy do końca zanim osiągnęliśmy (position - 1), to wstawiamy na koniec
    if (prev->next == nullptr && idx < position - 1) {
        addAtEnd(element);
        return;
    }
    // Wstawienie nowego węzła "po prev"
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = prev->next; //nullptr, gdy wstawiamy na końcu
    prev->next = newNode;
    // Jeżeli wstawiliśmy na sam koniec (prev był dawnym tail), to aktualizujemy tail
    if (newNode->next == nullptr) {
        tail = newNode;
    }
}

// usuwanie elementu z okreslonej pozycji
void listaJednokierunkowa::removeFromPosition(int position) {
    if (isEmpty()) return;

    if (position <= 0) {
        removeFromBegining();
        return;
    }

    // Szukamy węzła "poprzedniego" względem pozycji (ten, którego next będziemy usuwać)
    int idx = 0;
    Node* prev = head;

    // prev->next != nullptr, bo chcemy mieć istniejący element do usunięcia
    while (prev->next != nullptr && idx < position - 1) {
        prev = prev->next;
        ++idx;
    }

    // Jeśli prev->next to nullptr, to oznacza, że position wskazuje poza końcem
    // -> usuwamy ostatni element
    if (prev->next == nullptr) {
        removeFromEnd();
        return;
    }

    // Usuwamy element na pozycji
    Node* toDelete = prev->next;
    prev->next = toDelete->next;

    // Jeśli usuwaliśmy ostatni element, aktualizujemy tail
    if (prev->next == nullptr) {
        tail = prev;
    }

    delete toDelete;
}

// wyszukiwanie elementu w liście, zwraca true, jeśli element występuje
bool listaJednokierunkowa::listSearch(const int& element) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}


