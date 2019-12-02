#pragma once
#include "dbg.h"
#include "trener.h"
#include "silownia.h"
#include "bieznia.h"
#include "klient.h"
#include "silownia_test.h"
#include "obiekt_sportowy.h"
#include "basen.h"
#include "basen_sauna.h"
#include <vector>
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<time.h>

class Program {
public:
	vector <Obiekt_sportowy*> obiekty;

	Basen *ptr_b;
	Basen_sauna *ptr_bs;
	Silownia *ptr_s;
	void test();
	void interfejs();
private:
	void zapis_kolekcji();
	void odczyt_kolekcji();
	void wyswietl_kolekcje();
	void testowa_kolekcja();
	void usun_obiekt();
	bool stoigood(string s);
	void dodaj_basen();
	void dodaj_basen_sauna();
	void dodaj_silownia();
	void edytuj_obiekt();
	void wyswietl_cenniki();

	
};