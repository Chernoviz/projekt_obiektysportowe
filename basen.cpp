#include <string>
#include <iostream>
#include "basen.h"
#include "obiekt_sportowy.h"
#include <fstream>
#include <sstream>
using namespace std;

Basen::Basen(int id, string nazwa, string lokalizacja, int max_osob, int dlugosc, int szerokosc, int glebokosc)
:Obiekt_sportowy("Basen",id, nazwa, lokalizacja, max_osob)
{
	this->cena_wejscia = 0;
	this->temperatura_wody = 20;
	this->dlugosc = dlugosc;
	this->szerokosc = szerokosc;
	this->glebokosc = glebokosc;
}

Basen::~Basen()
{
	DBG("Destrukor basen");
}

string Basen::daj_cennik() {

	return "Cennik basenu '" +daj_nazwa()+ "' :\n"+to_string(cena_wejscia)+" PLN - Cena za wejscie bez limitu czasu.\n";
}

void Basen::ustaw_temp(int temp) {
	temperatura_wody = temp;
}

void Basen::ustaw_cene(int cena) {
	cena_wejscia = cena;
}

void Basen::zapisz()
{
	ofstream plik("BASEN_" + to_string(id) + ".txt");
	plik << *this;
	plik.close();
	cout << "Zapisano plik: BASEN_" + to_string(id) + ".txt" << endl;
}

void Basen::odczytaj(int file_id)
{
	string str;
	ifstream plik("BASEN_" + to_string(file_id) + ".txt");
	if (plik.is_open())
	{
		plik >> str;
		if (str[0] == '/' and str[1] == '/' and str[2] == '-')  //znacznik pocz¹tku obiektu 
		{
			plik >> str;
			if (str == "Basen")  // sprawdzenie zgodnoœci typu
			{
				plik >> *this;
			}
			else
				cout << "Blad odczytu. Niezgodnoœæ typu pliku: BASEN_" + to_string(file_id) + ".txt" << endl;
		}
		else
			cout << "Blad odczytu. Niepoprawny format pliku: BASEN_" + to_string(file_id) + ".txt" << endl;

		plik.close();
	}
	else
		cout << "Blad odczytu!!!. Nie mozna otworzyc pliku: BASEN_" + to_string(file_id) + ".txt" << endl;

}

void Basen::wyswietl_strumien()
{
	cout << *this;
}

void Basen::wyswietl()
{
	Obiekt_sportowy::wyswietl();
	cout << "Wymiary basenu:  " << dlugosc << " x " << szerokosc << " x " << glebokosc << endl;
	cout << "Temp. wody:      " << temperatura_wody << " stopni C." << endl;
	cout << "Cena wejscia:    " << cena_wejscia << " PLN" << endl;
}

string Basen::daj_stan_obiektu()
{
	ostringstream stream;
	stream << *this;
	return stream.str();
}

void Basen::odczytaj(ifstream & s)
{
	s >> *this;
}

void Basen::edytuj()
{

	string str;
	str = "0";
	string str2 = "0";
	do
	{
		switch (stoi(str))
		{
		case 0:
			cout << "Edycja basenu "<<nazwa<< endl;
			wyswietl();
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Zmien temperature wody" << endl;
			cout << "2: Zmien cene" << endl;
			cout << "9: Koniec edycji" << endl;
			cout << "-------------------------------" << endl;
			cout << "Opcja: ";
			getline(cin, str);
			try
			{
				stoi(str);
			}
			catch (const invalid_argument& ia)
			{
				cout << '\a';
				str = "100";
				break;
			}
			break;
		case 1:
			system("cls");
			
			do
			{
				cout << endl;
				cout << "Podaj nowa temperature wody: ";
				getline(cin, str);
			} while (!stoigood(str));
			temperatura_wody = stoi(str);

			str = "0";
			break;
		case 2:
			system("cls");

			do
			{
				cout << endl;
				cout << "Podaj nowa cene: ";
				getline(cin, str);
			} while (!stoigood(str));
			cena_wejscia = stoi(str);

			str = "0";
			break;
		default:
			system("cls");
			cout << '\a';
			cout << endl;
			cout << "Wybrano niepoprawna opcje." << endl;
			str = "0";
		}
	} while (stoi(str) != 9);
}

ostream & operator<<(ostream &s, Basen &basen)
{
	s << (Obiekt_sportowy&)basen;
	s <<  basen.dlugosc << endl  << basen.szerokosc << endl << basen.glebokosc << endl  << basen.temperatura_wody << endl <<  basen.cena_wejscia << endl;
	return s;
}

istream & operator>>(istream &s, Basen &basen)
{
	s >> (Obiekt_sportowy&)basen;
	s >> basen.dlugosc >> basen.szerokosc >> basen.glebokosc >> basen.temperatura_wody >> basen.cena_wejscia;
	return s;
}
