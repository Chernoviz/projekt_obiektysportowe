#pragma once
#include <string>
#include <time.h>
#include "bieznia.h"
#include "trener.h"
using namespace std;
class Klient{
public:
	Klient();
	Klient(int id);
	~Klient();
	
private:
	int id;
	string imie;
	string nazwisko;
	int wiek;
	float BMI;
	int rachunek;
	int czas_cwiczen;
public:
	void ustal_dane_osobowe();
	void dodaj_do_rachunku(int kasa);
	void wejdz_na_bieznie_na_x_minut(Bieznia b,int x);
	void trenuj_z_trenerem(Trener t);
	int daj_rachunek();
	int daj_id();
	string daj_dane();

	friend ostream& operator << (ostream &s, Klient &klient);
	friend istream& operator >> (istream &s, Klient &klient);


	//do testow
	void wyswietl_dane_klienta();

};