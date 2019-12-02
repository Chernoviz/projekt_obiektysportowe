#pragma once
#include <string>
//#include "klient.h"
using namespace std;
class Trener{
	
public:
	Trener(int cena);
	~Trener();
private:
	string imie;
	string nazwisko;
	int wiek;
	int cena_za_trening;
public:
	string daj_dane();
	void ustaw_cene(int x);
	void wprowadz_dane_osobowe(string imie,string nazwisko,int wiek);
	int daj_cene();
	bool operator > (const Trener t); 
	bool operator < (const Trener t);
	bool operator >= (const Trener t);
	bool operator <= (const Trener t);
	Trener& operator +=(const int x);
	Trener& operator -=(const int x);

	friend ostream& operator << (ostream &s, Trener &trener);
	friend istream& operator >> (istream &s, Trener &trener);

};
