#pragma once
#include "Struktury.h"
#include <iostream>
#include <iomanip> 
#include <fstream>

class Plecak
{
public:
	int pojemnosc, num_obj, i;		// pojemnoœæ plecaka i iloœæ przedmiotów
	int naj_wartoœæ, naj_waga;	// tutaj bêdziemy zapisywaæ dane najlepszego jak do tej pory set'u
	int aktualna_waga, aktualna_wartosc;					// wartoœæ i waga aktualnie badanego set'u
	int temp;
	int *naj_³up;
	int *aktualny_³up;
	obiekt *tab;				// tworzymy tablicê struktur, ka¿dy element struktury to waga i wartoœæ przedmiotu
	void czytaj_z_pliku(string nazwa_pliku);
	void wyswietl();
	void zupelny();
	void tworz_losowo();

	Plecak();
	~Plecak();
};

