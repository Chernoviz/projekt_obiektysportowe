#pragma once
#include <string>
using namespace std;
class Bieznia{
public:
	Bieznia(int numer,string marka,int cena);
	~Bieznia();
	

private:
	int numer_seryjny;
	string marka;
	int cena_za_minute;
public:
	
	friend ostream& operator << (ostream &s, Bieznia &bieznia);
	friend istream& operator >> (istream &s, Bieznia &bieznia);

	string daj_dane();
	int daj_cene();
	string daj_marka();
	int daj_numer_seryjny();
	Bieznia& operator++(int);
	Bieznia& operator--(int);
	
	

};