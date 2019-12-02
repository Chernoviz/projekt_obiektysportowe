#include "bieznia.h"
//#define _DBG
#include "dbg.h"
using namespace std;
Bieznia::Bieznia(int numer , string marka,int cena)
{
	this->marka = marka;
	this->numer_seryjny = numer;
	this->cena_za_minute = cena;
	DBG("Konstruktor Bieznia nr " << numer_seryjny);
}
Bieznia::~Bieznia()
{
	DBG("Destruktor Bieznia nr " << numer_seryjny);
}

string Bieznia::daj_dane()
{
	return marka + " Nr " + to_string(numer_seryjny) + " Cena: " + to_string(cena_za_minute) +" PLN";
}

int Bieznia::daj_cene()
{
	return this->cena_za_minute;
}

string Bieznia::daj_marka()
{
	return this->marka;
}

int Bieznia::daj_numer_seryjny()
{
	return this->numer_seryjny;
}

Bieznia & Bieznia::operator++(int)
{
	(this->cena_za_minute)++;
	return *this;
}

Bieznia & Bieznia::operator--(int)
{
	(this->cena_za_minute)--;
	return *this;
}

ostream & operator<<(ostream & s, Bieznia & bieznia)
{
	s <<"-- Bieznia:\n"<< bieznia.numer_seryjny << endl << bieznia.marka << endl << bieznia.cena_za_minute<<endl;
	return s;
}

istream & operator>>(istream & s, Bieznia & bieznia)
{
	string str;
	s >> str >> str; //Pominiecie lini komentarza "-- Bieznia"
	s >> bieznia.numer_seryjny >> bieznia.marka >> bieznia.cena_za_minute;
	return s;
}
