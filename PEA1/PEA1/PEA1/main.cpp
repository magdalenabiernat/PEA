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
		return a.warto�� > b.warto��;
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
		szacowanaWartosc += plecak[nastepnyPoziom].warto��;
		nastepnyPoziom++;
	}
	if (nastepnyPoziom < obiekty)
	{
		szacowanaWartosc += (pojemnosc - calkowitaWaga)*(plecak[nastepnyPoziom].warto�� / plecak[nastepnyPoziom].waga);
	}
	return szacowanaWartosc;
}

int main()
{
	//do pomiaru czasu ze strony
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	performanceCountStart = startTimer(); //zapami�tujemy czas pocz�tkowy
	Sleep(2000); //tutaj funkcje, kt�rych mierzymy wydajno��
	performanceCountEnd = endTimer(); //zapami�tujemy koniec czasu
	double tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
	cout << endl << "Time:" << tm << " s" << endl;

	system("pause");
}
