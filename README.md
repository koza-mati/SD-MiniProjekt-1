### Struktury Danych - Miniprojekt 1

## 1. Wymagania

- Kompilator: **GCC** (MinGW) z obsługą **C++17** (np. `g++`)
- System operacyjny: **Windows** (menu używa `system("cls")`)

## 2. Kompilacja i uruchomienie

W terminalu, w katalogu głównym projektu:

1. Zbuduj program:

```bat
g++ -std=c++17 -Wall -Wextra -o main.exe src\main.cpp src\menu.cpp src\tablica_dynamiczna.cpp src\listaJednokierunkowa.cpp
```

2. Uruchom:

```bat
main.exe
```

W konsoli pojawi się menu — wybierasz numer opcji i zatwierdzasz Enter.

---

## 3. Struktura projektu

```text
SD-MiniProjekt-1/
├── README.md
└── src/
    ├── main.cpp
    ├── menu.cpp
    ├── menu.hpp
    ├── tablica_dynamiczna.cpp
    ├── tablica_dynamiczna.hpp
    ├── listaJednokierunkowa.cpp
    └── listaJednokierunkowa.hpp
```

---

## 4. Szczegółowy opis plików i modułów

### A. Punkt wejścia i warstwa menu

**`main.cpp`**  
Jedyny plik z funkcją `main`. Uruchamia pętlę menu głównego (`menuGlowne()`).

**`menu.hpp` / `menu.cpp`**  
Deklaracje i implementacja obsługi konsoli: menu główne (wybór struktury danych) oraz osobne podmenu dla tablicy dynamicznej i listy jednokierunkowej (dodawanie, usuwanie, wyszukiwanie itd.). Wykorzystuje `system("cls")` do czyszczenia ekranu po wyborze opcji.

---

### B. Struktury danych (moduły implementacyjne)

**DynamicArray** (tablica dynamiczna, odpowiednik *ArrayList*)  
Pliki: `tablica_dynamiczna.hpp` / `tablica_dynamiczna.cpp`  

Implementacja tablicy opartej o jeden ciągły bufor w pamięci (`data`). Klasa trzyma m.in. rozmiar logiczny i pojemność; przy braku miejsca wywoływane jest podwojenie bufora (`grow`) z przepisaniem elementów. Zawiera operacje wstawiania i usuwania na początku, końcu i pod zadanym indeksem oraz wyszukiwanie (`find`).

**listaJednokierunkowa**  
Pliki: `listaJednokierunkowa.hpp` / `listaJednokierunkowa.cpp`  

Implementacja listy jednokierunkowej. W nagłówku zdefiniowany jest typ `Node` (pole `data`, wskaźnik `next`). Lista jest obsługiwana przez wskaźniki `head` i `tail`, co upraszcza dodawanie na obu końcach. Operacje obejmują m.in. dodawanie/usuwanie na początku, końcu i pod pozycją oraz wyszukiwanie (`listSearch`).

---

**Uwagi**

- W menu głównym jest pozycja listy dwukierunkowej — na razie to tylko komunikat tekstowy; osobnych plików `lista_dwukierunkowa.*` jeszcze nie ma.