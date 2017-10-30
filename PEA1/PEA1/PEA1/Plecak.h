#pragma once
#include "Struktury.h"
#include <iostream>
#include <iomanip> 
#include <fstream>

class Plecak
{
public:
	int pojemnosc, num_obj, i;		// pojemno�� plecaka i ilo�� przedmiot�w
	int naj_warto��, naj_waga;	// tutaj b�dziemy zapisywa� dane najlepszego jak do tej pory set'u
	int aktualna_waga, aktualna_wartosc;					// warto�� i waga aktualnie badanego set'u
	int temp;
	int *naj_�up;
	int *aktualny_�up;
	obiekt *tab;				// tworzymy tablic� struktur, ka�dy element struktury to waga i warto�� przedmiotu
	void czytaj_z_pliku(string nazwa_pliku);
	void wyswietl();
	void zupelny();
	void tworz_losowo();

	Plecak();
	~Plecak();
};

