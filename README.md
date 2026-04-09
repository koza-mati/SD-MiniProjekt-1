# Struktury Danych — Miniprojekt 1

Celem projektu jest implementacja trzech podstawowych struktur danych w C++ bez użycia kontenerów STL oraz przygotowanie mechanizmu pomiaru ich wydajności.

Projekt zawiera:
- implementację `DynamicArray` (tablica dynamiczna),
- implementację `listaJednokierunkowa` (lista jednokierunkowa),
- implementację `DoublyLinkedList` (lista dwukierunkowa),
- interaktywne menu do testowania operacji,
- system benchmarków zapisujący wyniki do plików CSV.

---

## 1. Cel projektu

Przeprowadzenie porównania trzech struktur danych pod kątem:
- czasu wykonania operacji dodawania/usuwania elementów,
- czasu wyszukiwania,
- kosztów związanych z pamięcią i sposobem zarządzania danymi.

W projekcie szczególny nacisk położono na:
- staranne zarządzanie pamięcią dynamiczną,
- separację logiki struktury danych od logiki menu,
- powtarzalność i uczciwość testów wydajnościowych.

---

## 2. Budowa projektu

```
SD-MiniProjekt-1/
├── README.md
├── SPRAWOZDANIE.md
├── ZLOZONOSC_OPERACJI.md
├── ANALIZA_BENCHMARKOW.md
├── .gitignore
└── src/
    ├── main.cpp
    ├── menu.hpp
    ├── menu.cpp
    ├── tablica_dynamiczna.hpp
    ├── tablica_dynamiczna.cpp
    ├── listaJednokierunkowa.hpp
    ├── listaJednokierunkowa.cpp
    ├── listaDwukierunkowa.hpp
    └── listaDwukierunkowa.cpp
```

### 2.1 Kompilacja

W katalogu głównym projektu:

```batch
g++ -std=c++17 -Wall -Wextra -o main.exe src\main.cpp src\menu.cpp src\tablica_dynamiczna.cpp src\listaJednokierunkowa.cpp src\listaDwukierunkowa.cpp
```

### 2.2 Uruchomienie

- Interaktywne menu:
  ```batch
  main.exe
  ```
- Benchmarki:
  ```batch
  main.exe --benchmarks
  ```

---

## 3. Implementowane struktury danych

### 3.1 DynamicArray

Źródła: `src/tablica_dynamiczna.hpp`, `src/tablica_dynamiczna.cpp`

Dynamiczna tablica wspiera:
- wstawianie na początek, koniec oraz do wybranej pozycji,
- usuwanie z początku, końca oraz z pozycji,
- wyszukiwanie wartości,
- automatyczne powiększanie bufora.

### 3.2 listaJednokierunkowa

Źródła: `src/listaJednokierunkowa.hpp`, `src/listaJednokierunkowa.cpp`

Lista jednokierunkowa wspiera:
- wstawianie na początek i koniec,
- usuwanie z początku, końca i pozycji,
- liniowe wyszukiwanie elementu,
- optymalizację `addAtEnd` dzięki wskaźnikowi `tail`.

### 3.3 DoublyLinkedList

Źródła: `src/listaDwukierunkowa.hpp`, `src/listaDwukierunkowa.cpp`

Lista dwukierunkowa wspiera:
- wstawianie i usuwanie na obu końcach w O(1),
- pozycjonowane wstawianie i usuwanie,
- liniowe wyszukiwanie elementu,
- dwukierunkowy dostęp do kolejnych węzłów.

---

## 4. Mechanizm benchmarków

Benchmarki mierzą czas 7 typów operacji dla wszystkich struktur:
- wstawianie na koniec / koniec lub początek,
- wstawianie na wybraną pozycję,
- usuwanie z początku / końca / pozycji,
- wyszukiwanie wartości.

Dane do testów generowane są deterministycznie z użyciem `std::mt19937`, dzięki czemu testy są powtarzalne i porównywalne.

Wyniki zapisywane są w formacie CSV, co umożliwia dalszą analizę i tworzenie wykresów.

---

## 5. Ocena i weryfikacja

Projekt został przygotowany z myślą o ocenie prowadzącego:
- kod źródłowy jest jasno rozdzielony na moduły,
- metody operacyjne posiadają dokumentację i komentarze,
- istnieją pliki pomocnicze opisujące złożoności i analizę benchmarków,
- `.gitignore` wyklucza pliki binarne i tymczasowe pliki benchmarków.

Pliki dodatkowe:
- `SPRAWOZDANIE.md` — pełne sprawozdanie projektowe,
- `ZLOZONOSC_OPERACJI.md` — tabela i analiza złożoności operacji,
- `ANALIZA_BENCHMARKOW.md` — omówienie wyników eksperymentalnych.

---

## 6. Uwagi dla prowadzącego

- Projekt realizuje wymagania dotyczące implementacji własnych struktur bez STL.
- Wszystkie trzy struktury korzystają z dynamicznej alokacji pamięci.
- Benchmarki wykonują pomiary w kontrolowany sposób.
- Pliki wynikowe benchmarków nie są śledzone przez Git.

Jeżeli prowadzący będzie chciał, mogę również dostarczyć krótki zestaw zrzutów ekranu z wyników benchmarków lub dodatkową wersję z exportem do plików graficznych.
