#include "klient.h"
//#define _DBG
#include "dbg.h"
using namespace std;

Klient::Klient()
{
	DBG("Konstruktor Domyslny Klienta");
}
Klient::Klient(int id)
{
	this->rachunek = 15;
	this->czas_cwiczen = 0;
	this->id = id;
	DBG("Konstruktor klienta o ID "<<id);
}
Klient::~Klient()
{
	DBG("Destruktor klienta o ID "<<this->id);
}



void Klient::ustal_dane_osobowe()
{
	//prowizoryczna baza danych
	switch (this->daj_id())
	{
	case 100:
		this->imie = "Robert";
		this->nazwisko = "Czerniewicz";
		this->wiek = 19;
		this->BMI = 27.6;
	break;
	case 101:
		this->imie = "Marek";
		this->nazwisko = "Parek";
		this->wiek = 60;
		this->BMI = 35.5;
		break;
	case 102:
		this->imie = "Agata";
		this->nazwisko = "Koza";
		this->wiek = 34;
		this->BMI = 24.3;
		break;
	case 103:
		this->imie = "Tomasz";
		this->nazwisko = "Paluch";
		this->wiek = 29;
		this->BMI = 26.5;
		break;
	case 104:
		this->imie = "Jakub";
		this->nazwisko = "Pomidor";
		this->wiek = 11;
		this->BMI = 20.0;
		break;
	case 105:
		this->imie = "Nikodem";
		this->nazwisko = "Kapusta";
		this->wiek = 16;
		this->BMI = 20.2;
		break;
	case 106:
		this->imie = "Paulina";
		this->nazwisko = "Goblin";
		this->wiek = 12;
		this->BMI = 21.3;
		break;
	case 107:
		this->imie = "Patrycja";
		this->nazwisko = "Pokemon";
		this->wiek = 18;
		this->BMI = 19.6;
		break;
	case 108:
		this->imie = "Kamil";
		this->nazwisko = "Malina";
		this->wiek = 40;
		this->BMI = 20.7;
		break;
	case 109:
		this->imie = "Ewa";
		this->nazwisko = "Mewa";
		this->wiek = 78;
		this->BMI = 34.6;
		break;
	case 110:
		this->imie = "Bartosz";
		this->nazwisko = "Kaczka";
		this->wiek = 16;
		this->BMI = 21.9;
		break;


	default:
		this->imie = "Norman";
		this->nazwisko = "Normalny";
		this->wiek = 99;
		this->BMI = 0.0;
		break;


	}
}

void Klient::dodaj_do_rachunku(int kasa)
{
	this->rachunek += kasa;
}

void Klient::wejdz_na_bieznie_na_x_minut(Bieznia b,int x)
{
	this->czas_cwiczen += x;
	this->dodaj_do_rachunku(x*b.daj_cene());

}

void Klient::trenuj_z_trenerem(Trener t)
{
	this->czas_cwiczen += 60;
	this->dodaj_do_rachunku(t.daj_cene());
}

int Klient::daj_rachunek()
{
	return this->rachunek;
}

int Klient::daj_id()
{
	return this->id;
}

string Klient::daj_dane()
{
	return "ID="+to_string(id)+" "+imie+" "+nazwisko+" "+to_string(wiek)+" lat "+"Stan rachunku: "+to_string(rachunek)+" PLN";
}

void Klient::wyswietl_dane_klienta()
{
	cout << id << "   " << imie << "   " << nazwisko << endl;
}

ostream& operator<<(ostream &s, Klient &klient)
{
	s << "-- Klient " << endl << klient.id << endl << klient.imie << endl << klient.nazwisko << endl << klient.wiek << endl << klient.BMI << endl << klient.rachunek << endl << klient.czas_cwiczen << endl;
	return s;
}

istream& operator>>(istream &s, Klient &klient)
{
	string str;
	s >> str >> str; //Pominiecie lini komentarza "-- Klient"
	s >> klient.id >> klient.imie >> klient.nazwisko >> klient.wiek >> klient.BMI >> klient.rachunek >> klient.czas_cwiczen;
	return s;
}