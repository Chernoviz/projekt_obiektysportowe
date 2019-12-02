#define _SILOWNIA_TEST
#include "silownia_test.h"
#include <iostream>
using namespace std;
void Silownia_test::testuj_silownie()
{
	cout << "################ START ####################" << endl;
	Silownia s1;
	cout << "------------S2-------------" << endl;
	Silownia s2(5,"ZDROFIT", "Legionowo");
	s2.klient_wchodzi(102);
	s2.klient_wchodzi(103);
	s2.klient_wchodzi(104);
	s2.klient_wchodzi(107);
	s2.wyswietl_klientow();

	cout << "-------------S3------------" << endl;
	cout << "Ilosc silowni: " << Silownia::ile_dzialajacych_silowni() << endl;
	Silownia s3(s2);
	cout << "Ilosc silowni: " << Silownia::ile_dzialajacych_silowni() << endl;
	cout << "---------- -usuwam z s2 klientow--------------" << endl;
	s2.klient_wychodzi(103);
	s2.klient_wychodzi(107);
	cout << "------------S2-------------" << endl;
	s2.wyswietl_klientow();
	cout << "------------S3-------------" << endl;
	s3.wyswietl_klientow();
	cout << "------------ int(silownia) -------------" << endl;
	cout << "Ilosc klientow w s2 poprzez konwersje: " << int(s2) << endl;
	cout << "Ilosc klientow w s3 poprzez konwersje: " << int(s3) << endl;
	cout << "------------ (test przeciazenia operatora indeksowania)Cena za minute biezni w s2 to: -------------" << endl;
	cout << "Bieznia1: " << s2[1] << endl;
	cout << "Bieznia2: " << s2[2] << endl;
	cout << "Bieznia3: " << s2[3] << endl;
	cout << "Bieznia4: " << s2[4] << endl;
	cout << "------------s 2=s3 -------------" << endl;
	s2 = s3;
	s2.wyswietl_klientow();
	

	cout << "################ KONIEC ####################" << endl;
}
