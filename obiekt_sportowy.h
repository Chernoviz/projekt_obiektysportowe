#pragma once
#include <string>
#include "dbg.h"

using namespace std;

 class Obiekt_sportowy {
public:
	 Obiekt_sportowy(string typ_obiektu, int id, string nazwa, string lokalizacja, int max_osob);
	 virtual ~Obiekt_sportowy();
	 virtual string daj_cennik(); //Przyklad dzialania polimorfizmu, mozna wykasowac "virtual"
	 virtual void zapisz() = 0;//zapis obiektu do oddzielnego pliku "TYPOBIEKTU_ID.txt" np.: "BASEN_5.txt"
	 virtual void odczytaj(int file_id) = 0;//Odczyt stanu obiektu z pliku o podanym id;
	 virtual void wyswietl_strumien() = 0;//wyswietlanie surowych danych ze strumienia
	 virtual void wyswietl();//sformatowane wyswietlanie obiektu
	 virtual string daj_stan_obiektu() = 0;//zwraca dane obiektu w postaci zmiennej string
	 virtual void odczytaj(ifstream &s) = 0;//odczyt stanu obiektu ze strumienia
	 virtual void edytuj() = 0;//metoda obsluguj¹ca edycje danego obiektu
	
	 string daj_typ();
	 int daj_id();
	 string daj_nazwa();

	 friend ostream& operator << (ostream &s, Obiekt_sportowy &os);
	 friend istream& operator >> (istream &s, Obiekt_sportowy &os);
		
protected:
	bool stoigood(string s); //metoda do sprawdzajaca mozliwosc konwersji string do int
	string typ_obiektu;
	int id;
	string nazwa;
	string lokalizacja;
	int max_osob;
	int akt_osob;
private:
};