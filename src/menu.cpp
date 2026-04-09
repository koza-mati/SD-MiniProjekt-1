#include <iostream>
#include <windows.h>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "menu.hpp"
#include "tablica_dynamiczna.hpp"
#include "listaJednokierunkowa.hpp"
#include "listaDwukierunkowa.hpp"

static unsigned int benchmarkSeed(int size, int attempt) {
    return 123456u + static_cast<unsigned int>(size) * 7919u + static_cast<unsigned int>(attempt) * 131u;
}

static std::vector<int> generateBenchmarkData(int size, int operations, int warmupOps, unsigned int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1, 100000000);
    std::vector<int> data;
    data.reserve(size + operations + warmupOps);
    for (int i = 0; i < size + operations + warmupOps; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

void menuTablicaDynamiczna() {
    DynamicArray tablica;
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
        std::cout << "9. Zbuduj z pliku" << std::endl;
        std::cout << "10. Utworz losowo" << std::endl;
        std::cout << "11. Wstecz do menu glownego" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> element;
            tablica.addToFront(element);
            tablica.saveToCSV("tablica_dynamiczna.csv");
            std::cout << "Element dodany na poczatek" << std::endl;
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> element;
            tablica.addAtEnd(element);
            tablica.saveToCSV("tablica_dynamiczna.csv");
            std::cout << "Element dodany na koniec" << std::endl;
            break;
        case 3:
            std::cout << "Podaj element: ";
            std::cin >> element;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            tablica.addAtPosition(element, position);
            tablica.saveToCSV("tablica_dynamiczna.csv");
            std::cout << "Element dodany na pozycje " << position << std::endl;
            break;
        case 4:
            if (!tablica.isEmpty()) {
                tablica.removeFromBeginning();
                tablica.saveToCSV("tablica_dynamiczna.csv");
                std::cout << "Element usuniety z poczatku" << std::endl;
            } else {
                std::cout << "Tablica jest pusta!" << std::endl;
            }
            break;
        case 5:
            if (!tablica.isEmpty()) {
                tablica.removeFromEnd();
                tablica.saveToCSV("tablica_dynamiczna.csv");
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
                tablica.saveToCSV("tablica_dynamiczna.csv");
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
            {
                std::string filename;
                std::cout << "Podaj nazwe pliku CSV: ";
                std::cin >> filename;
                tablica.loadFromFile(filename);
            }
            break;
        case 10:
            {
                int size;
                std::cout << "Podaj rozmiar struktury: ";
                std::cin >> size;
                tablica.generateRandom(size);
            }
            break;
        case 11:
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
        std::cout << "9. Zbuduj z pliku" << std::endl;
        std::cout << "10. Utworz losowo" << std::endl;
        std::cout << "11. Wstecz do menu glownego" << std::endl;
        std::cout << "=======================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addToFront(element);
            lista.saveToCSV("lista_jednokierunkowa.csv");
            std::cout << "Element dodany na poczatek" << std::endl;
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addAtEnd(element);
            lista.saveToCSV("lista_jednokierunkowa.csv");
            std::cout << "Element dodany na koniec" << std::endl;
            break;
        case 3:
            std::cout << "Podaj element: ";
            std::cin >> element;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            lista.addAtPosition(element, position);
            lista.saveToCSV("lista_jednokierunkowa.csv");
            std::cout << "Element dodany na pozycje " << position << std::endl;
            break;
        case 4:
            if (!lista.isEmpty()) {
                lista.removeFromBegining();
                lista.saveToCSV("lista_jednokierunkowa.csv");
                std::cout << "Element usuniety z poczatku" << std::endl;
            } else {
                std::cout << "Lista jest pusta!" << std::endl;
            }
            break;
        case 5:
            if (!lista.isEmpty()) {
                lista.removeFromEnd();
                lista.saveToCSV("lista_jednokierunkowa.csv");
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
                lista.saveToCSV("lista_jednokierunkowa.csv");
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
            {
                std::string filename;
                std::cout << "Podaj nazwe pliku CSV: ";
                std::cin >> filename;
                lista.loadFromFile(filename);
            }
            break;
        case 10:
            {
                int size;
                std::cout << "Podaj rozmiar struktury: ";
                std::cin >> size;
                lista.generateRandom(size);
            }
            break;
        case 11:
            return;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }
}

void menuListaDwukierunkowa() {
    DoublyLinkedList lista;
    int choice, element, position;

    while (true) {
        std::cout << "\n================= LISTA DWUKIERUNKOWA =================" << std::endl;
        std::cout << "1. Dodaj na poczatek" << std::endl;
        std::cout << "2. Dodaj na koniec" << std::endl;
        std::cout << "3. Dodaj na pozycje" << std::endl;
        std::cout << "4. Usun z poczatku" << std::endl;
        std::cout << "5. Usun z konca" << std::endl;
        std::cout << "6. Usun z pozycji" << std::endl;
        std::cout << "7. Wyszukaj element" << std::endl;
        std::cout << "8. Czy lista pusta?" << std::endl;
        std::cout << "9. Zbuduj z pliku" << std::endl;
        std::cout << "10. Utworz losowo" << std::endl;
        std::cout << "11. Wstecz do menu glownego" << std::endl;
        std::cout << "=======================================================" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addFront(element);
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element dodany na poczatek" << std::endl;
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> element;
            lista.addBack(element);
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element dodany na koniec" << std::endl;
            break;
        case 3:
            std::cout << "Podaj element: ";
            std::cin >> element;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            lista.insertAt(position, element);
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element dodany na pozycje " << position << std::endl;
            break;
        case 4:
            lista.removeFront();
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element usuniety z poczatku" << std::endl;
            break;
        case 5:
            lista.removeBack();
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element usuniety z konca" << std::endl;
            break;
        case 6:
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            lista.removeAt(position);
            lista.saveToCSV("lista_dwukierunkowa.csv");
            std::cout << "Element usuniety z pozycji " << position << std::endl;
            break;
        case 7:
            std::cout << "Podaj element do wyszukania: ";
            std::cin >> element;
            {
                int index = lista.find(element);
                if (index != -1) {
                    std::cout << "Element znaleziony na pozycji: " << index << std::endl;
                } else {
                    std::cout << "Element nie znaleziony" << std::endl;
                }
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
            {
                std::string filename;
                std::cout << "Podaj nazwe pliku CSV: ";
                std::cin >> filename;
                lista.loadFromFile(filename);
            }
            break;
        case 10:
            {
                int size;
                std::cout << "Podaj rozmiar struktury: ";
                std::cin >> size;
                lista.generateRandom(size);
            }
            break;
        case 11:
            return;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }
}

void menuGlowne() {
    int choice;

    while (true) {
        std::cout << "\n==================== MENU GLOWNE ====================" << std::endl;
        std::cout << "1. Tablica dynamiczna" << std::endl;
        std::cout << "2. Lista jednokierunkowa" << std::endl;
        std::cout << "3. Lista dwukierunkowa" << std::endl;
        std::cout << "4. Badania wydajnosciowe" << std::endl;
        std::cout << "5. Wyjscie" << std::endl;
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
            menuListaDwukierunkowa();
            break;
        case 4:
            runBenchmarks();
            break;
        case 5:
            std::cout << "================= \n Zakonczenie programu \n================= " << std::endl;
            return;
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
        }
    }
}

// Funkcje do badań wydajnościowych
void runBenchmarks() {
    std::cout << "\n================= BADANIA WYDAJNOSCIOWE =================" << std::endl;
    std::cout << "Uruchamianie testow wydajnosciowych..." << std::endl;
    std::cout << "Wyniki zostana zapisane do plikow CSV." << std::endl;
    std::cout << "Pomiar jest wykonywany wielokrotnie dla kazdego rozmiaru i uśredniany." << std::endl;
    std::cout << "To moze zajac kilka minut..." << std::endl;
    std::cout << "=========================================================" << std::endl;

    benchmarkDynamicArray("benchmark_tablica_dynamiczna.csv");
    benchmarkListaJednokierunkowa("benchmark_lista_jednokierunkowa.csv");
    benchmarkListaDwukierunkowa("benchmark_lista_dwukierunkowa.csv");

    std::cout << "\nBadania zakonczone! Pliki wynikowe:" << std::endl;
    std::cout << "- benchmark_tablica_dynamiczna.csv" << std::endl;
    std::cout << "- benchmark_lista_jednokierunkowa.csv" << std::endl;
    std::cout << "- benchmark_lista_dwukierunkowa.csv" << std::endl;
    std::cout << "Mozesz teraz uzyc tych plikow do tworzenia wykresow." << std::endl;
}

void benchmarkDynamicArray(const std::string& resultsFile) {
    std::ofstream file(resultsFile);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku wynikowego: " << resultsFile << std::endl;
        return;
    }

    file << "Operation,Size,AverageTime_ns\n";
    std::vector<int> sizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int attempts = 5;
    const int operations = 1000;
    const int warmupOps = 100;

    for (int size : sizes) {
        std::cout << "Testowanie tablicy dynamicznej, rozmiar: " << size << std::endl;

        long long sumAddAtEnd = 0;
        long long sumAddToFront = 0;
        long long sumAddAtPosition = 0;
        long long sumFind = 0;
        long long sumRemoveFromEnd = 0;
        long long sumRemoveFromBeginning = 0;
        long long sumRemoveFromPosition = 0;

        for (int attempt = 0; attempt < attempts; ++attempt) {
            auto testData = generateBenchmarkData(size, operations, warmupOps, benchmarkSeed(size, attempt));
            std::mt19937 rng(benchmarkSeed(size, attempt) + 1);

            {
                DynamicArray arr;
                for (int i = 0; i < size; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    arr.addAtEnd(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    arr.addAtEnd(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddAtEnd += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    arr.addToFront(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    arr.addToFront(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddToFront += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    arr.find(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    arr.find(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumFind += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    int pos = std::uniform_int_distribution<>(0, arr.getSize())(rng);
                    arr.addAtPosition(testData[size + (i % operations)], pos);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, arr.getSize())(rng);
                    arr.addAtPosition(testData[size + warmupOps + i], pos);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddAtPosition += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size + operations; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    arr.removeFromEnd();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromEnd += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size + operations; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    arr.removeFromBeginning();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromBeginning += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DynamicArray arr;
                for (int i = 0; i < size + operations; ++i) {
                    arr.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, arr.getSize() - 1)(rng);
                    arr.removeFromPosition(pos);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromPosition += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }
        }

        file << "addAtEnd," << size << "," << (sumAddAtEnd / attempts) << "\n";
        file << "addToFront," << size << "," << (sumAddToFront / attempts) << "\n";
        file << "addAtPosition," << size << "," << (sumAddAtPosition / attempts) << "\n";
        file << "find," << size << "," << (sumFind / attempts) << "\n";
        file << "removeFromEnd," << size << "," << (sumRemoveFromEnd / attempts) << "\n";
        file << "removeFromBeginning," << size << "," << (sumRemoveFromBeginning / attempts) << "\n";
        file << "removeFromPosition," << size << "," << (sumRemoveFromPosition / attempts) << "\n";
    }

    file.close();
}

void benchmarkListaJednokierunkowa(const std::string& resultsFile) {
    std::ofstream file(resultsFile);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku wynikowego: " << resultsFile << std::endl;
        return;
    }

    file << "Operation,Size,AverageTime_ns\n";
    std::vector<int> sizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int attempts = 5;
    const int operations = 1000;
    const int warmupOps = 100;

    for (int size : sizes) {
        std::cout << "Testowanie listy jednokierunkowej, rozmiar: " << size << std::endl;

        long long sumAddAtEnd = 0;
        long long sumAddToFront = 0;
        long long sumAddAtPosition = 0;
        long long sumFind = 0;
        long long sumRemoveFromEnd = 0;
        long long sumRemoveFromBeginning = 0;
        long long sumRemoveFromPosition = 0;

        for (int attempt = 0; attempt < attempts; ++attempt) {
            auto testData = generateBenchmarkData(size, operations, warmupOps, benchmarkSeed(size, attempt));
            std::mt19937 rng(benchmarkSeed(size, attempt) + 1);

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.addAtEnd(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.addAtEnd(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddAtEnd += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.addToFront(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.addToFront(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddToFront += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size)(rng);
                    lista.addAtPosition(testData[size + (i % operations)], pos);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size)(rng);
                    lista.addAtPosition(testData[size + warmupOps + i], pos);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddAtPosition += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.listSearch(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.listSearch(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumFind += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.removeFromEnd();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromEnd += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.removeFromBegining();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromBeginning += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                listaJednokierunkowa lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addAtEnd(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size - 1)(rng);
                    lista.removeFromPosition(pos);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFromPosition += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }
        }

        file << "addAtEnd," << size << "," << (sumAddAtEnd / attempts) << "\n";
        file << "addToFront," << size << "," << (sumAddToFront / attempts) << "\n";
        file << "addAtPosition," << size << "," << (sumAddAtPosition / attempts) << "\n";
        file << "listSearch," << size << "," << (sumFind / attempts) << "\n";
        file << "removeFromEnd," << size << "," << (sumRemoveFromEnd / attempts) << "\n";
        file << "removeFromBeginning," << size << "," << (sumRemoveFromBeginning / attempts) << "\n";
        file << "removeFromPosition," << size << "," << (sumRemoveFromPosition / attempts) << "\n";
    }

    file.close();
}

void benchmarkListaDwukierunkowa(const std::string& resultsFile) {
    std::ofstream file(resultsFile);
    if (!file.is_open()) {
        std::cerr << "Blad otwarcia pliku wynikowego: " << resultsFile << std::endl;
        return;
    }

    file << "Operation,Size,AverageTime_ns\n";
    std::vector<int> sizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int attempts = 5;
    const int operations = 1000;
    const int warmupOps = 100;

    for (int size : sizes) {
        std::cout << "Testowanie listy dwukierunkowej, rozmiar: " << size << std::endl;

        long long sumAddBack = 0;
        long long sumAddFront = 0;
        long long sumInsertAt = 0;
        long long sumFind = 0;
        long long sumRemoveBack = 0;
        long long sumRemoveFront = 0;
        long long sumRemoveAt = 0;

        for (int attempt = 0; attempt < attempts; ++attempt) {
            auto testData = generateBenchmarkData(size, operations, warmupOps, benchmarkSeed(size, attempt));
            std::mt19937 rng(benchmarkSeed(size, attempt) + 1);

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size; ++i) {
                    lista.addBack(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.addBack(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.addBack(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddBack += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size; ++i) {
                    lista.addBack(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.addFront(testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.addFront(testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumAddFront += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size; ++i) {
                    lista.addBack(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size)(rng);
                    lista.insertAt(pos, testData[size + (i % operations)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size)(rng);
                    lista.insertAt(pos, testData[size + warmupOps + i]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumInsertAt += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size; ++i) {
                    lista.addBack(testData[i]);
                }
                // Warmup - cache heating
                for (int i = 0; i < warmupOps; ++i) {
                    lista.find(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.find(testData[std::uniform_int_distribution<>(0, size - 1)(rng)]);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumFind += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addBack(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.removeBack();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveBack += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addBack(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    lista.removeFront();
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveFront += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }

            {
                DoublyLinkedList lista;
                for (int i = 0; i < size + operations; ++i) {
                    lista.addBack(testData[i]);
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < operations; ++i) {
                    int pos = std::uniform_int_distribution<>(0, size - 1)(rng);
                    lista.removeAt(pos);
                }
                auto end = std::chrono::high_resolution_clock::now();
                sumRemoveAt += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / operations;
            }
        }

        file << "addBack," << size << "," << (sumAddBack / attempts) << "\n";
        file << "addFront," << size << "," << (sumAddFront / attempts) << "\n";
        file << "insertAt," << size << "," << (sumInsertAt / attempts) << "\n";
        file << "find," << size << "," << (sumFind / attempts) << "\n";
        file << "removeBack," << size << "," << (sumRemoveBack / attempts) << "\n";
        file << "removeFront," << size << "," << (sumRemoveFront / attempts) << "\n";
        file << "removeAt," << size << "," << (sumRemoveAt / attempts) << "\n";
    }

    file.close();
}

