#pragma once
#include <iostream>
#include <string>

// menu dla struktur danych (tablica dynamiczna / listy)

void menuTablicaDynamiczna();
void menuListaJednokierunkowa();
void menuListaDwukierunkowa();
void menuGlowne();

// funkcje do badań wydajnościowych
void runBenchmarks();
void benchmarkDynamicArray(const std::string& resultsFile);
void benchmarkListaJednokierunkowa(const std::string& resultsFile);
void benchmarkListaDwukierunkowa(const std::string& resultsFile);

