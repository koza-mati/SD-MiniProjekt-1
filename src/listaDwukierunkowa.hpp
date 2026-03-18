#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class Node {
public:
    int value; // liczba wstawiana do listy
    Node* prev; // poprzedni element
    Node* next; // nastepny element

    Node(int val); // konstruktor Node'a
};

class DoublyLinkedList {
private:
    Node* head; // glowa listy
    Node* tail;

    // Przejście do węzła o danym indeksie
    // Zwraca wskaźnik do węzła lub nullptr, jeśli poza zakresem
    Node* nodeAt(int index);

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

    // wyszukiwanie, które zwraca indeks pierwszego wystąpienia wartości lub -1, jeśli brak.
    int find(int value);
};

#endif // DOUBLY_LINKED_LIST_HPP