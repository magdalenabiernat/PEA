#include "Plecak.h"


void Plecak::wyswietl()
{
	cout << "Waga | Wartosc\n";
	for (i = 0; i<num_obj; i++)
	{
		cout << endl << setw(6) << tab[i].waga << setw(8) << tab[i].wartoœæ;
	}
	cout << endl << endl;
}

Plecak::Plecak()
{
}


Plecak::~Plecak()
{
}
