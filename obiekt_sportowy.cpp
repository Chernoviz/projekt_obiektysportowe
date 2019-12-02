#include "obiekt_sportowy.h"
#include <iostream>
#include <fstream>
using namespace std;

Obiekt_sportowy::Obiekt_sportowy(string typ_obiektu,int id,string nazwa,string lokalizacja,int max_osob)
{
	DBG("Konstruktor Obiekt sportowy");
	this->typ_obiektu = typ_obiektu;
	this->id = id;
	this->nazwa = nazwa;
	this->lokalizacja = lokalizacja;
	this->max_osob=max_osob;
	this->akt_osob = 0;
}

Obiekt_sportowy::~Obiekt_sportowy()
{
	DBG("Destruktor Obiekt sportowy");
}

string Obiekt_sportowy::daj_cennik()
{
	return "Ktos wlasnie wykasowal slowo 'virtual' przed deklaracja tej metody\n";
}

string Obiekt_sportowy::daj_nazwa()
{
	return nazwa;
}

void Obiekt_sportowy::wyswietl()
{
	cout << endl << "**********  Obiekt sportowy typu: " << typ_obiektu << " o id=" << id << "  *********************" << endl;
	cout << "Nazwa:           " << nazwa << endl;
	cout << "Lokalizacja:     " << lokalizacja << endl;
	cout << "Osoby w ob.:     " << akt_osob << "/" << max_osob << endl;
}

string Obiekt_sportowy::daj_typ()
{
	return typ_obiektu;
}

int Obiekt_sportowy::daj_id()
{
	return id;
}

bool Obiekt_sportowy::stoigood(string s)
{
	try
	{
		stoi(s);
	}
	catch (const invalid_argument& ia)
	{
		return false;
	}
	if (stoi(s) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream & operator<<(ostream & s, Obiekt_sportowy &os)
{
	s  << "//------------------ " << os.typ_obiektu <<endl<< os.id << endl << os.nazwa << endl << os.lokalizacja << endl << os.max_osob << endl <<  os.akt_osob << endl;
	return s;
}

istream & operator>>(istream &s, Obiekt_sportowy &os)
{
	s >> os.id;
	getline(s, os.nazwa); getline(s, os.nazwa);
	getline(s, os.lokalizacja);
	s >> os.max_osob >> os.akt_osob;
	return s;
}

