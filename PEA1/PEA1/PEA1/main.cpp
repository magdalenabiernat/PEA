//#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Struktury.h"

using namespace std;

//funkcje pomiaru czasu ze strony
LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

bool porownanie(obiekt a, obiekt b)
{
	if (a.stosunek == b.stosunek)
		return a.wartoœæ > b.wartoœæ;
	return a.stosunek > b.stosunek;
}

int maxWartosc(vector<obiekt>&plecak, wezel u, int obiekty, int  pojemnosc)
{
	if (u.waga >= pojemnosc)
		return 0;
	int szacowanaWartosc = u.zysk;
	int nastepnyPoziom = u.poziom + 1;
	int calkowitaWaga = u.waga;
	while ((nastepnyPoziom < obiekty) && (calkowitaWaga + plecak[nastepnyPoziom].waga <= pojemnosc))
	{
		calkowitaWaga += plecak[nastepnyPoziom].waga;
		szacowanaWartosc += plecak[nastepnyPoziom].wartoœæ;
		nastepnyPoziom++;
	}
	if (nastepnyPoziom < obiekty)
	{
		szacowanaWartosc += (pojemnosc - calkowitaWaga)*(plecak[nastepnyPoziom].wartoœæ / plecak[nastepnyPoziom].waga);
	}
	return szacowanaWartosc;
}

int main()
{
	//do pomiaru czasu ze strony
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
	Sleep(2000); //tutaj funkcje, których mierzymy wydajnoœæ
	performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
	double tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
	cout << endl << "Time:" << tm << " s" << endl;

	system("pause");
}
