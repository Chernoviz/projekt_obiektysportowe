Robert Czerniewicz 300505 Glowny projekt: Kurort Wakacyjny - > Silownia
LABORATORIUM PROE.B, PROJEKT 2
DZIEDZICZENIE, ABSTRAKCJA DANYCH, HERMETYZACJA, WEKTORY BIBLIOTEKI STL


1. Stworzyłem klasę abstrakcyjną "Obiekty_sportowe" z której dziedziczą klasy 
	"Basen" jako B, 
	"Basen_sauna" jako C 
	"Silownia" jako D (klasa z projektu 1)
zaimplementowałem wiele metod virtualnych. np. metoda 
daj_cennik()- zwraca aktualne ceny Basenu/ Basenu z sauną lub Silowni w zalezności od typu obiektu na jaki wskazuje wskaźnik.
Ceny w każdej z tych klas naliczane są inaczej (basen za wejscie, sauna za czas, siłownie za konkretne czynności)

2. Zaimplementowalem hierarchiczne operatory strumieniowe dla wszystkich utworzonych klas. (operator definiowany dla klasy potomnej
wykorzystuje operator dla klasy bazowej).

3. Pola klasy Obiekty_sportowe umiesciłem pod deklaratorem zakresu protected aby były dostępne tylko dla klas pochodnych.

4. W klasie Silownia tablice obiektów zastąpiłem kontenerem vector.

5. We wszystkich klasach obiektów spotrowych zaimplementowałem metody zapisywania/odczytywania stanu całego obiektu do/z pliku
Zgodnie z zaleceniem , zapis i odczyt wykorzystuje wczesniej zaimplementowane hierarchiczne operatory strumieniowe wiec działa kaskadowo 
i nie było konieczności korzystania z metod z klasy bazowej bo załatwia to hierarchiczny operator strumieniowy.
Jest możliwość zapisu wielu obiektów do oddzielnych plików oraz jednego pliku.

6. W programie stworzyłem vector wskaźników na klasę A (Obiekty_sportowe) z mozliwoscią dodawania obiektów róznego typu (Silownia. Basen, Basen_sauna)

Napisana aplikacja konsolowa pozwala na:
- dodawanie obiektów klas B, C oraz D do wektora wskaźników na klasę A, ich modyfikowanie i usuwanie.
- demonstrację działania polimorfizmu (po usunięciu słowa virtual z deklaracji funkcji wirtualnej uruchamia sie metoda z klasy A);
- zapis do jednego pliku (KOLEKCJA_OBIEKTOW.txt) stanu wszystkich obiektów przechowywanych w kontenerze vector 
- odtworzenie całej kolekcji obiektów z pliku (KOLEKCJA_OBIEKTOW.txt)
- wypisanie na ekran stanu wszystkich obiektów z wektora.



