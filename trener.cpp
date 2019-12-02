#include "trener.h"
//#define _DBG
#include "dbg.h"
using namespace std;
Trener::Trener(int cena)
{
	this->cena_za_trening = cena;
	DBG("Konstruktor Trener " << imie);

}
Trener::~Trener()
{
	DBG("Desktruktor Trener " << imie);
}

string Trener::daj_dane()
{
	return imie + " " + nazwisko + " Cena: " + to_string(cena_za_trening) + " PLN";
}

void Trener::ustaw_cene(int x)
{
	this->cena_za_trening = x;
}

void Trener::wprowadz_dane_osobowe(string imie, string nazwisko, int wiek)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wiek = wiek;
}

int Trener::daj_cene()
{
	return this->cena_za_trening;
}

bool Trener::operator > (const Trener t)
{
	if (cena_za_trening > t.cena_za_trening)
		return true;
	else
		return false;
}

bool Trener::operator<(const Trener t)
{
	if (cena_za_trening < t.cena_za_trening)
		return true;
	else
		return false;

}

bool Trener::operator>=(const Trener t)
{
	if (cena_za_trening >= t.cena_za_trening)
		return true;
	else
		return false;
}

bool Trener::operator<=(const Trener t)
{
	if (cena_za_trening <= t.cena_za_trening)
		return true;
	else
		return false;
}

Trener& Trener::operator+=(const int x)
{
	this->cena_za_trening += x;
	return *this;
}

Trener & Trener::operator-=(const int x)
{
	this->cena_za_trening -= x;
	return *this;
}

ostream& operator<<(ostream &s, Trener &trener)
{
	s << "-- Trener " << endl << trener.imie << endl << trener.nazwisko << endl << trener.wiek << endl << trener.cena_za_trening << endl;
	return s;

}

istream & operator>>(istream & s, Trener & trener)
{
	string str;
	s >> str >> str; //Pominiecie lini komentarza "-- Trener"
	s >> trener.imie >> trener.nazwisko >> trener.wiek >> trener.cena_za_trening;
	return s;
}

