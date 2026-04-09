#include <iostream>
#include <fstream>
#include <string>
#include "listaDwukierunkowa.hpp"

// ===== Node =====
// Ustawiamy wartosci poczatkowe naszej listy dwukierunkowej

DNode::DNode(int val) {
    value = val;
    prev = 0;
    next = 0;
}

// ===== Lista Dwukierunkowa =====

DoublyLinkedList::DoublyLinkedList() { // konstruktor domyslny
    head = 0; // lista nie ma zandych elementow
    tail = 0;
}

DoublyLinkedList::~DoublyLinkedList() { //destruktor
    DNode* cur = head; // zaczynamy od pierwszeg wezla
    while (cur != 0) { // while sa wezly
        DNode* nxt = cur->next; // zapamietujemy adres nastepnego wezla
        delete cur; // usuwamy akutalny wezel z pamieci
        cur = nxt; // przechodzimy do nastepnego
    }
    head = 0; // lista pusta po petli
    tail = 0; // cyscimy wskazniki koncowe
}

DNode* DoublyLinkedList::nodeAt(int index) {
    if (index < 0) return 0; // jesli index jest mniejszy od zera zwraca 0
    DNode* cur = head; // zaczynamy od head'a
    for (int i = 0; cur != 0 && i < index; ++i) { // przechodzimy do nastepnych indexów
        cur = cur->next; // idziemy do przodu
    }
    return cur; // wezele o podnaym indexie, albo nullptr jesli poza zakresem
}

void DoublyLinkedList::addFront(int value) {
    DNode* n = new DNode(value); // dynamiczna alokacja wezla 
    n->prev = 0; // poprzedni element to 0 bo brak poprzednika
    n->next = head; // wskazuje na dotychczasowy head jezeli lista nie bedzie pusta

    if (head != 0) { // jesli lista nie byla pusta
        head->prev = n; // stary pierwszy element wskazuje wstecz na nowy wezel
    } else {
        // lista była pusta
        tail = n;
    }
    head = n; // podmieniamy wskaznik na nowy element n
}

void DoublyLinkedList::removeFront() {
    if (head == 0) return; // sprawdzenie czy lista jest pusta

    DNode* old = head; // zapamieyujemy starego head'a
    head = head->next; // przesuwamy head'a na nastepny element
    if (head != 0) { // jesli lista ma nadal element to prev musi byc wyzerowane
        head->prev = 0;
    } else {
        // lista stała się pusta
        tail = 0;
    }
    delete old; // zwalniamy pamiec
}

void DoublyLinkedList::addBack(int value) {
    DNode* n = new DNode(value); // alokujemy dynamicznie nowy wezel
    n->next = 0; // wstawiamy na koniec wiec next musi byc 0
    n->prev = tail;

    if (tail != 0) { // lista nie byla pusta
        tail->next = n; // ogon wskazuje na next czyli nowy element
    } else {
        // lista była pusta
        head = n; // wstawaimy pierwszy element do listy
    }
    tail = n; // ustawiamy nowy tail
}

void DoublyLinkedList::removeBack() {
    if (tail == 0) return; // sprawdzamy czy lista jest pusta

    DNode* old = tail; // zapamietujemy wsk starego taila
    tail = tail->prev; // przesuwamy taila na poprzedni element
    if (tail != 0) { // lista nie byla pusta
        tail->next = 0; // 
    } else {
        // lista stała się pusta
        head = 0; 
    }
    delete old; // zwalaniamy pamiec
}

void DoublyLinkedList::insertAt(int index, int value) {
    // Wstawienie na początek, gdy index <= 0
    if (index <= 0 || head == 0) {
        addFront(value);
        return;
    }

    // Szukamy węzeła o danym indeksie
    DNode* where = nodeAt(index);

    if (where == 0) {
        // Jeżeli index poza końcem wstawiamy na koniec
        addBack(value);
        return;
    }

    // Wstaw PRZED where
    DNode* n = new DNode(value);
    n->next = where; // nowy wskazuje na przód na where
    n->prev = where->prev; // i wstecz na poprzednika where

    if (where->prev != 0) { // jesli where mial poprzednika to jego next wskazuje na nowy wezel
        where->prev->next = n;
    } else {
        // wstawiamy na początku
        head = n;
    }
    where->prev = n; // ustawaimy poprzednika where
}

// Usuwamy element znajdujący się pod podanym indeksem
void DoublyLinkedList::removeAt(int index) {  
    if (index < 0 || head == 0) return; // Jeżeli indeks ujemny albo lista pusta nic nie zwracamy

    DNode* target = nodeAt(index); // Znajdujemy wskaźnik do węzła na pozycji 'index'
    if (target == 0) return; // Jeżeli jest poza zakresem lub brak takiego węzła, nic nie zwracamy

    if (target->prev != 0) { // Jeżeli węzeł ma poprzednika (nie jest head)
        target->prev->next = target->next; // To omijamy target z lewej, poprzednik ma teraz wskazywać na następnik targetu
    } else { // W przeciwnym razie target jest pierwszym elementem listy
        head = target->next; // Nową głową staje się następnikiem usuwanego węzła
    }

    if (target->next != 0) { // Jeżeli węzeł ma następnika, nie jest tail
        target->next->prev = target->prev; // To omijamy target z prawej, następnik ma teraz wskazywać wstecz na poprzednik targetu
    } else { // W przeciwnym razie target jest ostatnim elementem listy
        tail = target->prev; // Nowym ogonem staje się poprzednik usuwanego węzła
    }

    delete target; // zwalniamy pamięć po usuwanym węźle
}

int DoublyLinkedList::find(int value) { // Zwraca indeks pierwszego węzła o wartości 'value', albo -1 jeśli nie znaleziono
    DNode* cur = head;  // ustawiamy wskaźnik 'cur' na head listy
    int idx = 0; // licznik indeksu bieżącego węzła, pierwszy element ma indeks 0
    while (cur != 0) { // dopóki nie dojdzeimy do końca listy 
        if (cur->value == value) return idx; // jeśli wartość w bieżącym węźle jest równa szukanej, zwróć bieżący indeks
        cur = cur->next; // przejdź do następnego węzła w liście
        idx++; // zwiększ indeks o jeden węzeł dalej
    }
    return -1; // jeśli pętla zakończyła się lub nie znaleziono wartości to zwracamy -1
}

bool DoublyLinkedList::isEmpty() const {
    return head == 0;
}

void DoublyLinkedList::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku: " << filename << std::endl;
        return;
    }

    file << "Index,Value\n";
    DNode* cur = head;
    int idx = 0;
    while (cur != 0) {
        file << idx << "," << cur->value << "\n";
        cur = cur->next;
        idx++;
    }

    file.close();
}