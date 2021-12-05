#Sezon ogórkowy

Dostępna pamięć: 512 MB

Rozpoczyna się sezon ogórkowy, a z tej okazji przygotowywany jest doroczny Konkurs Uprawy Ogórka organi-
zowany na prostokątnym fragmencie Pola Ogórkowego podzielonego na kwadratowe działki o boku 1m. Jako
że wydarzenie to jest bardzo medialne, żeby ułatwić streamowanie online, miejsce konkursu jest prostokątem
o bokach równoległych do osi Pola i przebiegającym wzdłuż granic działek. Wielkość pola konkursowego jest
dobierana w zależności od liczby uczestników: każdy uczestnik dostaje do uprawy swoją wydzieloną działkę, a
każda działka na polu jest uprawiana przez jednego z uczestników.

Niestety, nie każda działka jest jednakowo żyzna, co powoduje, że szanse uczestników nie są równe. Dlatego
zarząd Konkursu, poprosił Cię o napisanie programu który dla każdej propozycji położenia pola konkursowego
wyznaczy jej współczynnik sprawiedliwości, zdefiniowany jako różnica poziomu żyzności najbardziej i najmniej
żyznej działki wchodzącej w obręb pola konkursowego

Wejście
W pierwszym wierszu standardowego wejścia znajdują się trzy liczby całkowite 
```n, m i k (m, n ≥1, 1 ≤ n∗m ≤1 000 000, 1 ≤k ≤50 000)```, 
pooddzielane pojedynczymi odstępami i oznaczające odpowiednio wysokość i szerokość Pola Ogórkowego oraz liczbę zapytań.

Każdy z kolejnych n wierszy zawiera po m liczb naturalnych 
```zi,j (1 ≤zi,j ≤1 000 000 000) ```
reprezentujących poziom żyzności gleby na działce znajdującej się w i-tym wierszu i j-tej kolumnie Pola Ogórkowego, gdzie ```z0,0```
oznacza żyzność skrajnej lewej górnej działki, a ```zn−1,m−1``` skrajnej prawej dolnej.

W kolejnych k wierszach są zapisane informacje o kolejnych propozycjach położenia pola konkursowego.
W ```(n + i + 1)```-szym wierszu zostały zapisane cztery liczby całkowite 
```x1, y1, x2 i y2 (0 ≤x1 ≤x2 < n,0 ≤y1 ≤y2 < m) ```
oznaczające współrzędne skrajnej lewej górnej i skrajnej prawej dolnej działki należącej do
pola konkursowego.

Wyjście
Wyjście powinno składać się z k wierszy. W i-tym z nich należy wypisać współczynnik sprawiedliwości i-tej
propozycji położenia pola konkursowego.
Przykład
Dla danych wejściowych:
```
3 6 5
2 3 2 1 5 8
4 3 5 2 7 1
1 6 3 5 8 3
0 0 2 2
0 2 1 4
1 5 2 5
1 2 2 4
1 1 1 1
```
poprawnym wynikiem jest:
```
5
6
2
6
0
```
Wyjaśnienie do przykładu: Współczynniki sprawiedliwości dla kolejnych propozycji obliczane są jako:
```
•6 −1 = 5
•7 −1 = 6
•3 −1 = 2
•8 −2 = 6
•3 −3 = 0```
