#pragma once
#include <iostream>
#include <string>
#include "obiekt_sportowy.h"
#include "trener.h"
#include "klient.h"
#include "bieznia.h"
#include <vector>

using namespace std;
class Silownia:public Obiekt_sportowy {
public:
	Silownia();
	Silownia(int id,string nazwa,string lokalizacja);
	~Silownia();
	Silownia(const Silownia &s);
	Trener trener1=Trener(30);
	Trener trener2=Trener(50);
	vector<Klient*> vector_klientow;
	Bieznia bieznia1 = Bieznia(100, "Nokia",10);
	Bieznia bieznia2 = Bieznia(200, "Honda",18);
	Bieznia bieznia3 = Bieznia(300, "Jogobella",35);
	Bieznia bieznia4 = Bieznia(400, "Samsung",50);
private:
	static int zarobek;
	static int liczba_silowni;
	static int liczba_dzialajacych_silowni;
	int powierzchnia_m2;

public:
	//Metody wirtualne z Obiekt_sportowy
	string daj_cennik();
	void zapisz();
	void odczytaj(int file_id);
	void wyswietl_strumien();
	void wyswietl();
	string daj_stan_obiektu();
	void odczytaj(ifstream &s);
	void edytuj();
	//

	friend ostream& operator << (ostream &s, Silownia &silownia);
	friend istream& operator >> (istream &s, Silownia &silownia);

	void ustaw_powierzchnie(int x);
	void wyczysc_klienci();
	void klient_wchodzi(int id);
	void klient_wychodzi(int id);
	static int ile_silowni();
	static int ile_dzialajacych_silowni();
	static void dodaj_do_zarobek(int x);
	static int ile_zarobione();
	void wyswietl_klientow();
	bool operator==(const Silownia &s);
	Silownia& operator=(const Silownia &s);
	operator int() const;
	int operator[](int i);
};	