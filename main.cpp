#include <iostream>
#include <conio.h>
#define _DBG
//#define _SILOWNIA_TEST
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
#include "program.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
#ifdef _SILOWNIA_TEST
	Silownia_test::testuj_silownie();
#endif
	Program p;
	p.interfejs();
	return 0;
}
