#include <iostream>
#include <windows.h>
#include "listaJednokierunkowa.cpp"

int main() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Tablica dynamiczna" << std::endl;
    std::cout << "2. Lista jednokierunkowa" << std::endl;
    std::cout << "3. Lista dwukierunkowa" << std::endl;
    std::cout << "4. Wyjście" << std::endl;

    int choice;
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;
    system("cls"); // Czyści ekran po dokonaniu wyboru
   



    switch (choice) {
    case 1:
        std::cout << "================= \n Wybrano tablicę dynamiczną \n================= " << std::endl;
        break;
    case 2:
        std::cout << "================= \n Wybrano listę jednokierunkową \n================= " << std::endl;
        break;
    case 3:
        std::cout << "================= \n Wybrano listę dwukierunkową \n================= " << std::endl;
        break;
    case 4:
        std::cout << "================= \n Zakończenie programu \n================= " << std::endl;
        break;
    default:
        std::cout << " Nieprawidłowy wybór :(" << std::endl;   
        break;
    }

    return 0;
}
