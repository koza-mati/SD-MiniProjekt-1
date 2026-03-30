#include <iostream>
#include <windows.h>
#include "tablica_dynamiczna.hpp"
#include "tablica_dynamiczna.cpp"
#include "listaJednokierunkowa.hpp"
#include "listaJednokierunkowa.cpp"

void menuTablicaDynamiczna() {
    tablicaDynamiczna tablica;
    int choice, element, position;

    while (true) {
        std::cout << "\n================= TABLICA DYNAMICZNA =================" << std::endl;
        std::cout << "1. Dodaj na poczatek" << std::endl;
        std::cout << "2. Dodaj na koniec" << std::endl;
        std::cout << "3. Dodaj na pozycje" << std::endl;
        std::cout << "4. Usun z poczatku" << std::endl;
        std::cout << "5. Usun z konca" << std::endl;
        std::cout << "6. Usun z pozycji" << std::endl;
        std::cout << "7. Wyszukaj element" << std::endl;
        std::cout << "8. Wyswietl rozmiar" << std::endl;
        std::cout << "9. Wstecz do menu glownego" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> element;
            tablica.addToFront(element);
            std::cout << "Element dodany na poczatek" << std::endl;
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> element;
            tablica.addAtEnd(element);
            std::cout << "Element dodany na koniec" << std::endl;
            break;
        case 3:
            std::cout << "Podaj element: ";
            std::cin >> element;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            tablica.addAtPosition(element, position);
            std::cout << "Element dodany na pozycje " << position << std::endl;
            break;
        case 4:
            if (!tablica.isEmpty()) {
                tablica.removeFromBeginning();
                std::cout << "Element usuniety z poczatku" << std::endl;
            } else {
                std::cout << "Tablica jest pusta!" << std::endl;
            }
            break;
        case 5:
            if (!tablica.isEmpty()) {
                tablica.removeFromEnd();
                std::cout << "Element usuniety z konca" << std::endl;
            } else {
                std::cout << "Tablica jest pusta!" << std::endl;
            }
            break;
        case 6:
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            if (!tablica.isEmpty()) {
                tablica.removeFromPosition(position);
                std::cout << "Element usuniety z pozycji " << position << std::endl;
            } else {
                std::cout << "Tablica jest pusta!" << std::endl;
            }
            break;
        case 7:
            std::cout << "Podaj element do wyszukania: ";
            std::cin >> element;
            {
                int index = tablica.find(element);
                if (index != -1) {
                    std::cout << "Element znaleziony na pozycji: " << index << std::endl;
                } else {
                    std::cout << "Element nie znaleziony" << std::endl;
                }
            }
            break;
        case 8:
            std::cout << "Rozmiar tablicy: " << tablica.getSize() << std::endl;
            break;
        case 9:
            return;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }
}

void menuListaJednokierunkowa() {
    listaJednokierunkowa lista;
    int choice, element, position;

    while (true) {
        std::cout << "\n================= LISTA JEDNOKIERUNKOWA =================" << std::endl;
        std::cout << "1. Dodaj na poczatek" << std::endl;
        std::cout << "2. Dodaj na koniec" << std::endl;
        std::cout << "3. Dodaj na pozycje" << std::endl;
        std::cout << "4. Usun z poczatku" << std::endl;
        std::cout << "5. Usun z konca" << std::endl;
        std::cout << "6. Usun z pozycji" << std::endl;
        std::cout << "7. Wyszukaj element" << std::endl;
        std::cout << "8. Czy lista pusta?" << std::endl;
        std::cout << "9. Wstecz do menu glownego" << std::endl;
        std::cout << "=======================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addToFront(element);
            std::cout << "Element dodany na poczatek" << std::endl;
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addAtEnd(element);
            std::cout << "Element dodany na koniec" << std::endl;
            break;
        case 3:
            std::cout << "Podaj element: ";
            std::cin >> element;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            lista.addAtPosition(element, position);
            std::cout << "Element dodany na pozycje " << position << std::endl;
            break;
        case 4:
            if (!lista.isEmpty()) {
                lista.removeFromBegining();
                std::cout << "Element usuniety z poczatku" << std::endl;
            } else {
                std::cout << "Lista jest pusta!" << std::endl;
            }
            break;
        case 5:
            if (!lista.isEmpty()) {
                lista.removeFromEnd();
                std::cout << "Element usuniety z konca" << std::endl;
            } else {
                std::cout << "Lista jest pusta!" << std::endl;
            }
            break;
        case 6:
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            if (!lista.isEmpty()) {
                lista.removeFromPosition(position);
                std::cout << "Element usuniety z pozycji " << position << std::endl;
            } else {
                std::cout << "Lista jest pusta!" << std::endl;
            }
            break;
        case 7:
            std::cout << "Podaj element do wyszukania: ";
            std::cin >> element;
            if (lista.listSearch(element)) {
                std::cout << "Element znaleziony!" << std::endl;
            } else {
                std::cout << "Element nie znaleziony" << std::endl;
            }
            break;
        case 8:
            if (lista.isEmpty()) {
                std::cout << "Lista jest pusta" << std::endl;
            } else {
                std::cout << "Lista nie jest pusta" << std::endl;
            }
            break;
        case 9:
            return;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        std::cout << "\n==================== MENU GLOWNE ====================" << std::endl;
        std::cout << "1. Tablica dynamiczna" << std::endl;
        std::cout << "2. Lista jednokierunkowa" << std::endl;
        std::cout << "3. Lista dwukierunkowa" << std::endl;
        std::cout << "4. Wyjscie" << std::endl;
        std::cout << "====================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            menuTablicaDynamiczna();
            break;
        case 2:
            menuListaJednokierunkowa();
            break;
        case 3:
            std::cout << "================= \n Lista dwukierunkowa - wkrotce \n================= " << std::endl;
            break;
        case 4:
            std::cout << "================= \n Zakonczenie programu \n================= " << std::endl;
            return 0;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }

    return 0;
}
