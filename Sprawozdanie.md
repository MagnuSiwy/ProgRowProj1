# Programowanie Równoległe - Liczby Pierwsze
Wersja pierwsza


### Autorzy
**Grupa dziekańska:** 4<br>
**Grupa labolatoryjna:** 7<br>
**Termin zajęć:** czwartek, 16:50<br>

Tymoteusz Jagła 151811 - tymoteusz.jagla@student.put.poznan.pl<br>
Kaper Magnuszewski 151746 - kacper.magnuszewski@student.put.poznan.pl


### Sprawozdanie
_Wymagany termin oddania sprawozdania -_ 10.05.2024 <br>
_Rzeczywisty termin oddania sprawozdania -_ 10.05.2024 <br>


## Opis zadania
Projekt polegał na zbadaniu efektywności przetwarzania równoległego w komputerze z procesorem wielordzeniowym. Badanym zadaniem było znajdowanie liczb pierwszych w określonym zakresie. Podano różne warianty algorytmów - wyznaczanie liczb pierwszych metodą dzielenia oraz przy użyciu sita Erastothenes'a, w tym podejście sekwencyjne oraz równoległe (domenowe i funkcyjne).


## Wykorzystany system obliczeniowy
### Procesor
  - Model: 13th Gen Intel® Core(TM) i5-13600KF
  - Liczba procesorów fizycznych: 14
  - Liczba procesorów logicznych: 20 
  - Oznaczenie typu procesora: KF
  - Wielkość pamięci podręcznej: 24MB
  - Organizacja pamięci podręcznej: Intel® Smart Cache


### System Operacyjny
  - Nazwa systemu operacyjnego: Linux Pop!-OS 6.8.0
  - Oprogramowanie wykorzystane do przygotowania kodu wynikowego: Visual Studio Code
  - Oprogramowanie wykorzystane do przeprowadzenia testów: Intel VTune Profiler


## Wersje programów
### Liczby pierwsze wyznaczane sekwencyjnie przez dzielenie w zakresie <m, n>
```cpp

```

### Liczby pierwsze wyznaczane równolegle przez dzielenie w zakresie <m,n>
```cpp

```

### Sito sekwencyjne bez lokalności dostępu do danych
```cpp

```


### Sito równoległe funkcyjne bez lokalności dostępu do danych
```cpp

```


### Sito równoległe domenowe z potencjalną lokalnością dostępu do danych
```cpp

```


### Sito równoległe domenowe z potencjalną lokalnością dostępu do danych
```cpp

```