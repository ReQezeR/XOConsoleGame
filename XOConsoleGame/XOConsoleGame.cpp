#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void generuj(char **temp)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = '_';
		}
	}
}

void wyswietl(char **temp)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " [ " << temp[i][j] << " ] ";
		}
		cout << endl;
	}
}

int sprawdzI(int t)
{
	int p = t + '0';
	//cout << "Sprawdzam : p =" << p << endl;
	if (p >= 55 && p <= 57) { return 0; }
	else if (p >= 52 && p <= 54) { return 1; }
	else if (p >= 49 && p <= 51) { return 2; }
	else return 0;
}// ustala wspolrzedne I

int sprawdzJ(int t)
{
	int p = t + '0';
	//cout << "Sprawdzam : p =" << p << endl;
	if (p == 55 || p == 52 || p == 49) { return 0; }
	else if (p == 56 || p == 53 || p == 50) { return 1; }
	else if (p == 57 || p == 54 || p == 51) { return 2; }
}//ustala wspolrzedne J

bool czyZajete(int pole, char **temp)
{
	int i = 0, j = 0;
	i = sprawdzI(pole);
	j = sprawdzJ(pole);
	if (temp[i][j] == '_') { return false; }
	else { return true; }
} //sprawdza czy pole jest zajete ( 0 / 1 )

int czekaj(char **t)
{
	int p = 0;
	char w;

	while (true)
	{
		if (_kbhit())
		{
			w = _getch();
			p = w - '0';
			if (p >= 1 && p <= 9 && czyZajete(p, t) == false)
			{
				break;
			}
		}
	}
	return p;
}

bool rozwiazanie(char **Plansza, char &winner)
{
	if (Plansza[0][0] == Plansza[1][1] && Plansza[1][1] == Plansza[2][2] && Plansza[1][1] != '_')//pierwsza przekatna
	{
		//cout << "pierwsza przekatna" << endl;
		if (Plansza[1][1] == 'X') { winner = 'X'; }
		else if (Plansza[1][1] == 'X') { winner = 'O'; }
		return true;
	}

	else if (Plansza[2][0] == Plansza[1][1] && Plansza[1][1] == Plansza[0][2] && Plansza[1][1] != '_')//druga przekatna
	{
		//cout << "druga przekatna" << endl;
		if (Plansza[1][1] == 'X') { winner = 'X'; }
		else if (Plansza[1][1] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[0][0] == Plansza[0][1] && Plansza[0][1] == Plansza[0][2] && Plansza[0][1] != '_')// gora D
	{
		//cout << "gora" << endl;
		if (Plansza[0][1] == 'X') { winner = 'X'; }
		else if (Plansza[0][1] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[2][0] == Plansza[2][1] && Plansza[2][1] == Plansza[2][2] && Plansza[2][1] != '_')// dol
	{
		//cout << "dol" << endl;
		if (Plansza[2][1] == 'X') { winner = 'X'; }
		else if (Plansza[2][1] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[0][0] == Plansza[1][0] && Plansza[1][0] == Plansza[2][0] && Plansza[1][0] != '_')// lewo
	{
		//cout << "lewo" << endl;
		if (Plansza[1][0] == 'X') { winner = 'X'; }
		else if (Plansza[1][0] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[0][2] == Plansza[1][2] && Plansza[1][2] == Plansza[2][2] && Plansza[1][2] != '_')// prawo
	{
		//cout << "prawo" << endl;
		if (Plansza[1][2] == 'X') { winner = 'X'; }
		else if (Plansza[1][2] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[0][1] == Plansza[1][1] && Plansza[1][1] == Plansza[2][1] && Plansza[1][1] != '_')// pion
	{
		//cout << "pion" << endl;
		if (Plansza[1][1] == 'X') { winner = 'X'; }
		else if (Plansza[1][1] == 'O') { winner = 'O'; }
		return true;
	}

	else if (Plansza[1][0] == Plansza[1][1] && Plansza[1][1] == Plansza[1][2] && Plansza[1][1] != '_')// poziom
	{
		//cout << "poziom" << endl;
		if (Plansza[1][1] == 'X') { winner = 'X'; }
		else if (Plansza[1][1] == 'O') { winner = 'O'; }
		return true;
	}

	else { return false; }
}

void rozgrywka(char **temp)
{
	int p = 0, i = 0, j = 0;
	char winer = 'R';
	cout << "======================" << endl << "=   Ruch  :   = [ O ] " << endl << "======================" << endl;
	wyswietl(temp);
	cout << "======================" << endl;

	for (int timer = 1; timer <= 9; timer++)
	{
		if (timer > 5) { if (rozwiazanie(temp, winer) == true) break; }

		if ((timer + 1) % 2 == 0)
		{
			p = czekaj(temp);
			i = sprawdzI(p);
			j = sprawdzJ(p);
			temp[i][j] = 'O';
			system("cls");
			cout << "======================" << endl << "=   Ruch  :   = [ X ] " << endl << "======================" << endl;
			wyswietl(temp);
			cout << "======================" << endl;
		}

		else
		{
			p = czekaj(temp);
			i = sprawdzI(p);
			j = sprawdzJ(p);
			temp[i][j] = 'X';
			system("cls");
			cout << "======================" << endl << "=   Ruch  :   = [ O ] " << endl << "======================" << endl;
			wyswietl(temp);
			cout << "======================" << endl;
		}

		if (timer == 9) { if (rozwiazanie(temp, winer) == true) break; }
	}
	system("cls");
	if (winer != 'R')
	{
		cout << "======================" << endl << "=     GRATULACJE     =" << endl << "=     Wygral : " << winer << "     = " << endl << "======================" << endl;
	}
	else { cout << "======================" << endl << "=        Remis       = " << endl << "======================" << endl; }
	wyswietl(temp);
	cout << "======================" << endl;
}

int main()
{
	bool czyKoniec = false;
	char **Plansza = new char *[3];
	for (int i = 0; i < 3; i++) { Plansza[i] = new char[3]; }
	while (true)
	{
		generuj(Plansza);
		rozgrywka(Plansza);
		getchar();
		system("cls");
	}
	getchar();
	return 0;
}

