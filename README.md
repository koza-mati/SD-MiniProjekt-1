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

W konsoli pojawi się menu - wybierasz numer opcji i zatwierdzasz Enter.

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

- W menu głównym jest pozycja listy dwukierunkowej - na razie to tylko komunikat tekstowy; osobnych plików `lista_dwukierunkowa.*` jeszcze nie ma.

---

## 5. Funkcjonalność CSV

Wszystkie trzy struktury danych (tablica dynamiczna, lista jednokierunkowa i lista dwukierunkowa) automatycznie zapisują swoją zawartość do pliku CSV po każdej operacji modyfikującej dane (dodawanie/usuwanie).

Domyślne pliki CSV:
- `tablica_dynamiczna.csv`
- `lista_jednokierunkowa.csv`
- `lista_dwukierunkowa.csv`

Format danych:
```
Index,Value
0,12345
1,67890
...
```

Pliki te są gotowe do analizy i tworzenia wykresów bez konieczności korzystania z dodatkowej opcji w menu.

---

## 6. Badania wydajnościowe

Program zawiera automatyczne testy wydajnościowe, dostępne w menu głównym pod opcją "Badania wydajnościowe". Testy mierzą czas wykonania podstawowych operacji na trzech strukturach danych dla różnych rozmiarów danych, a wyniki są uśredniane z wielokrotnych pomiarów dla każdej konfiguracji.

### Rozmiary danych:
- 5000
- 8000
- 10000
- 16000
- 20000
- 40000
- 60000
- 100000

### Testowane operacje:
- **addAtEnd** / **addBack**: dodawanie na koniec
- **addToFront** / **addFront**: dodawanie na początek
- **find** / **listSearch**: wyszukiwanie elementu
- **removeFromEnd** / **removeBack**: usuwanie z końca
- **removeFromBeginning** / **removeFront**: usuwanie z początku

### Pliki wyjściowe:
- `benchmark_tablica_dynamiczna.csv` - wyniki dla tablicy dynamicznej
- `benchmark_lista_jednokierunkowa.csv` - wyniki dla listy jednokierunkowej
- `benchmark_lista_dwukierunkowa.csv` - wyniki dla listy dwukierunkowej

### Format plików CSV:
```
Operation,Size,AverageTime_ns
addAtEnd,5000,1200000
addToFront,5000,34000000
...
```

Pliki te mogą być wykorzystane do tworzenia wykresów porównawczych wydajności struktur danych w narzędziach takich jak Excel, Google Sheets, Python (matplotlib), R czy innych programach do analizy danych.

### Skrypt do wizualizacji (Python):
W katalogu głównym projektu znajduje się skrypt `plot_benchmarks.py`, który automatycznie tworzy wykresy porównawcze na podstawie wygenerowanych plików CSV.

**Wymagania:**
```bash
pip install pandas matplotlib seaborn
```

**Uruchomienie:**
```bash
python plot_benchmarks.py
```

Skrypt tworzy:
- Wykresy porównawcze obu struktur danych
- Indywidualne wykresy dla każdej struktury
- Statystyki wydajności w konsoli
- Pliki PNG z wykresami