#include "basen_sauna.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Basen_sauna::Basen_sauna(int id, string nazwa, string lokalizacja, int max_osob, int dlugosc, int szerokosc, int glebokosc, int powierzchnia)
:Basen(id,nazwa,lokalizacja,max_osob,dlugosc,szerokosc,glebokosc)
{
	Obiekt_sportowy::typ_obiektu = "Basen_sauna";
	this->powierzchnia = powierzchnia;
	this->cena_sauny = 0;
	this->temperatura_sauna = 20;
}

Basen_sauna::~Basen_sauna()
{
	DBG("Destruktor Basen sauna");
}

string Basen_sauna::daj_cennik()
{
	string cena = Basen::daj_cennik();
	return cena + to_string(cena_sauny) + " PLN - cena za godzine sauny(opcjonalnie).\n";
}

void Basen_sauna::ustaw_cene_sauny(int cena)
{
	cena_sauny = cena;
}

void Basen_sauna::ustaw_temp_sauny(int temp)
{
	temperatura_sauna = temp;
}

void Basen_sauna::zapisz()
{
	ofstream plik("BASEN_SAUNA_" + to_string(id) + ".txt");
	plik << *this;
	plik.close();
	cout << "Zapisano plik: BASEN_SAUNA_" + to_string(id) + ".txt" << endl;
}

void Basen_sauna::odczytaj(int file_id)
{
	string str;
	ifstream plik("BASEN_SAUNA_" + to_string(file_id) + ".txt");
	if (plik.is_open())
	{
		plik >> str;
		if (str[0] == '/' and str[1] == '/' and str[2] == '-')  //znacznik pocz¹tku obiektu 
		{
			plik >> str;
			if (str == "Basen_sauna")  // sprawdzenie zgodnoœci typu
			{
				plik >> *this;
			}
			else
				cout << "Blad odczytu. Niezgodnoœæ typu pliku: BASEN_SAUNA_" + to_string(file_id) + ".txt" << endl;
		}
		else
			cout << "Blad odczytu. Niepoprawny format pliku: BASEN_SAUNA_" + to_string(file_id) + ".txt" << endl;

		plik.close();
	}
	else
		cout << "Blad odczytu!!!. Nie mozna otworzyc pliku: BASEN_SAUNA_" + to_string(file_id) + ".txt" << endl;

}

void Basen_sauna::wyswietl_strumien()
{
	cout << *this;
}

void Basen_sauna::wyswietl()
{
	Basen::wyswietl();
	cout << "Temp. sauny:     " << temperatura_sauna << " stopni C." << endl;
	cout << "Cena sauny:      " << cena_sauny << " PLN" << endl;
}

string Basen_sauna::daj_stan_obiektu()
{
	ostringstream stream;
	stream << *this;
	return stream.str();
}

void Basen_sauna::odczytaj(ifstream & s)
{
	s >> *this;
}

void Basen_sauna::edytuj()
{

	string str;
	str = "0";
	string str2 = "0";
	do
	{
		switch (stoi(str))
		{
		case 0:
			cout << "Edycja basenu z sauna " << nazwa << endl;
			wyswietl();
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Zmien temperature wody" << endl;
			cout << "2: Zmien cene" << endl;
			cout << "3: Zmien temperature sauny" << endl;
			cout << "4: Zmien cene sauny" << endl;
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
		case 3:
			system("cls");
			do
			{
				cout << endl;
				cout << "Podaj nowa temperature sauny: ";
				getline(cin, str);
			} while (!stoigood(str));
			temperatura_sauna = stoi(str);
			str = "0";
			break;
		case 4:
			system("cls");
			do
			{
				cout << endl;
				cout << "Podaj nowa cene sauny: ";
				getline(cin, str);
			} while (!stoigood(str));
			cena_sauny = stoi(str);
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

ostream & operator<<(ostream & s, Basen_sauna & basen_sauna)
{
	s << (Basen&)basen_sauna;
	s << basen_sauna.powierzchnia << endl  << basen_sauna.cena_sauny << endl  << basen_sauna.temperatura_sauna << endl;
	return s;
}

istream & operator>>(istream & s, Basen_sauna & basen_sauna)
{
	s >> (Basen&)basen_sauna;
	s >> basen_sauna.powierzchnia >> basen_sauna.cena_sauny >> basen_sauna.temperatura_sauna;
	return s;
}
