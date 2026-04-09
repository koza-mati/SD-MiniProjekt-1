# Struktury Danych - Miniprojekt 1

**Projekt zawiera implementacje trzech struktur danych (tablica dynamiczna, lista jednokierunkowa, lista dwukierunkowa) z pełnym systemem testowania wydajnościowego oraz interaktywnym menu do zarządzania danymi.**

---

## 1. Wymagania

- **Kompilator**: GCC (MinGW) z obsługą C++17 lub nowszego
- **System operacyjny**: Windows (menu używa `system("cls")` do czyszczenia konsoli)
- **Biblioteki**: Standardowe biblioteki C++17

---

## 2. Szybki start

### Kompilacja

W terminalu, w katalogu głównym projektu:

```batch
g++ -std=c++17 -Wall -Wextra -o main.exe src\main.cpp src\menu.cpp src\tablica_dynamiczna.cpp src\listaJednokierunkowa.cpp src\listaDwukierunkowa.cpp
```

### Uruchomienie

#### Interaktywne menu:
```batch
main.exe
```
Pojawi się menu z opcjami do wyboru. Możesz testować struktury danych ręcznie.

#### Benchmarki wydajności (testy automatyczne):
```batch
main.exe --benchmarks
```
Program uruchomi pełny zestaw testów wydajnościowych dla wszystkich trzech struktur i zapisze wyniki do plików CSV.

---

## 3. Struktura projektu

```
SD-MiniProjekt-1/
├── README.md                              # Niniejszy plik
├── src/
│   ├── main.cpp                          # Punkt wejścia (main), obsługuje --benchmarks
│   ├── menu.hpp, menu.cpp                # Interfejs menu i funkcje benchmarków
│   ├── tablica_dynamiczna.hpp, .cpp      # Implementacja tablicy dynamicznej
│   ├── listaJednokierunkowa.hpp, .cpp    # Implementacja listy jednokierunkowej
│   └── listaDwukierunkowa.hpp, .cpp      # Implementacja listy dwukierunkowej
└── .gitignore                             # Wyklucza pliki .exe i benchmark_*.csv
```

---

## 4. Zawartość projektu

### Główne komponenty

1. **Menu interaktywne** – Pozwala na ręczne testowanie struktur danych z poziomu konsoli
2. **System benchmarków** – Automatyczne testy wydajnościowe z deterministycznym generowaniem danych
3. **Eksport CSV** – Każda operacja modyfikacyjna zapisuje zawartość struktury do pliku CSV
4. **Trzy struktury danych** – Tablicowa, listowa i dwukierunkowa

---

## 5. Szczegółowy opis struktur danych

### 5.1 DynamicArray (Tablica Dynamiczna)

**Plik**: `src/tablica_dynamiczna.hpp / tablica_dynamiczna.cpp`

Implementacja oparta na wektorze z dynamicznym przeszukaniem bufora:
- **Przechowywanie**: Jeden ciągły bufor w pamięci (`data`)
- **Zarządzanie pojemnością**: Automatyczne podwojenie bufora (`grow()`) przy niewystarczającej przestrzeni
- **Rozmiar logiczny vs fizyczny**: Trzyma zarówno bieżący rozmiar (`size`) jak i pojemność (`capacity`)

**Obsługiwane operacje**:
- `addToFront()` – O(n) – przesunięcie wszystkich elementów
- `addAtEnd()` – O(1) amortyzowane – wstawienie na koniec
- `addAtPosition()` – O(n) – przesunięcie części elementów
- `removeFromBeginning()` – O(n) – przesunięcie wszystkich elementów
- `removeFromEnd()` – O(1) – usunięcie z końca
- `removeFromPosition()` – O(n) – przesunięcie części elementów
- `find()` – O(n) – liniowe wyszukiwanie
- `isEmpty()` – O(1)
- `getSize()` – O(1)

### 5.2 listaJednokierunkowa (Singly Linked List)

**Plik**: `src/listaJednokierunkowa.hpp / listaJednokierunkowa.cpp`

Implementacja listy z węzłami zawierającymi wskaźnik na następny element:
- **Węzły**: Zawierają dane i wskaźnik `next`
- **Wskaźniki**: `head` i `tail` do szybkiego dostępu na obu końcach
- **Brak dostępu bezpośredniego**: Trzeba przejść przez węzły aby dotrze do elementu

**Obsługiwane operacje**:
- `addToFront()` – O(1) – wstawianie na początek
- `addAtEnd()` – O(1) – wstawianie na koniec (dzięki `tail`)
- `addAtPosition()` – O(n) – znalezienie pozycji + wstawienie
- `removeFromBegining()` – O(1) – usunięcie pierwszego węzła
- `removeFromEnd()` – O(n) – trzeba znaleźć poprzedni węzeł
- `removeFromPosition()` – O(n) – znalezienie i usunięcie
- `listSearch()` – O(n) – liniowe wyszukiwanie
- `isEmpty()` – O(1)

### 5.3 DoublyLinkedList (Doubly Linked List)

**Plik**: `src/listaDwukierunkowa.hpp / listaDwukierunkowa.cpp`

Lista z węzłami posiadającymi wskaźniki na następny i poprzedni element:
- **Węzły**: Zawierają dane, wskaźnik `next` i wskaźnik `prev`
- **Dwukierunkowy dostęp**: Można przechodzić zarówno do przodu jak i do tyłu
- **Wskaźniki**: `head` i `tail` do szybkiego dostępu z obu końców
- **Lepsza wydajność usuwania**: Szczególnie z końca (O(1) zamiast O(n))

**Obsługiwane operacje**:
- `addFront()` – O(1) – wstawianie na początek
- `addBack()` – O(1) – wstawianie na koniec
- `insertAt()` – O(n) – znalezienie pozycji + wstawienie
- `removeFront()` – O(1) – usunięcie z początku
- `removeBack()` – O(1) – usunięcie z końca
- `removeAt()` – O(n) – znalezienie i usunięcie
- `find()` – O(n) – liniowe wyszukiwanie
- `isEmpty()` – O(1)

---

## 6. Funkcjonalność CSV

Każda struktura danych automatycznie zapisuje swoją zawartość do pliku CSV po każdej operacji modyfikującej (dodawanie/usuwanie).

**Generowane pliki**:
- `tablica_dynamiczna.csv` – Zawartość tablicy dynamicznej
- `lista_jednokierunkowa.csv` – Zawartość listy jednokierunkowej
- `lista_dwukierunkowa.csv` – Zawartość listy dwukierunkowej

**Format CSV**:
```
Index,Value
0,12345
1,67890
2,54321
```

Pliki można importować do Excela, Python'a czy innych narzędzi analitycznych.

---

## 7. System benchmarków wydajnościowych

### 7.1 Jak uruchomić benchmarki

Opcja 1 – Bezpośrednie uruchomienie:
```batch
main.exe --benchmarks
```

Opcja 2 – Interaktywne menu (nr 4 – Badania wydajnościowe):
```batch
main.exe
# Wybierz opcję 4
```

### 7.2 Generator danych testowych

Benchmarki używają **deterministycznego seeda** do generowania danych, co zapewnia powtarzalność wyników i uczciwość porównania.

**Jak działaje logika seeda**:

```
Dla każdego ROZMIARU (5000, 8000, 10000, ..., 100000):
  └─ Dla każdej PRÓBY (attempt 0, 1, 2):
     ├─ Oblicz: seed = 123456 + rozmiar*7919 + numer_próby*131
     │
     ├─ Wygeneruj TAKIE SAME testData z tym seedem
     │ └─ Zawiera (rozmiar + 500) losowych liczb
     │
     ├─ TABLICA DYNAMICZNA:
     │  ├─ Załaduj 'rozmiar' elementów
     │  ├─ Zmierz czas: addAtEnd (500x)
     │  ├─ Zmierz czas: addToFront (500x)
     │  ├─ Zmierz czas: find (500x)
     │  ├─ Zmierz czas: addAtPosition (500x)
     │  ├─ Zmierz czas: removeFromEnd (500x)
     │  ├─ Zmierz czas: removeFromBeginning (500x)
     │  └─ Zmierz czas: removeFromPosition (500x)
     │
     ├─ LISTA JEDNOKIERUNKOWA (te SAME testData):
     │  ├─ Załaduj 'rozmiar' elementów
     │  ├─ Zmierz czas: addAtEnd (500x)
     │  ├─ Zmierz czas: addToFront (500x)
     │  └─ ... (pozostałe operacje)
     │
     └─ LISTA DWUKIERUNKOWA (te SAME testData):
        ├─ Załaduj 'rozmiar' elementów
        ├─ Zmierz czas: addBack (500x)
        └─ ... (odpowiednio nazwane operacje)

Po trzech próbach każdej struktury dla każdego rozmiaru:
├─ Uśrednij wyniki z 3 prób
└─ Zapisz średnią do CSV
```

**Kluczowe punkty**:
- Dla rozmiaru 5000, próba 0: seed = 123456 + 5000*7919 + 0*131 = 39,639,956
- Dla rozmiaru 5000, próba 1: seed = 123456 + 5000*7919 + 1*131 = 39,640,087 (inne dane)
- Dla rozmiaru 8000, próba 0: seed = 123456 + 8000*7919 + 0*131 = 63,395,456 (zupełnie inne dane)
- **Każda struktura otrzymuje DOKŁADNIE TE SAME dane** dla danego rozmiaru i próby

### 7.3 Parametry benchmarków

- **Rozmiary testowe**: 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 elementów
- **Liczba prób**: 3 (dla każdego rozmiaru i operacji)
- **Operacji per pomiar**: 500 (liczba powtórzeń danej operacji w jednym pomiarze)
- **Pomiar czasu**: `std::chrono::high_resolution_clock` (nanosekuncjowa precyzja)
- **Losowe pozycje**: Używają osobnego seeda (seed + 1) aby emulować realistyczne wstawienia/usunięcia

### 7.4 Testowane operacje

| Struktura | add(koniec) | add(początek) | add(pozycja) | remove(koniec) | remove(początek) | remove(pozycja) | find/search |
|-----------|-----------|-------------|----------|------------|-------------|------------|------------|
| Tablica | addAtEnd | addToFront | addAtPosition | removeFromEnd | removeFromBeginning | removeFromPosition | find |
| Lista 1-kier. | addAtEnd | addToFront | addAtPosition | removeFromEnd | removeFromBegining | removeFromPosition | listSearch |
| Lista 2-kier. | addBack | addFront | insertAt | removeBack | removeFront | removeAt | find |

### 7.5 Wynik benchmarków

Po uruchomieniu benchmarków, w katalogu projektu pojawią się pliki CSV:

```
benchmark_tablica_dynamiczna.csv
benchmark_lista_jednokierunkowa.csv
benchmark_lista_dwukierunkowa.csv
```

**Format CSV**:
```
Operation,Size,AverageTime_ns
addAtEnd,5000,64
addToFront,5000,71
addAtPosition,5000,9997
find,5000,9455
removeFromEnd,5000,20936
removeFromBeginning,5000,26
removeFromPosition,5000,9105
...
```

Można je otworzyć w:
- **Excel/LibreOffice** – Bezpośrednio
- **Python** – `import pandas as pd; df = pd.read_csv('benchmark_tablica_dynamiczna.csv')`
- **Google Sheets** – Import → Upload spreadsheet

### 7.6 Analiza wyników

Wyniki pozwalają na:
- Porównanie wydajności trzech struktur dla każdej operacji
- Obserwację jak zmienia się czas w funkcji rozmiaru danych
- Weryfikację teoretycznych złożoności (O(1), O(n), itp.)
- Identyfikację operacji krytycznych dla każdej struktury

---

## 8. Menu interaktywne

Po uruchomieniu `main.exe` pojawi się menu główne z opcjami:

```
1. Tablica dynamiczna     – Testuj operacje na tablicy
2. Lista jednokierunkowa  – Testuj operacje na liście 1-kier.
3. Lista dwukierunkowa    – Testuj operacje na liście 2-kier.
4. Badania wydajnościowe  – Uruchom pełne testy wydajnościowe
5. Wyjście                – Zamknij program
```

Dla każdej struktury można:
- Dodawać elementy (na początek, koniec, w losową pozycję)
- Usuwać elementy (z początku, końca, z losowej pozycji)
- Wyszukiwać elementy
- Przeglądać aktualny rozmiar
- Przeglądać zawartość w saved CSV

Po każdej operacji modyfikującej dana struktura jest automatycznie zapisywana do odpowiedniego pliku CSV.

---

## 9. Plik .gitignore

Plik `.gitignore` excluduje:
- `*.exe` – Pliki wykonywalne (generowane przez kompilację)
- `benchmark_*.csv` – Wyniki benchmarków (generowane automatycznie)
- `input.txt` – Plik tymczasowy (jeśli istnieje)

Tylko kod źródłowy i dokumentacja są versionowane.

---

## 10. Poznotes dla prowadzącego

- **Powtarzalność**: Każde uruchomienie benchmarków z tym samym kodem da identyczne wyniki (dzięki seedowi)
- **Uczciwe porównanie**: Wszystkie trzy struktury pracują na tych samych danych wejściowych
- **Precyzja**: Pomiary w nanosekundach dzięki `high_resolution_clock`
- **Uśrednianie**: 3 próby dla każdej operacji zmniejszają wpływ wahań systemu
- **Skalabilność**: Testowanie od 5000 do 100000 elementów pokazuje skalowanie algorytmów
- **CSV**: Łatwe do importu do narzędzi analitycznych

---