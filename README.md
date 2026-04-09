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

- W menu głównym znajduje się już pozycja listy dwukierunkowej. Implementacja listy dwukierunkowej jest dostępna w plikach `src/listaDwukierunkowa.cpp` i `src/listaDwukierunkowa.hpp`.

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

Program zawiera automatyczne testy wydajnościowe, dostępne w menu głównym pod opcją "Badania wydajnościowe". Wyniki są zapisywane do plików CSV i mogą być wykorzystane do porównywania wydajności struktur danych.

### Jak uruchomić testy

1. W folderze głównym projektu skompiluj aplikację z plikiem źródłowym `src/main.cpp` i pozostałymi modułami:

```bat
g++ -std=c++17 -Wall -Wextra -o benchmark src\main.cpp src\menu.cpp src\tablica_dynamiczna.cpp src\listaJednokierunkowa.cpp src\listaDwukierunkowa.cpp
```

2. Uruchom testy bezpośrednio:

```bat
src\benchmark.exe --benchmarks
```

3. Alternatywnie uruchom program normalnie i wybierz opcję `4. Badania wydajnościowe` w menu głównym.

4. Po zakończeniu testów wyniki pojawią się w katalogu głównym projektu w plikach:
- `benchmark_tablica_dynamiczna.csv`
- `benchmark_lista_jednokierunkowa.csv`
- `benchmark_lista_dwukierunkowa.csv`

> Plik `input.txt` nie jest wymagany do uruchamiania testów i został wyłączony z repozytorium przez `.gitignore`.

### Jak zostały przeprowadzone testy

- Dla każdej struktury danych i każdego rozmiaru budowana jest najpierw struktura zawierająca losowe wartości.
- Testowane rozmiary danych to: 5000, 8000, 10000, 16000, 20000, 40000, 60000 i 100000 elementów.
- Dla każdej konfiguracji wykonywane jest stałe, powtarzalne zadanie operacji.
- Każdy pomiar jest powtarzany kilka razy (`attempts = 3`), aby zredukować wpływ fluktuacji czasu i zamrożenia systemu.
- Czas każdego zestawu operacji mierzony jest przy użyciu `std::chrono::high_resolution_clock`.
- W plikach CSV zapisywany jest średni czas wykonania operacji w nanosekundach, obliczony jako suma czasów podzielona przez liczbę prób.

### Testowane operacje
- **addAtEnd** / **addBack** – wstawienie na koniec
- **addToFront** / **addFront** – wstawienie na początek
- **addAtPosition** / **insertAt** – wstawienie w losowej pozycji
- **listSearch** / **find** – wyszukiwanie elementu
- **removeFromEnd** / **removeBack** – usunięcie z końca
- **removeFromBeginning** / **removeFront** – usunięcie z początku
- **removeFromPosition** / **removeAt** – usunięcie z losowej pozycji

### Format plików CSV
```
Operation,Size,AverageTime_ns
addAtEnd,5000,1200000
addToFront,5000,34000000
...
```

Pliki te można wykorzystać do tworzenia wykresów porównawczych wydajności struktur danych w narzędziach takich jak Excel, Google Sheets, Python (matplotlib), R czy innych narzędziach do analizy danych.
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