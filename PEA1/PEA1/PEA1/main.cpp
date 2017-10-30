//#include "stdafx.h"
#include <iostream>
#include <Windows.h>

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
