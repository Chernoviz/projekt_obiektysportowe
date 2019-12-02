#pragma once
#include <string>
#include "basen.h"
#include "dbg.h"

using namespace std;

class Basen_sauna :public Basen {
public:
	Basen_sauna(int id, string nazwa, string lokalizacja, int max_osob, int dlugosc, int szerokosc, int glebokosc,int powierzchnia);
	~Basen_sauna();
	
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
	void ustaw_cene_sauny(int cena);
	void ustaw_temp_sauny(int temp);

	friend ostream& operator << (ostream &s, Basen_sauna &basen_sauna);
	friend istream& operator >> (istream &s, Basen_sauna &basen_sauna);
	
	
protected:
	int powierzchnia;
	int cena_sauny;
	int temperatura_sauna;
	
private:
};