#include <iostream>
#include "listaJednokierunkowa.hpp"

listaJednokierunkowa::listaJednokierunkowa() : head(NULL), tail(NULL) {}; // konstruktor inicialzujacy head i tail na NULL

listaJednokierunkowa::~listaJednokierunkowa(){ // destruktor usuwający wszystkie elementy z listy w celu zwolnienia pamięci
    while(!isEmpty()){
        removeFromBegining();
    }
}

// sprwdzamy czu lsita jest pusta, jeżelei tak to zwracamy head = 0
bool listaJednokierunkowa::isEmpty() const{
    return (head == 0); 
}


// dodawanie na początku listy
void listaJednokierunkowa::addToFront(const int& element) {
    Node* newNode = new Node; // dynamicznie alokujemy węzeł 
    newNode -> date = element; // przypisujemy nowy element do wezła
    newNode -> next = head; // ustawiamy następny element na nowy head lsity
    head = newNode; // przypisujemy nowy wezele jako aktualny head'a (w skrócie aktualziujemy head'a)

    if(isEmpty()){ // jeżeli lista była puta tail również przypisujemy do nowego węzła
        tail = newNode;
    }
}


// dodawanie na końcu listy
void listaJednokierunkowa::addAtEnd(const int& element) {
    Node* new_Node = new Node;
    new_Node -> date = element; // przypisujemy nowy element do węzła
    new_Node -> next = nullptr; // ustawaimy tail na nullptr 

    // sprawdzamy czy lista jest pusta
    if(isEmpty()){
        head = new_Node; // jezeli jest pusta ustawaimy head i tail jako wezel
        tail = new_Node;
    }else{ 
        tail -> next = new_Node; // w przeciwynym wypadku do tail przypisujemy next czyli nullptr
        tail = new_Node; // aktualizujemy tail 
    }
}

