#include "program.h"
#include<stdlib.h>
#include<time.h>

void Program::test()
{
	testowa_kolekcja();	
	obiekty[0]->wyswietl();
	Basen *ptr_b;
	ptr_b = (Basen*)obiekty[0];
	ptr_b->ustaw_cene(5);
	ptr_b->ustaw_temp(50);
	obiekty[0]->wyswietl();
}

void Program::zapis_kolekcji()
{
	cout << "*****************Zapis Kolekcji ********************************************" << endl;
	ofstream plikzapisu("KOLEKCJA_OBIEKTOW.txt");
	for (int i = 0; i < static_cast<int>(obiekty.size()); i++)
	{
		plikzapisu << obiekty[i]->daj_stan_obiektu();
		cout << "Zapisano do pliku kolekcji obiekt " << obiekty[i]->daj_nazwa() << endl;
	}
	plikzapisu.close();
	cout << "-----------------------------------------------------" << endl;
}

void Program::odczyt_kolekcji()
{
	
	string str;
	ifstream plik("KOLEKCJA_OBIEKTOW.txt");
	//int j = 0;
	if (plik.is_open())
	{
		for (int i = 0; i < obiekty.size(); i++)
		{
			delete obiekty[i];
		}
		obiekty.clear();

		while (!plik.eof())
		{
			plik >> str;
			if (str[0] == '/' and str[1] == '/' and str[2] == '-')  //znacznik pocz¹tku obiektu 
			{
				plik >> str;
				if (str == "Basen")  // sprawdzenie zgodnoœci typu
				{
					obiekty.push_back(new Basen(0, "B", "BRAK", 0, 0, 0, 0));
					obiekty[obiekty.size() - 1]->odczytaj(plik);
				}
				if (str == "Basen_sauna")  // sprawdzenie zgodnoœci typu
				{
					obiekty.push_back(new Basen_sauna(0, "BS", "BRAK", 0, 0, 0, 0, 0));
					obiekty[obiekty.size() - 1]->odczytaj(plik);
				}
				if (str == "Silownia")  // sprawdzenie zgodnoœci typu
				{
					obiekty.push_back(new Silownia(0, "S", "BRAK"));
					obiekty[obiekty.size() - 1]->odczytaj(plik);
				}

			}
		}
		cout << endl;
		cout << "  ODCZYTANO KOLEKCJIE! Liczba obiektow: " << obiekty.size()<< endl;
		cout << endl;
		plik.close();
	}
	else
	{
		cout << "Blad odczytu!!!. Nie mozna otworzyc pliku: KOLEKCJA_OBIEKTOW.txt" << endl;
	}
}

void Program::wyswietl_kolekcje()
{
	cout << "------------KOLEKCJA-------------------" << endl;
	for (int i = 0; i < obiekty.size(); i++)
	{
		obiekty[i]->wyswietl();
	}
	cout << "---------------------------------------" << endl;
}

void Program::testowa_kolekcja() {

	Basen *ptr_b1 = new Basen(1, "Basen Maly Delfinek", "Legionowo", 30, 50, 20, 2);
	ptr_b1->ustaw_cene(20);
	ptr_b1->ustaw_temp(15);
	Obiekt_sportowy *ptr_osb1 = ptr_b1;

	Basen_sauna *ptr_bs2 = new Basen_sauna(2, "Basen z Sauna Goracy Pingwin", "Szczecin", 40, 100, 30, 3, 15);
	ptr_bs2->ustaw_cene(18);
	ptr_bs2->ustaw_cene_sauny(5);
	ptr_bs2->ustaw_temp(20);
	ptr_bs2->ustaw_temp_sauny(100);
	Obiekt_sportowy *ptr_osbs2 = ptr_bs2;

	Silownia *ptr_s3 = new Silownia(3, "Mario GYM", "Warszawa");
	ptr_s3->klient_wchodzi(101);
	ptr_s3->klient_wchodzi(102);
	ptr_s3->klient_wchodzi(103);
	Obiekt_sportowy *ptr_oss3 = ptr_s3;

	obiekty.push_back(ptr_osb1);
	obiekty.push_back(ptr_osbs2);
	obiekty.push_back(ptr_oss3);
	obiekty.push_back(new Basen(4, "Basen Zrebaczek", "Gdansk", 20, 50, 30, 2));
	obiekty.push_back(new Basen_sauna(5, "Basen sauna hot Papa", "Sosnowiec", 15, 55, 32, 2, 70));
	obiekty.push_back(new Silownia(6, "Zdrofit", "Krakow"));
}

void Program::usun_obiekt()
{
	string id;
	cout << endl;
	cout << "Podaj ID obiektu do usuniecia: ";
	getline(cin, id);
	try
	{
		stoi(id);
	}
	catch (const invalid_argument& ia)
	{
		cout << '\a';
		id = "BLAD";
	}
	if (id != "BLAD")
	{
		for (int i = 0; i < obiekty.size(); i++)
		{
			if (obiekty[i]->daj_id() == stoi(id)) // usuwanie obiektu na podstawie jego ID
			{
				delete obiekty[i];
				obiekty.erase(obiekty.begin() + i);
				cout << endl;
				cout << "Usuwanie powiodlo sie" << endl;
				cout << endl;
				id = "SUKCES";
				break;
			}
		}
		if (id != "SUKCES")
		{
			cout << endl;
			cout << "Nie znaleziono takiego obiektu" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "Nie poprawny format ID" << endl;
		cout << endl;
	}
}

bool Program::stoigood(string s)
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

void Program::dodaj_basen()
{
	string str = "a";
	int id, max_osob,dlugosc, szerokosc, glebokosc, temperatura_wody, cena_wejscia;
	string nazwa, lokalizacja;
	
	do
	{
		cout << endl;
		cout << "Podaj ID nowego basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	id = stoi(str);
	

	cout << endl << endl;
	cout << "Podaj nazwe nowego basenu: ";
	getline(cin, str);
	nazwa = str;

	cout << endl << endl;
	cout << "Podaj lokalizacje basenu "<<nazwa<<": ";
	getline(cin, str);
	lokalizacja = str;

	do
	{
		cout << endl<<endl;
		cout << "Podaj dopuszczalna liczbe osob w basenie: ";
		getline(cin, str);
	} while (!stoigood(str));
	max_osob = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj dlugosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	dlugosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj szerokosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	szerokosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj glebokosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	glebokosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj temperature wody: ";
		getline(cin, str);
	} while (!stoigood(str));
	temperatura_wody = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj cene wejscia na basen: ";
		getline(cin, str);
	} while (!stoigood(str));
	cena_wejscia = stoi(str);

	obiekty.push_back(new Basen(id, nazwa, lokalizacja, max_osob, dlugosc, szerokosc, glebokosc));
	ptr_b = (Basen*)obiekty.back();
	ptr_b->ustaw_temp(temperatura_wody);
	ptr_b->ustaw_cene(cena_wejscia);
	ptr_b = nullptr;
}

void Program::dodaj_basen_sauna()
{
	string str = "a";
	int id, max_osob, dlugosc, szerokosc, glebokosc,temperatura_wody,cena_wejscia,powierzchnia,cena_sauny, temperatura_sauna;
	string nazwa, lokalizacja;

	do
	{
		cout << endl;
		cout << "Podaj ID nowego basenu z sauna: ";
		getline(cin, str);
	} while (!stoigood(str));
	id = stoi(str);


	cout << endl << endl;
	cout << "Podaj nazwe nowego basenu: ";
	getline(cin, str);
	nazwa = str;

	cout << endl << endl;
	cout << "Podaj lokalizacje basenu " << nazwa << ": ";
	getline(cin, str);
	lokalizacja = str;

	do
	{
		cout << endl << endl;
		cout << "Podaj dopuszczalna liczbe osob w basenie: ";
		getline(cin, str);
	} while (!stoigood(str));
	max_osob = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj dlugosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	dlugosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj szerokosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	szerokosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj glebokosc basenu: ";
		getline(cin, str);
	} while (!stoigood(str));
	glebokosc = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj temperature wody: ";
		getline(cin, str);
	} while (!stoigood(str));
	temperatura_wody = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj cene wejscia na basen: ";
		getline(cin, str);
	} while (!stoigood(str));
	cena_wejscia = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj powierzchnie sauny: ";
		getline(cin, str);
	} while (!stoigood(str));
	powierzchnia = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj cene za godziny sauny: ";
		getline(cin, str);
	} while (!stoigood(str));
	cena_sauny = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj temperature sauny: ";
		getline(cin, str);
	} while (!stoigood(str));
	temperatura_sauna = stoi(str);

	obiekty.push_back(new Basen_sauna(id, nazwa, lokalizacja, max_osob, dlugosc, szerokosc, glebokosc,powierzchnia));
	ptr_bs = (Basen_sauna*)obiekty.back();
	ptr_bs->ustaw_temp(temperatura_wody);
	ptr_bs->ustaw_cene(cena_wejscia);
	ptr_bs->ustaw_cene_sauny(cena_sauny);
	ptr_bs->ustaw_temp_sauny(temperatura_sauna);
	ptr_bs = nullptr;

}

void Program::dodaj_silownia()
{
	string str = "a";
	int id, max_osob, powierzchnia_m2;
	string nazwa, lokalizacja;

	do
	{
		cout << endl;
		cout << "Podaj ID nowej silowni: ";
		getline(cin, str);
	} while (!stoigood(str));
	id = stoi(str);


	cout << endl << endl;
	cout << "Podaj nazwe nowej silowni: ";
	getline(cin, str);
	nazwa = str;

	cout << endl << endl;
	cout << "Podaj lokalizacje silowni " << nazwa << ": ";
	getline(cin, str);
	lokalizacja = str;

	do
	{
		cout << endl << endl;
		cout << "Podaj dopuszczalna liczbe osob w silowni: ";
		getline(cin, str);
	} while (!stoigood(str));
	max_osob = stoi(str);

	do
	{
		cout << endl << endl;
		cout << "Podaj powierzchnie silowni [m2]: ";
		getline(cin, str);
	} while (!stoigood(str));
	powierzchnia_m2 = stoi(str);

	obiekty.push_back(new Silownia(id, nazwa, lokalizacja));
	ptr_s = (Silownia*)obiekty.back();
	ptr_s->ustaw_powierzchnie(powierzchnia_m2);
	ptr_s = nullptr;
}

void Program::edytuj_obiekt()
{
	string id;
	cout << endl;
	cout << "Podaj ID obiektu do edycji: ";
	getline(cin, id);
	try
	{
		stoi(id);
	}
	catch (const invalid_argument& ia)
	{
		cout << '\a';
		id = "BLAD";
	}
	if (id != "BLAD")
	{
		for (int i = 0; i < obiekty.size(); i++)
		{
			if (obiekty[i]->daj_id() == stoi(id)) // edycja obiektu na podstawie jego ID
			{
				obiekty[i]->edytuj();
				cout << endl;
				id = "SUKCES";
				break;
			}
		}
		if (id != "SUKCES")
		{
			cout << endl;
			cout << "Nie znaleziono takiego obiektu" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "Nie poprawny format ID" << endl;
		cout << endl;
	}
}

void Program::wyswietl_cenniki()
{
	cout << "------------CENNIKI-------------------" << endl;
	for (int i = 0; i < obiekty.size(); i++)
	{
		cout<<obiekty[i]->daj_cennik()<<endl;
	}
	cout << "---------------------------------------" << endl;
}

void Program::interfejs()
{
	
	string str;
	str = "0";
	string str2 = "0";
    do
	{
		switch (stoi(str))
		{
		case 0:
			cout << "MENU PROGRAMU" << endl;
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Wyswietl kolekcje" << endl;
			cout << "2: Dodaj obiekt" << endl;
			cout << "3: Usun obiekt" << endl;
			cout << "4: Zapisz kolekcje" << endl;
			cout << "5: Otworz kolekcje" << endl;
			cout << "6: Edytuj obiekt" << endl;
			cout << "7. Wyswietl cenniki" << endl;
			cout << "9: Zamknij program" << endl;
			cout << "-------------------------------" << endl;
			cout << "Opcja: ";
			getline(cin,str);
			try 
			{ 
				stoi(str); 
			}
			catch (const invalid_argument& ia) 
			{
				std::cerr << "Invalid argument: " << ia.what() << '\n'; 
				cout << '\a';
				str = "100";
				break;
			}
			break;
		case 1:
			system("cls");
			if (obiekty.size() == 0)
			{
				cout << endl;
				cout << "Kolekcja jest pusta!" << endl;
				cout << endl;
			}
			else
			{
				wyswietl_kolekcje();
			}
			str = "0";
			break;
		case 2:
			system("cls");
			do
			{
				switch (stoi(str2))
				{
				case 0:
					cout << "MENU DODAWANIA OBIEKTOW SPORTOWYCH" << endl;
					cout << "-------------------------------" << endl;
					cout << "Wybierz opcje:" << endl;
					cout << "1: Dodaj Basen" << endl;
					cout << "2: Dodaj Basen z sauna" << endl;
					cout << "3: Dodaj Silownie" << endl;
					cout << "4: Dodaj przykladowe obiekty" << endl;
					cout << "9: Wstecz" << endl;
					cout << "-------------------------------" << endl;
					cout << "Opcja: ";
					getline(cin, str2);
					try
					{
						stoi(str2);
					}
					catch (const invalid_argument& ia)
					{
						std::cerr << "Invalid argument: " << ia.what() << '\n';
						cout << '\a';
						str = "2";
						str2 = "10";
						break;
					}
					break;
				case 1:
					system("cls");
					dodaj_basen();
					str2 = "0";
					break;
				case 2:
					system("cls");
					dodaj_basen_sauna();
					str2 = "0";
					break;
				case 3:
					system("cls");
					dodaj_silownia();
					str2 = "0";
					break;
				case 4:
					system("cls");
					cout << endl;
					cout << "Dodano testowe obiekty" << endl<<endl;
					testowa_kolekcja();
					str2 = "10";
					str = "0";
					break;
				case 9:
					system("cls");
					str = "0";
					str2 = "10";
					break;
				default:
					system("cls");
					str2 = "0";
					break;
				
				}
			} while (stoi(str2)!=10);
			break;

		case 3:
			system("cls");
			usun_obiekt();
			str = "0";
			break;
		case 4:
			system("cls");
			zapis_kolekcji();
			str = "0";
			break;
		case 5:
			system("cls");
			odczyt_kolekcji();
			str = "0";
			break;
		case 6:
			system("cls");
			edytuj_obiekt();
			str = "0";
			break;
		case 7:
			system("cls");
			wyswietl_cenniki();
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

