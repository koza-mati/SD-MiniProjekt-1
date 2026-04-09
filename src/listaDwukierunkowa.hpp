#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <fstream>
#include <string>

class DNode {
public:
    int value; // liczba wstawiana do listy
    DNode* prev; // poprzedni element
    DNode* next; // następny element

    DNode(int val); // konstruktor DNode'a
};

/**
 * Klasa DoublyLinkedList implementuje listę dwukierunkową.
 * Wszystkie operacje są implementowane ręcznie bez użycia STL.
 * Złożoności czasowe:
 * - addFront/removeFront: O(1)
 * - addBack/removeBack: O(1)
 * - insertAt/removeAt: O(n) średnio (trzeba znaleźć pozycję)
 * - find: O(n)
 */
class DoublyLinkedList {
private:
    DNode* head; // głowa listy
    DNode* tail; // ogon listy

    // Przejście do węzła o danym indeksie
    // Zwraca wskaźnik do węzła lub nullptr, jeśli poza zakresem
    DNode* nodeAt(int index);

public:
    DoublyLinkedList(); // konstruktor - O(1)
    ~DoublyLinkedList(); // destruktor - O(n)

    // dodawanie elementu na początek listy - O(1)
    void addFront(int value);

    // usuwanie elementu na początku listy - O(1)
    void removeFront();

    // dodawanie elementu na końcu listy - O(1)
    void addBack(int value);

    // usuwanie elementu na końcu listy - O(1)
    void removeBack();

    // dodawanie elementu w "losowym" miejscu listy pod zadanym indeksem - O(n)
    // Jeśli index <= 0 -> wstaw na początek.
    // Jeśli index >= aktualna długość -> wstaw na koniec.
    void insertAt(int index, int value);

    // usuwanie elementu w "losowym" miejscu listy pod zadanym indeksem - O(n)
    // Jeżeli index poza zakresem, nic nie robi.
    void removeAt(int index);

    // sprawdza czy lista jest pusta - O(1)
    bool isEmpty() const;

    // wyszukiwanie, które zwraca indeks pierwszego wystąpienia wartości lub -1, jeśli brak - O(n)
    int find(int value);

    void loadFromFile(const std::string& filename); // wczytanie z pliku CSV - O(n)
    void generateRandom(int size);    // generowanie losowej struktury - O(n)
    void saveToCSV(const std::string& filename) const; // zapis do pliku CSV - O(n)
};

#endif // DOUBLY_LINKED_LIST_HPP