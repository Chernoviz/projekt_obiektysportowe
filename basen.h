#pragma once
#include <string>
#include "obiekt_sportowy.h"
#include "dbg.h"

using namespace std;

class Basen:public Obiekt_sportowy {
public:
	
	Basen(int id, string nazwa, string lokalizacja, int max_osob,int dlugosc,int szerokosc,int glebokosc);
	~Basen();

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
	void ustaw_temp(int temp);
	void ustaw_cene(int cena);
	
	friend ostream& operator << (ostream &s, Basen &basen);
	friend istream& operator >> (istream &s, Basen &basen);
	
	
protected:
	int dlugosc,szerokosc,glebokosc;
	int temperatura_wody;
	int cena_wejscia;
	
private:
};