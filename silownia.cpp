#include "silownia.h"
#include <fstream>
//#define _DBG
#include "dbg.h"
#include <sstream>
using namespace std;
int Silownia::liczba_silowni=0;
int Silownia::liczba_dzialajacych_silowni=0;
int Silownia::zarobek = 0;
Silownia::Silownia():
Obiekt_sportowy("Silownia", 0, "BRAK", "BRAK", 0)
{
	DBG("Konstruktor domyslny Silownia");
	Silownia::liczba_dzialajacych_silowni++;
	Silownia::liczba_silowni++;
}
Silownia::Silownia(int id,string nazwa,string lokalizacja)
:Obiekt_sportowy("Silownia", id, nazwa, lokalizacja,20)
{
	trener1.wprowadz_dane_osobowe("IMIE", "NAZWISKO", 0);
	trener2.wprowadz_dane_osobowe("IMIE", "NAZWISKO", 0);
	DBG("Konstruktor Silownia Nazwa: " << nazwa << "   Lokalizacja: " << lokalizacja);
	this->powierzchnia_m2 = 400;
	Silownia::liczba_dzialajacych_silowni++;
	Silownia::liczba_silowni++;
}
Silownia::~Silownia()
{
	DBG("Destruktor Silownia Nazwa : " << Obiekt_sportowy::nazwa << "   Lokalizacja : " << Obiekt_sportowy::lokalizacja);
	Silownia::liczba_dzialajacych_silowni--;
	wyczysc_klienci();
}

Silownia::Silownia(const Silownia & s) :
	powierzchnia_m2(s.powierzchnia_m2),
	trener1(s.trener1),
	trener2(s.trener2),
	bieznia1(s.bieznia1),
	bieznia2( s.bieznia2),
	bieznia3( s.bieznia3),
	bieznia4( s.bieznia4),
	Obiekt_sportowy(s.typ_obiektu, s.id, s.nazwa, s.lokalizacja,s.max_osob)
{
	DBG("Konstruktor kopiujacy Silownia");
	Silownia::liczba_dzialajacych_silowni++;
	Silownia::liczba_silowni++;
	for (int i = 0; i < s.vector_klientow.size(); i++)
	{
		vector_klientow.push_back(s.vector_klientow[i]);
	}
}

string Silownia::daj_cennik()
{
	return "Cennik silowni '" + daj_nazwa() + "' :\n"  
		+ to_string(bieznia1.daj_cene()) + " PLN \t- Bieznia " + bieznia1.daj_marka() + ", cena za 15 minut.\n"
		+ to_string(bieznia2.daj_cene()) + " PLN \t- Bieznia " + bieznia2.daj_marka() + ", cena za 15 minut.\n"
		+ to_string(bieznia3.daj_cene()) + " PLN \t- Bieznia " + bieznia3.daj_marka() + ", cena za 15 minut.\n"
		+ to_string(bieznia4.daj_cene()) + " PLN \t- Bieznia " + bieznia4.daj_marka() + ", cena za 15 minut.\n"
		+ to_string(trener1.daj_cene()) + " PLN \t- Trener EASY, cena za godzinny trening.\n"
		+ to_string(trener2.daj_cene())+" PLN \t- Trener EXPERT, cena za godzinny trening.\n"
		;
}

void Silownia::zapisz()
{
	ofstream plik("SILOWNIA_" + to_string(id) + ".txt");
	plik << *this;
	plik.close();
	cout << "Zapisano plik: SILOWNIA_" + to_string(id) + ".txt" << endl;
}

void Silownia::odczytaj(int file_id)
{
	string str;
	ifstream plik("SILOWNIA_" + to_string(file_id) + ".txt");
	if (plik.is_open())
	{
		plik >> str;
		if (str[0] == '/' and str[1] == '/' and str[2] == '-')  //znacznik pocz¹tku obiektu 
		{
			plik >> str;
			if (str == "Silownia")  // sprawdzenie zgodnoœci typu
			{
				plik >> *this;
			}
			else
				cout << "Blad odczytu. Niezgodnoœæ typu pliku: SILOWNIA_" + to_string(file_id) + ".txt" << endl;
		}
		else
			cout << "Blad odczytu. Niepoprawny format pliku: SILOWNIA_" + to_string(file_id) + ".txt" << endl;

		plik.close();
	}
	else
		cout << "Blad odczytu!!!. Nie mozna otworzyc pliku: SILOWNIA_" + to_string(file_id) + ".txt" << endl;

}

void Silownia::wyswietl_strumien()
{
	cout << *this;
}

void Silownia::wyswietl()
{
	Obiekt_sportowy::wyswietl();
	cout << "Powierzchnia:    " << powierzchnia_m2 << endl;
	cout << "Trener EASY:     " << trener1.daj_dane() << endl;
	cout << "Trener EXPERT:   " << trener2.daj_dane() << endl;
	cout << "Bieznia:         " << bieznia1.daj_dane() << endl;
	cout << "Bieznia:         " << bieznia2.daj_dane() << endl;
	cout << "Bieznia:         " << bieznia3.daj_dane() << endl;
	cout << "Bieznia:         " << bieznia4.daj_dane() << endl;
	for (int i = 0; i < vector_klientow.size(); i++)
	{
		cout << "\tKlient:          " << vector_klientow[i]->daj_dane()<<endl;
	}

}

string Silownia::daj_stan_obiektu()
{
	ostringstream stream;
	stream << *this;
	return stream.str();
}

void Silownia::odczytaj(ifstream & s)
{
	s >> *this;
}

void Silownia::edytuj()
{
	int wiek, cena;
	string str,imie,nazwisko;
	str = "0";
	string str2 = "0";
	do
	{
		switch (stoi(str))
		{
		case 0:
			cout << "Edycja silowni " << nazwa << endl;
			wyswietl();
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Dodaj klienta" << endl;
			cout << "2: Usun klienta" << endl;
			cout << "3: Ustaw trenera EASY" << endl;
			cout << "4: Ustaw trenera EXPERT" << endl;
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
				cout << "Podaj ID klienta z bazy danych <100-110> : ";
				getline(cin, str);
			} while (!stoigood(str));
			klient_wchodzi(stoi(str));

			str = "0";
			break;
		case 2:
			system("cls");

			do
			{
				cout << endl;
				cout << "Podaj ID klienta z silowni: ";
				getline(cin, str);
			} while (!stoigood(str));
			klient_wychodzi(stoi(str));

			str = "0";
			break;
		case 3:
			system("cls");

			
				cout << "Podaj imie Trenera EASY : ";
				getline(cin, str);
				imie = str;

				cout << "Podaj nazwisko Trenera EASY : ";
				getline(cin, str);
				nazwisko = str;

				do
				{
					cout << endl;
					cout << "Podaj wiek Trenera EASY : ";
					getline(cin, str);
				} while (!stoigood(str));
				wiek=(stoi(str));

				do
				{
					cout << endl;
					cout << "Podaj cene Trenera EASY : ";
					getline(cin, str);
				} while (!stoigood(str));
				cena = (stoi(str));

				this->trener1.wprowadz_dane_osobowe(imie, nazwisko, wiek);
				this->trener1.ustaw_cene(cena);

			

			str = "0";
			break;
		case 4:
			system("cls");
			cout << "Podaj imie Trenera EXPERT : ";
			getline(cin, str);
			imie = str;

			cout << "Podaj nazwisko Trenera EXPERT : ";
			getline(cin, str);
			nazwisko = str;

			do
			{
				cout << endl;
				cout << "Podaj wiek Trenera EXPERT : ";
				getline(cin, str);
			} while (!stoigood(str));
			wiek = (stoi(str));

			do
			{
				cout << endl;
				cout << "Podaj cene Trenera EXPERT : ";
				getline(cin, str);
			} while (!stoigood(str));
			cena = (stoi(str));

			this->trener2.wprowadz_dane_osobowe(imie, nazwisko, wiek);
			this->trener2.ustaw_cene(cena);
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

void Silownia::klient_wchodzi(int id)
{
		vector_klientow.push_back(new Klient(id));
		vector_klientow[vector_klientow.size()-1]->ustal_dane_osobowe();
}

void Silownia::klient_wychodzi(int id)
{
	for (int i = 0; i < vector_klientow.size(); i++)
	{
		if (vector_klientow[i]->daj_id() == id)
		{
			Silownia::dodaj_do_zarobek(vector_klientow[i]->daj_rachunek());
			//tutaj trzeba dodac rachunek z silowni do calosciowego rachunku klienta z pobytu w kurorcie.
			delete vector_klientow[i];
			vector_klientow.erase(vector_klientow.begin()+i);
			break;
		}
	}
}

void Silownia::ustaw_powierzchnie(int x)
{
	powierzchnia_m2 = x;
}

void Silownia::wyczysc_klienci()
{

	for (int i = 0; i < vector_klientow.size(); i++)
	{
		delete vector_klientow[i];
	}
	vector_klientow.clear();
}

int Silownia::ile_silowni()
{
	return Silownia::liczba_silowni;
}

int Silownia::ile_dzialajacych_silowni()
{
	return Silownia::liczba_dzialajacych_silowni;
}

void Silownia::dodaj_do_zarobek(int x)
{
	Silownia::zarobek += x;
}

int Silownia::ile_zarobione()
{
	return Silownia::zarobek;
}

void Silownia::wyswietl_klientow()
{
	cout << "###### AKTUALNIE W SILOWNI " << this->nazwa << " przebywa " << this->vector_klientow.size() << " klientow ##########" << endl;
	for (int i = 0; i < this->vector_klientow.size(); i++)
	{
		vector_klientow[i]->wyswietl_dane_klienta();
	}
	cout << "#################################################" << endl;
}

bool Silownia::operator==(const Silownia & s)
{
	if (nazwa == s.nazwa&&lokalizacja == s.lokalizacja)
		return true;
	else
		return false;
}

Silownia& Silownia::operator=(const Silownia & s)
{
	
	wyczysc_klienci();
	nazwa = s.nazwa;
	lokalizacja = s.lokalizacja;
	powierzchnia_m2 = s.powierzchnia_m2;
	trener1 = s.trener1;
	trener2 = s.trener2;
	bieznia1 = s.bieznia1;
	bieznia2 = s.bieznia2;
	bieznia3 = s.bieznia3;
	bieznia4 = s.bieznia4;

	
	for (int i = 0; i < s.vector_klientow.size(); i++)
	{
		vector_klientow.push_back(s.vector_klientow[i]);
	}
	return *this;
}

Silownia::operator int() const
{
	return this->vector_klientow.size();
}

int Silownia::operator[](int i)
{
	switch (i)
	{
	case 1:
		return bieznia1.daj_cene();
	case 2:
		return bieznia2.daj_cene();
	case 3:
		return bieznia3.daj_cene();
	case 4:
		return bieznia4.daj_cene();

	default:
		cout << "ZLY NUMER ZWRACAM -1" << endl;
		return -1;
		break;

	}
}

ostream & operator<<(ostream & s, Silownia & silownia)
{
	s << (Obiekt_sportowy&)silownia;
	//s << "//Strumien z Basenu" << endl << "dlugosc=" << basen.dlugosc << endl << "szerokosc=" << basen.szerokosc << endl << "glebokosc=" << basen.glebokosc << endl << "temperatura_wody=" << basen.temperatura_wody << endl << "cena_wejscia=" << basen.cena_wejscia << endl;
	s << silownia.powierzchnia_m2 << endl;
	s << silownia.trener1;
	s << silownia.trener2;
	s << silownia.bieznia1;
	s << silownia.bieznia2;
	s << silownia.bieznia3;
	s << silownia.bieznia4;
	s <<"KLIENCI "<< silownia.vector_klientow.size()<<endl;
	for (int i = 0; i < silownia.vector_klientow.size(); i++)
	{	
		s << *(silownia.vector_klientow[i]);
	}
	
	return s;
}

istream & operator>>(istream & s, Silownia & silownia)
{
	string str;
	s >> (Obiekt_sportowy&)silownia;
	s >> silownia.powierzchnia_m2;
	s >> silownia.trener1;
	s >> silownia.trener2;
	s >> silownia.bieznia1;
	s >> silownia.bieznia2;
	s >> silownia.bieznia3;
	s >> silownia.bieznia4;
	s >> str >> str; //Odczytanie liczby klientow
	silownia.wyczysc_klienci();
	for (int i = 0; i < stoi(str); i++)
	{	
		silownia.klient_wchodzi(i);//tworzymy klienta
		s >> *(silownia.vector_klientow[i]);//uzupelniamy dane klienta ze strumienia
	}

	return s;
}
