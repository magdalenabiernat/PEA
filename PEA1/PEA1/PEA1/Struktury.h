#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct obiekt
{
	long int warto��;
	double waga;
	double stosunek;
	int indeks;
};

struct wezel
{
	long int zysk;
	long int poziom;
	long int granica;
	double waga;
	vector <bool> decyzja;
};

