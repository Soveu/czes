#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "gamefunc.h"
using namespace std;

string plansza[8][8]; //moze zmieniac sie w zaleznosci od robionych ruchow
string kopia[8][8]; //niezmienia swojego utawienia od poczatku gry do konca
int uklad=0; //jezeli uklad=0 to biale figury sa na dole planszy, w przeciwnym przypadku sa na gorze
bool bicieK[8]; //tablica,ktora zawiera pola wokol krola czarnego, 0-gdy pole nie jest bite, 1-gdy pole jest bite
void printboard(string tab[8][8]) //wpisywanie do tablicy struktur planszy
{
	figura board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tab[i][j] == " ")
			{
				board[7-i][j].fig = ' ';
				board[7-i][j].tim = -1;
			}
			else if (tab[i][j] == "P" || tab[i][j] == "R" || tab[i][j] == "B" || tab[i][j] == "N" || tab[i][j] == "Q" || tab[i][j] == "K")
			{
				board[7-i][j].fig = tab[i][j][0];
				board[7-i][j].tim = 2;
			}
			else if (tab[i][j] == "p")
			{
				board[7-i][j].fig = 'P';
				board[7-i][j].tim = 1;
			}
			else if (tab[i][j] == "r")
			{
				board[7-i][j].fig = 'R';
				board[7-i][j].tim = 1;
			}
			else if (tab[i][j] == "b")
			{
				board[7-i][j].fig = 'B';
				board[7-i][j].tim = 1;
			}
			else if (tab[i][j] == "n")
			{
				board[7-i][j].fig = 'N';
				board[7-i][j].tim = 1;
			}
			else if (tab[i][j] == "q")
			{
				board[7-i][j].fig = 'Q';
				board[7-i][j].tim = 1;
			}
			else if (tab[i][j] == "k")
			{
				board[7-i][j].fig = 'K';
				board[7-i][j].tim = 1;
			}
		}
	}
	printBoard(board, uklad+1 /*1==biale 0==czarne*/);
}
void gra(string szachy[8][8], int liczbarand) //opcja druga reneruje losowo gre jedna z dziesieciu
{
	switch (liczbarand)
	{
		case 1:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j]=" ";
				}
			}
			szachy[0][4]="K"; //czarny krol
			szachy[2][3] = "n"; //bialy skoczek
			szachy[4][0] = "p"; //bialy pionek
			szachy[1][0] = "r"; //biala wieza
			szachy[6][6] = "k"; //bialy krol
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'a' || (ruch[1] - 48) != 7 || ruch[2] != 'e' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 2:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][5] = "K"; //czarny krol
			szachy[5][7] = "r"; //biala wieza
			szachy[4][0] = "p"; //bialy pionek
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 3 || ruch[2] != 'h' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 3:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[2][3] = "K"; //czarny krol
			szachy[3][3] = "n"; //bialy skoczek
			szachy[4][3] = "k"; //bialy krol
			szachy[4][7] = "q"; //biala krolowa
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 4 || ruch[2] != 'd' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 4:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][2] = "R"; //czarna wieza
			szachy[0][3] = "K"; //czarny krol
			szachy[0][4] = "R"; //czarna wieza
			szachy[5][6] = "q"; //biala krolowa
			szachy[6][6] = "k"; //bialy krol
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'g' || (ruch[1] - 48) != 3 || ruch[2] != 'd' || (ruch[3] - 48) != 6 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 5:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][6] = "R"; //czarna wieza
			szachy[0][7] = "K"; // czarny krol
			szachy[1][6] = "P"; //czarny pionek
			szachy[2][6] = "q"; //biala krolowa
			szachy[6][6] = "k"; //bialy krol
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'g' || (ruch[1] -48)!= 6 || ruch[2] != 'h' || (ruch[3]-48) != 5 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if(ruch!="exit")
				cout << "WYGRANA";
		}break;
		case 6:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[2][3] = "K"; //CK czarny krol
			szachy[0][3] = "b"; //CG czarny skoczek
			szachy[0][4] = "k"; //BH bialy hetman
			szachy[5][1] = "q"; //BK- bialy krol
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'b' || (ruch[1] - 48) != 3 || ruch[2] != 'd' || (ruch[3] - 48) != 5 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 7:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[1][0] = "q";//BH biala krolowa
			szachy[4][0] = "p";//BP bialy pionek
			szachy[6][6] = "k";//BK bialy krol
			szachy[2][6] = "n";//BE bialy skoczek
			szachy[0][4] = "K";//CK czarny krol
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'a' || (ruch[1] - 48) != 7 || ruch[2] != 'e' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 8:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][5] = "K";// czarny krol
			szachy[2][4] = "k";//bialy krol
			szachy[6][7] = "q";// bialy hetman
			szachy[1][3]= "p"; //bialy pionek
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 2 || ruch[2] != 'g' || (ruch[3] - 48) != 2 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 9:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][7] = "K"; //CK
			szachy[4][7] = "q";//BH
			szachy[1][5] = "P";//CP
			szachy[1][7] = "P";//CP
			szachy[2][6] = "P";//CP
			szachy[2][7] = "p";//BP
			szachy[5][6] = "k";//BK
			printboard(szachy); //wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 4 || ruch[2] != 'd' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
		case 10:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j] = " ";
				}
			}
			szachy[0][0] = "R";//czarna wieza
			szachy[0][2] = "B";//czarny goniec
			szachy[0][5] = "R";//czarna wieza
			szachy[0][6] = "K";//czarny krol
			szachy[1][0] = "P";//czarny pionek
			szachy[1][1] = "P";
			szachy[1][4] = "B";
			szachy[1][5] = "P";
			szachy[1][6] = "P";
			szachy[5][3] = "q";//bialy hetman
			szachy[2][2] = "P";
			szachy[2][5] = "Q";//czarny hetman
			szachy[3][0] = "N";// czarny skoczek
			szachy[4][2] = "p";//bialy pionek
			szachy[5][1] = "p";
			szachy[5][2] = "n";//bilay skoczek
			szachy[5][5] = "n";//bialy skoczek
			szachy[6][0] = "p";//bialy pionek
			szachy[6][1] = "b";//bialy goniec
			szachy[6][2] = "b";//bialy goniec
			szachy[6][5] = "p";
			szachy[6][6] = "p";
			szachy[6][7] = "p";
			szachy[7][3] = "r";//biala wieza
			szachy[7][4] = "r";///biala wieza
			szachy[7][6] = "k"; //bialy krol
			printboard(szachy);//wyswietla plansze
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'd' || (ruch[1] - 48) != 4 || ruch[2] != 'h' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				if (ruch == "exit")
				{
					break;
				}
				cout << "ZLY RUCH\n";
				cin >> ruch;
			}
			if (ruch != "exit")
				cout << "WYGRANA";
		}break;
	}
}
void opcjatrzecia(string ruchwygrany)
{
	string ruch;
	cin >> ruch;
	while (ruch[0] != ruchwygrany[0] || (ruch[1] - 48) != (ruchwygrany[1]-48 ) || ruch[2] != ruchwygrany[2] || (ruch[3] - 48) != (ruchwygrany[3] - 48) || ruch.length() != 4)
	{
		if (ruch == "exit")
		{
			break;
		}
		cout << "ZLY RUCH\n";
		cin >> ruch;
	}
	if (ruch != "exit")
		cout << "WYGRANA";
}
int zAbcNaInt(char a)
{
	if (a == 'a') return 0;
	else if(a == 'b') return 1;
	else if (a == 'c') return 2;
	else if (a == 'd') return 3;
	else if (a == 'e') return 4;
	else if (a == 'f') return 5;
	else if (a == 'g') return 6;
	else if (a == 'h') return 7;
	return 0;
}
void wgrajplansze()
{
	cout << "Oznaczenia pionkow: \n";
	cout << "'K'- czarny krol \n";
	cout << "'Q'- czarna krolowa \n";
	cout << "'R'- czarna wieza \n";
	cout << "'B'- czarny goniec \n";
	cout << "'N'- czarny kon \n";
	cout << "'P'- czarny pionek \n";
	cout << "'k'- bialy krol \n";
	cout << "'q'- biala krolowa \n";
	cout << "'r'- biala wieza \n";
	cout << "'b'- bialy goniec \n";
	cout << "'n'- bialy kon \n";
	cout << "'p'- bialy pionek \n";
	cout << "wypisuj ustawienie ciagiem, jedno za drugim \n";
	cout<<"PRZYKLAD: Nb5Ra8, czyli czarny kon jest ustawiony na polu b5, a czarna wieza na polu a8 \n";
	string ustawienie;
	cin >> ustawienie;
	cout << "Wybierz ustawienie kolorow pionkow na planszy: 0-biale sa na dole planszy,1-czarne sa na dole planszy\n";
	cin >> uklad;
	cout << "wpisanie 'exit' zakancza gre\n";
	for (int i = 0; i < 8; i ++)
	{
		for (int j = 0; j < 8; j ++)
		{
			plansza[i][j] = " ";
			kopia[i][j]=" ";
		}
	}
	for (int i = 0; i < ustawienie.length(); i+=3)
	{
		char pionek = ustawienie[i];
		int id_x = 8-(ustawienie[i + 2] - 48);
		int id_y = zAbcNaInt(ustawienie[i + 1]);
		plansza[id_x][id_y] = pionek;
		kopia[id_x][id_y] = pionek;
	}
	printboard(kopia);
}
void wpiszwstepnebiciaK(int xH, int yH)
{
	if ((xH != 0 && yH != 0) && (xH != 7 && yH != 7))
	{
		if (plansza[xH - 1][yH] != " ") bicieK[0] = true;
		if (plansza[xH - 1][yH+1] != " ") bicieK[1] = true;
		if (plansza[xH][yH+1] != " ") bicieK[2] = true;
		if (plansza[xH + 1][yH+1] != " ") bicieK[3] = true;
		if (plansza[xH + 1][yH] != " ") bicieK[4] = true;
		if (plansza[xH + 1][yH-1] != " ") bicieK[5] = true;
		if (plansza[xH][yH-1] != " ") bicieK[6] = true;
		if (plansza[xH - 1][yH-1] != " ") bicieK[7] = true;
	}
	else if (xH == 0 && yH == 0)
	{
		if (plansza[xH][yH + 1] != " ") bicieK[2] = true;
		if (plansza[xH + 1][yH + 1] != " ") bicieK[3] = true;
		if (plansza[xH + 1][yH] != " ") bicieK[4] = true;
	}
	else if (xH == 0 && yH == 7)
	{
		if (plansza[xH+1][yH] != " ") bicieK[4] = true;
		if (plansza[xH + 1][yH - 1] != " ") bicieK[5] = true;
		if (plansza[xH ][yH-1] != " ") bicieK[6] = true;
	}
	else if (xH == 7 && yH == 0)
	{
		if (plansza[xH - 1][yH] != " ") bicieK[0] = true;
		if (plansza[xH - 1][yH + 1] != " ") bicieK[1] = true;
		if (plansza[xH][yH+1] != " ") bicieK[2] = true;
	}
	else if (xH == 7 && yH == 7)
	{
		if (plansza[xH][yH - 1] != " ") bicieK[6] = true;
		if (plansza[xH - 1][yH - 1] != " ") bicieK[7] = true;
		if (plansza[xH -1][yH] != " ") bicieK[0] = true;
	}
	else if (xH == 0)
	{
		if (plansza[xH][yH + 1] != " ") bicieK[2] = true;
		if (plansza[xH + 1][yH + 1] != " ") bicieK[3] = true;
		if (plansza[xH + 1][yH] != " ") bicieK[4] = true;
		if (plansza[xH + 1][yH - 1] != " ") bicieK[5] = true;
		if (plansza[xH][yH - 1] != " ") bicieK[6] = true;
	}
	else if (xH == 7)
	{
		if (plansza[xH - 1][yH] != " ") bicieK[0] = true;
		if (plansza[xH - 1][yH + 1] != " ") bicieK[1] = true;
		if (plansza[xH][yH + 1] != " ") bicieK[2] = true;
		if (plansza[xH][yH - 1] != " ") bicieK[6] = true;
		if (plansza[xH - 1][yH - 1] != " ") bicieK[7] = true;
	}
	else if (yH == 0)
	{
		if (plansza[xH - 1][yH] != " ") bicieK[0] = true;
		if (plansza[xH - 1][yH + 1] != " ") bicieK[1] = true;
		if (plansza[xH][yH + 1] != " ") bicieK[2] = true;
		if (plansza[xH + 1][yH + 1] != " ") bicieK[3] = true;
		if (plansza[xH + 1][yH] != " ") bicieK[4] = true;
	}
	else if (yH == 7)
	{
		if (plansza[xH + 1][yH] != " ") bicieK[4] = true;
		if (plansza[xH + 1][yH - 1] != " ") bicieK[5] = true;
		if (plansza[xH][yH - 1] != " ") bicieK[6] = true;
		if (plansza[xH][yH + 1] != " ") bicieK[7] = true;
		if (plansza[xH - 1][yH] != " ") bicieK[0] = true;
	}
}
bool czybicieK(int xH, int yH)
{
		if ((xH != 0 && yH != 0) && (xH!=7 && yH!=7))
		{
			for (int j = 0; j < 8; j++)
			{
				if (bicieK[j] == false) return false;
			}
		}
		else if (xH == 0 && yH == 0)
		{
			if (bicieK[2] == false || bicieK[3] == false || bicieK[4] == false) return false;
		}
		else if (xH == 0 && yH == 7)
		{
			if (bicieK[4] == false || bicieK[5] == false || bicieK[6] == false) return false;
		}
		else if (xH == 7 && yH == 0)
		{
			if (bicieK[0] == false || bicieK[1] == false || bicieK[2] == false) return false;
		}
		else if (xH == 7 && yH == 7)
		{
			if (bicieK[6] == false || bicieK[7] == false || bicieK[0] == false) return false;
		}
		else if (xH == 0)
		{
			if (bicieK[2] == false || bicieK[3] == false || bicieK[4] == false || bicieK[5]==false || bicieK[6]==false) return false;
		}
		else if (xH == 7)
		{
			if (bicieK[6] == false || bicieK[7] == false || bicieK[0] == false || bicieK[1] == false || bicieK[2] == false) return false;
		}
		else if (yH == 0)
		{
			if (bicieK[0] == false || bicieK[1] == false || bicieK[2] == false || bicieK[3] == false || bicieK[4] == false) return false;
		}
		else if (yH == 7)
		{
			if (bicieK[4] == false || bicieK[5] == false || bicieK[6] == false || bicieK[7] == false || bicieK[0] == false) return false;
		}
	return true;
}
bool czybialypionek(int x, int y)
{
	if (plansza[x][y] == "k" || plansza[x][y] == "q" || plansza[x][y] == "r" || plansza[x][y] == "b" || plansza[x][y] == "n" || plansza[x][y] == "p") return true;
	return false;
}
bool wolnebicie(int x1, int y1, int x2, int y2, char figura) //,int uklad)
{
	switch (figura)
	{
		case 'k':
		{
			return true;
		}break;
		case'q':
		{
			if (x1 == x2 || y1 == y2) //tak samo jak w przypadku wiezy
			{
				int pomx, pomy;
				if (x2 < x1) //ruch w gore wieza
				{
					pomx = x1 - 1;
					pomy = y1;
					while (pomx != x2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx--;
					}
					return true;
				}
				else if (y2 > y1)//ruch w prawo wieza
				{
					pomx = x1;
					pomy = y1 + 1;
					while (pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomy++;
					}
					return true;
				}
				else if (x2 > x1)//ruch w dol wieza
				{
					pomx = x1 + 1;
					pomy = y1;
					while (pomx != x2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx++;
					}
					return true;
				}
				else if (y2 < y1)//ruch w lewo wieza
				{
					pomx = x1;
					pomy = y1 - 1;
					while (pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomy--;
					}
					return true;
				}
			}
			else //tak samo jak goniec
			{
				int pomx, pomy;
				if (x2<x1 && y2>y1) //ruch po ukosie w prawy gorny rog
				{
					pomx = x1 - 1;
					pomy = y1 + 1;
					while (pomx != x2 || pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx--;
						pomy++;
					}
					return true;
				}
				else if (x2 > x1 && y2 > y1) //ruch po ukosie w prwy dolny rog
				{
					pomx = x1 + 1;
					pomy = y1 + 1;
					while (pomx != x2 || pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx++;
						pomy++;
					}
					return true;
				}
				else if (x2 > x1 && y2 < y1) //ruch po ukosie w lewy dolny rog
				{
					pomx = x1 + 1;
					pomy = y1 - 1;
					while (pomx != x2 || pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx++;
						pomy--;
					}
					return true;
				}
				else if (x2 < x1 && y2 < y1) //ruch w lewy gorny rog
				{
					pomx = x1 - 1;
					pomy = y1 - 1;
					while (pomx != x2 || pomy != y2)
					{
						if (plansza[pomx][pomy] != " ")
						{
							return false;
						}
						pomx--;
						pomy--;
					}
					return true;
				}
			}
		}break;
		case'r':
		{
			int pomx, pomy;
			if(x2<x1) //ruch w gore wieza
			{
				pomx = x1 - 1;
				pomy = y1;
				while (pomx != x2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx--;
				}
				return true;
			}
			else if (y2>y1)//ruch w prawo wieza
			{
				pomx = x1;
				pomy = y1+1;
				while (pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomy++;
				}
				return true;
			}
			else if (x2>x1)//ruch w dol wieza
			{
				pomx = x1+1;
				pomy = y1;
				while (pomx != x2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx++;
				}
				return true;
			}
			else if (y2<y1)//ruch w lewo wieza
			{
				pomx = x1;
				pomy = y1-1;
				while (pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomy--;
				}
				return true;
			}
		}break;
		case'b':
		{
			int pomx,pomy;
			if (x2<x1 && y2>y1) //ruch po ukosie w prawy gorny rog
			{
				pomx = x1 - 1;
				pomy = y1 + 1;
				while (pomx != x2 || pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx--;
					pomy++;
				}
				return true;
			}
			else if (x2>x1 && y2>y1) //ruch po ukosie w prwy dolny rog
			{
				pomx = x1 + 1;
				pomy = y1 + 1;
				while (pomx != x2 || pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx++;
					pomy++;
				}
				return true;
			}
			else if (x2>x1 && y2<y1) //ruch po ukosie w lewy dolny rog
			{
				pomx = x1 + 1;
				pomy = y1 - 1;
				while (pomx != x2 || pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx++;
					pomy--;
				}
				return true;
			}
			else if (x2<x1 && y2<y1) //ruch w lewy gorny rog
			{
				pomx = x1 - 1;
				pomy = y1 - 1;
				while (pomx != x2 || pomy != y2)
				{
					if (plansza[pomx][pomy] != " ")
					{
						return false;
					}
					pomx--;
					pomy--;
				}
				return true;
			}
		}break;
		case'n':
		{
			return true;
			/*if ((x2 == x1 - 2 && y2 == y1 - 1) || (x2 == x1 - 2 && y2 == y1 + 1))
			{
				if (plansza[x1 - 1][y1] != " " && plansza[x1 - 2][y1] != " ")
				{
					return true;
				}
				else return false;
			}
			else if ((x2 == x1 - 1 && y2 == y1 + 2) || (x2 == x1 + 1 && y2 == y1 + 2))
			{
				if (plansza[x1][y1+1] != " " && plansza[x1][y1+2] != " ")
				{
					return true;
				}
				else return false;
			}
			else if (x2 == x1 + 2 && y2 == y1 + 1)
			{
			}
			else if (x2 == x1 + 2 && y2 == y1 - 1)
			{
			}
			else if (x2 == x1 + 1 && y2 == y1 - 2)
			{
			}
			else if (x2 == x1 - 1 && y2 == y1 - 2)
			{
			}*/
		}break;
		case'p':
		{
			if (abs(x1 - x2) > 1) //ruch o dwa pola
			{
				if (x1 > x2)
				{
					if (plansza[x1 - 1][y1] != " ")
					{
						return false;
					}
					else
						return true;
				}
				else
				{
					if (plansza[x2 - 1][y1] != " ")
					{
						return false;
					}
					else
						return true;
				}
			}
			else return true; //ruch jedno pole do przodu/tylu
		}break;
	}
	return false;
}
void wypelnbiciaH(int xH,int yH, bool uklad) //jak uklad=0 to białe sš na dole tablicy, uklad=1 to przypadek przeciwny
{
	wpiszwstepnebiciaK(xH,yH);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (czybialypionek(i, j))
			{
				char c = plansza[i][j][0];
				switch (c)
				{
					case 'k': //krol
					{
						for (int k = 0; k < 8; k++)
						{
							if (k==0 && i + 1 >= 0 && i + 1 == xH - 1 && (j == yH - 1 || j == yH || j == yH + 1)) //czy atak na 0 pole od czarnego hetmana
								//   7  0  1
								//   6  K  2
								//   5  4  3
								bicieK[0] = true;
							else if (k == 1 && ((i==xH-2 && j>=yH && j<=yH+2) || (j==yH+2 && i>=xH-2 && i<=xH))) //czy atak na 1 pole od czarnego hetmana
							{
								bicieK[1] = true;
							}
							else if (k == 2 && j==yH+2 && i>=xH-1 && i<=xH+1)
							{
								bicieK[2] = true;
							}
							else if (k == 3 && ((j == yH + 2 && i >= xH && i <= xH + 2) || (i == xH + 2 && j >= yH && j <= yH+2)))
							{
								bicieK[3] = true;
							}
							else if (k == 4 && i == xH + 2 && j >= yH - 1 && j <= yH + 1)
							{
								bicieK[4] = true;
							}
							else if (k == 5 && ((i == xH + 2 && j >= yH-2 && j <= yH) || (j == yH - 2 && i >= xH && i <= xH+2)))
							{
								bicieK[5] = true;
							}
							else if (k == 6 && j == yH - 2 && i >= xH - 1 && i <= xH + 1)
							{
								bicieK[6] = true;
							}
							else if (k == 7 && ((i == xH - 2 && j >= yH - 2 && j <= yH) || (j == yH - 2 && i >= xH-2 && i <= xH)))
							{
								bicieK[7] = true;
							}
						}
					}break;
					case 'q': //krolowa
					{
						if (i == xH - 1)
						{
							if (wolnebicie(i, j, xH - 1, yH - 1, 'q'))
								bicieK[7] = true;
							if (wolnebicie(i, j, xH - 1, yH, 'q'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH - 1, yH + 1, 'q'))
								bicieK[1] = true;
						}
						else if (i == xH)
						{
							if (wolnebicie(i, j, xH, yH - 1, 'q'))
								bicieK[6] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'q'))
								bicieK[2] = true;
						}
						else if (i == xH + 1)
						{
							if (wolnebicie(i, j, xH + 1, yH - 1, 'q'))
								bicieK[5] = true;
							if (wolnebicie(i, j, xH + 1, yH, 'q'))
								bicieK[4] = true;
							if (wolnebicie(i, j, xH + 1, yH + 1, 'q'))
								bicieK[3] = true;
						}
						if (j == yH - 1)
						{
							if (wolnebicie(i, j, xH - 1, yH - 1, 'q'))
								bicieK[7] = true;
							if (wolnebicie(i, j, xH, yH - 1, 'q'))
								bicieK[6] = true;
							if (wolnebicie(i, j, xH + 1, yH - 1, 'q'))
								bicieK[5] = true;
						}
						else if (j == yH)
						{
							if (wolnebicie(i, j, xH - 1, yH, 'q'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH + 1, yH, 'q'))
								bicieK[4] = true;
						}
						else if (j == yH + 1)
						{
							if (wolnebicie(i, j, xH - 1, yH + 1, 'q'))
								bicieK[1] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'q'))
								bicieK[2] = true;
							if (wolnebicie(i, j, xH + 1, yH + 1, 'q'))
								bicieK[3] = true;
						}
						// \ ukosna
						if (j - i == (yH - 1) - (xH + 1))
						{
							if (wolnebicie(i, j, xH + 1, yH - 1, 'q'))
								bicieK[5] = true;
						}
						else if (j - i == yH - (xH + 1))
						{
						if (wolnebicie(i, j, xH + 1, yH, 'q'))
								bicieK[4] = true;
							if (wolnebicie(i, j, xH, yH - 1, 'q'))
								bicieK[6] = true;
						}
						else if (j - i == yH - xH)
						{
							if (wolnebicie(i, j, xH + 1, yH + 1, 'q'))
								bicieK[3] = true;
							if (wolnebicie(i, j, xH - 1, yH - 1, 'q'))
								bicieK[7] = true;
						}
						else if (j - i == yH - (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH, 'q'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'q'))
								bicieK[2] = true;
						}
						else if (j - i == (yH + 1) - (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH + 1, 'q'))
								bicieK[1] = true;
						}
						// / ukosna
						if (j + i == (yH + 1) + (xH + 1))
						{
							if (wolnebicie(i, j, xH + 1, yH + 1, 'q'))
								bicieK[3] = true;
						}
						else if (j + i == yH + (xH + 1))
						{
							if (wolnebicie(i, j, xH + 1, yH, 'q'))
								bicieK[4] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'q'))
								bicieK[2] = true;
						}
						else if (j + i == yH + xH)
						{
							if (wolnebicie(i, j, xH + 1, yH - 1, 'q'))
								bicieK[5] = true;
							if (wolnebicie(i, j, xH - 1, yH + 1, 'q'))
								bicieK[1] = true;
						}
						else if (j + i == yH + (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH, 'q'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH, yH - 1, 'q'))
								bicieK[6] = true;
						}
						else if (j + i == (yH - 1) + (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH - 1, 'q'))
								bicieK[7] = true;
						}
					}break;
					case 'r': //wieza
					{
						if (i == xH - 1)
						{
							if (wolnebicie(i, j, xH - 1, yH - 1, 'r'))
								bicieK[7] = true;
							if (wolnebicie(i, j, xH - 1, yH, 'r'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH - 1, yH + 1, 'r'))
								bicieK[1] = true;
						}
						else if (i == xH)
						{
							if (wolnebicie(i, j, xH , yH - 1, 'r'))
								bicieK[6] = true;
							if (wolnebicie(i, j, xH , yH + 1, 'r'))
								bicieK[2] = true;
						}
						else if (i == xH + 1)
						{
							if(wolnebicie(i, j, xH + 1, yH - 1, 'r'))
								bicieK[5] = true;
							if (wolnebicie(i, j, xH + 1, yH, 'r'))
								bicieK[4] = true;
							if (wolnebicie(i, j, xH + 1, yH + 1, 'r'))
								bicieK[3] = true;
						}
						if (j == yH - 1)
						{
							if (wolnebicie(i, j, xH - 1, yH-1, 'r'))
								bicieK[7] = true;
							if (wolnebicie(i, j, xH, yH-1, 'r'))
								bicieK[6] = true;
							if (wolnebicie(i, j, xH + 1, yH-1, 'r'))
								bicieK[5] = true;
						}
						else if (j == yH)
						{
							if (wolnebicie(i, j, xH-1, yH, 'r'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH+1, yH, 'r'))
								bicieK[4] = true;
						}
						else if (j == yH + 1)
						{
							if (wolnebicie(i, j, xH - 1, yH + 1, 'r'))
								bicieK[1] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'r'))
								bicieK[2] = true;
							if(wolnebicie(i, j, xH+1, yH + 1, 'r'))
								bicieK[3] = true;
						}
					}break;
					case 'b': //goniec-po ukosie
					{
						// \ ukosna
						if (j - i == (yH - 1) - (xH + 1))
						{
							if(wolnebicie(i, j, xH + 1, yH - 1, 'b'))
								bicieK[5] = true;
						}
						else if (j - i == yH - (xH + 1))
						{
							if(wolnebicie(i, j, xH + 1, yH, 'b'))
								bicieK[4]=true;
							if(wolnebicie(i, j, xH , yH - 1, 'b'))
								bicieK[6] = true;
						}
						else if (j - i == yH - xH)
						{
							if(wolnebicie(i, j, xH + 1, yH + 1, 'b'))
								bicieK[3] = true;
							if(wolnebicie(i, j, xH - 1, yH - 1, 'b'))
								bicieK[7] = true;
						}
						else if (j-i==yH-(xH-1))
						{
							if(wolnebicie(i, j, xH - 1, yH , 'b'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH , yH + 1, 'b'))
								bicieK[2] = true;
						}
						else if (j - i == (yH + 1) - (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH + 1, 'b'))
								bicieK[1] = true;
						}
						// / ukosna
						if (j + i == (yH + 1) + (xH + 1))
						{
							if (wolnebicie(i, j, xH + 1, yH + 1, 'b'))
								bicieK[3] = true;
						}
						else if (j + i == yH + (xH + 1))
						{
							if (wolnebicie(i, j, xH + 1, yH , 'b'))
								bicieK[4] = true;
							if (wolnebicie(i, j, xH, yH + 1, 'b'))
								bicieK[2] = true;
						}
						else if (j + i == yH + xH)
						{
							if (wolnebicie(i, j, xH + 1, yH - 1, 'b'))
								bicieK[5] = true;
							if (wolnebicie(i, j, xH - 1, yH + 1, 'b'))
								bicieK[1] = true;
						}
						else if (j + i == yH + (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH , 'b'))
								bicieK[0] = true;
							if (wolnebicie(i, j, xH , yH - 1, 'b'))
								bicieK[6] = true;
						}
						else if (j + i == (yH - 1) + (xH - 1))
						{
							if (wolnebicie(i, j, xH - 1, yH - 1, 'b'))
								bicieK[7] = true;
						}
					}break;
					case 'n': //kon
					{
						for (int k = 0; k < 8; k++)
						{
							if (k == 0 && ((i - 2 == xH - 1 && j + 1 == yH) || (i - 1 == xH - 1 && j + 2 == yH) || (i + 1 == xH - 1 && j + 2 == yH) || (i + 2 == xH - 1 && j + 1 == yH) || (i + 2 == xH - 1 && j - 1 == yH) || (i + 1 == xH - 1 && j - 2 == yH) || (i - 1 == xH - 1 && j - 2 == yH) || (i - 2 == xH - 1 && j - 1 == yH)))
							{
								bicieK[0] = true;
							}
							if (k == 1 && ((i - 2 == xH - 1 && j + 1 == yH+1) || (i - 1 == xH - 1 && j + 2 == yH + 1) || (i + 1 == xH - 1 && j + 2 == yH + 1) || (i + 2 == xH - 1 && j + 1 == yH + 1) || (i + 2 == xH - 1 && j - 1 == yH + 1) || (i + 1 == xH - 1 && j - 2 == yH + 1) || (i - 1 == xH - 1 && j - 2 == yH + 1) || (i - 2 == xH - 1 && j - 1 == yH + 1)))
							{
								bicieK[1] = true;
							}
							if (k == 2 && ((i - 2 == xH && j + 1 == yH + 1) || (i - 1 == xH && j + 2 == yH + 1) || (i + 1 == xH  && j + 2 == yH + 1) || (i + 2 == xH  && j + 1 == yH + 1) || (i + 2 == xH  && j - 1 == yH + 1) || (i + 1 == xH  && j - 2 == yH + 1) || (i - 1 == xH  && j - 2 == yH + 1) || (i - 2 == xH  && j - 1 == yH + 1)))
							{
								bicieK[2] = true;
							}
							if (k == 3 && ((i - 2 == xH + 1 && j + 1 == yH + 1) || (i - 1 == xH + 1 && j + 2 == yH + 1) || (i + 1 == xH + 1 && j + 2 == yH + 1) || (i + 2 == xH + 1 && j + 1 == yH + 1) || (i + 2 == xH + 1 && j - 1 == yH + 1) || (i + 1 == xH + 1 && j - 2 == yH + 1) || (i - 1 == xH + 1 && j - 2 == yH + 1) || (i - 2 == xH + 1 && j - 1 == yH + 1)))
							{
								bicieK[3] = true;
							}
							if (k == 4 && ((i - 2 == xH + 1 && j + 1 == yH) || (i - 1 == xH + 1 && j + 2 == yH) || (i + 1 == xH + 1 && j + 2 == yH) || (i + 2 == xH + 1 && j + 1 == yH) || (i + 2 == xH + 1 && j - 1 == yH) || (i + 1 == xH + 1 && j - 2 == yH) || (i - 1 == xH + 1 && j - 2 == yH) || (i - 2 == xH + 1 && j - 1 == yH)))
							{
								bicieK[4] = true;
							}
							if (k == 5 && ((i - 2 == xH + 1 && j + 1 == yH-1) || (i - 1 == xH + 1 && j + 2 == yH-1) || (i + 1 == xH + 1 && j + 2 == yH-1) || (i + 2 == xH + 1 && j + 1 == yH-1) || (i + 2 == xH + 1 && j - 1 == yH-1) || (i + 1 == xH + 1 && j - 2 == yH-1) || (i - 1 == xH + 1 && j - 2 == yH-1) || (i - 2 == xH + 1 && j - 1 == yH-1)))
							{
								bicieK[5] = true;
							}
							if (k == 6 && ((i - 2 == xH  && j + 1 == yH-1) || (i - 1 == xH  && j + 2 == yH-1) || (i + 1 == xH  && j + 2 == yH-1) || (i + 2 == xH  && j + 1 == yH-1) || (i + 2 == xH  && j - 1 == yH-1) || (i + 1 == xH  && j - 2 == yH-1) || (i - 1 == xH  && j - 2 == yH-1) || (i - 2 == xH && j - 1 == yH-1)))
							{
								bicieK[6] = true;
							}
							if (k == 7 && ((i - 2 == xH - 1 && j + 1 == yH-1) || (i - 1 == xH - 1 && j + 2 == yH-1) || (i + 1 == xH - 1 && j + 2 == yH-1) || (i + 2 == xH - 1 && j + 1 == yH-1) || (i + 2 == xH - 1 && j - 1 == yH-1) || (i + 1 == xH - 1 && j - 2 == yH-1) || (i - 1 == xH - 1 && j - 2 == yH-1) || (i - 2 == xH - 1 && j - 1 == yH-1)))
							{
								bicieK[7] = true;
							}
						}
					}break;
					case 'p': //pionek
					{
						if (!uklad)
						{
							if (i == xH && j == yH - 2)
							{
								bicieK[7] = true;
							}
							else if (i == xH + 1 && j == yH - 2)
							{
								bicieK[6] = true;
							}
							else if (i == xH + 2 && j == yH - 2)
							{
								bicieK[5] = true;
							}
							else if (i == xH + 2 && j == yH - 1)
							{
								bicieK[4] = true;
							}
							else if (i == xH + 2 && j == yH )
							{
								bicieK[3] = true;
								bicieK[5] = true;
							}
							else if (i == xH + 2 && j == yH +1)
							{
								bicieK[4] = true;
							}
							else if (i == xH + 2 && j == yH + 2)
							{
								bicieK[3] = true;
							}
							else if (i == xH + 1 && j == yH + 2)
							{
								bicieK[2] = true;
							}
							else if (i == xH  && j == yH + 2)
							{
								bicieK[1] = true;
							}
						}
						else
						{
							if (i == xH  && j == yH - 2)
							{
								bicieK[5] = true;
							}
							else if (i == xH - 1 && j == yH - 2)
							{
								bicieK[6] = true;
							}
							else if (i == xH - 2 && j == yH - 2)
							{
								bicieK[7] = true;
							}
							else if (i == xH - 2 && j == yH - 1)
							{
								bicieK[0] = true;
							}
							else if (i == xH - 2 && j == yH)
							{
								bicieK[7] = true;
								bicieK[1] = true;
							}
							else if (i == xH - 2 && j == yH +1)
							{
								bicieK[0] = true;
							}
							else if (i == xH - 2 && j == yH + 2)
							{
								bicieK[1] = true;
							}
							else if (i == xH - 1 && j == yH + 2)
							{
								bicieK[2] = true;
							}
							else if (i == xH && j == yH + 2)
							{
								bicieK[3] = true;
							}
						}
					}break;
				}
			}
		}
	}
}
void czyscbicia()
{
	for (int i = 0; i < 8; i++)
	{
		bicieK[i] = false;
	}
	return;
}
string zIntNaAbc(int j)
{
	switch (j)
	{
	case 0:
	{
		return "a";
	}break;
	case 1:
	{
		return "b";
	}break;
	case 2:
	{
		return "c";
	}break;
	case 3:
	{
		return "d";
	}break;
	case 4:
	{
		return "e";
	}break;
	case 5:
	{
		return "f";
	}break;
	case 6:
	{
		return "g";
	}break;
	case 7:
	{
		return "h";
	}break;
	}
	return "e";
}

char liczbachar(int a)
{
	if (a == 0) return '8';
	else if (a == 1) return '7';
	else if (a == 2) return '6';
	else if (a == 3) return '5';
	else if (a == 4) return '4';
	else if (a == 5) return '3';
	else if (a == 6) return '2';
	else if (a == 7) return '1';
	else return ' ';
}
string czyonmozemat(int x, int y, int xH,int yH)
{
	char b =liczbachar(x);
	string a = zIntNaAbc(y);
	char c = plansza[x][y][0];
	int currx = x;
	int curry = y;
	string wynik = "";
	bool ok=true;
	switch (c)
	{
		case'k': //krol
		{
			for (int i = 0; i < 8; i++)
			{
				if (i == 0 && currx-1>=0 && currx-1<8  && wolnebicie(x, y, x - 1, y, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y] = c;
					currx = x - 1;
					curry = y;
					wypelnbiciaH(xH,yH,uklad);
					if (czybicieK(xH,yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik =  a+ b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 1  && x - 1 >= 0 && x - 1 < 8 && y+1>=0 && y+1<8 && wolnebicie(x, y, x - 1, y+1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y+1] = c;
					currx = x-1;
					curry = y+1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH,yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 2 && x >= 0 && x < 8 && y + 1 >= 0 && y + 1 < 8 && wolnebicie(x, y, x , y+1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x ][y+1] = c;
					currx = x;
					curry = y + 1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH,yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 3 && x + 1 >= 0 && x + 1 < 8 && y + 1 >= 0 && y + 1 < 8 && wolnebicie(x, y, x + 1, y+1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y+1] = c;
					currx=x+1;
					curry = y+1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 4 && x + 1 >= 0 && x + 1 < 8 && y  >= 0 && y  < 8 && wolnebicie(x, y, x + 1, y, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y] = c;
					currx = x+1;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 5 && x + 1 >= 0 && x + 1 < 8 && y - 1 >= 0 && y - 1 < 8 && wolnebicie(x, y, x + 1, y-1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y-1] = c;
					currx = x + 1;
					curry = y-1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 6 && x  >= 0 && x  < 8 && y - 1 >= 0 && y - 1 < 8 && wolnebicie(x, y, x , y-1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x ][y-1] = c;
					currx = x;
					curry = y-1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 7 && x - 1 >= 0 && x - 1 < 8 && y - 1 >= 0 && y - 1 < 8 && wolnebicie(x, y, x - 1, y-1, 'k'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y-1] = c;
					currx = x - 1;
					curry = y-1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		case'q'://krolowa
		{
			for (int i = 1; i < 8; i++)
			{
				if (x - i >= 0 && x - i < 8 && wolnebicie(x, y, x - i, y, 'q')) //w gore
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - i][y] = c;
					currx = x - i;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + i >= 0 && x + i < 8 && wolnebicie(x, y, x + i, y, 'q')) //w dol
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + i][y] = c;
					currx = x + i;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (y - i >= 0 && y - i < 8 && wolnebicie(x, y, x , y-i, 'q')) //w lewo
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x][y - i] = c;
					currx = x;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (y + i >= 0 && y + i < 8 && wolnebicie(x, y, x , y+i, 'q'))//w prawo
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x][y + i] = c;
					currx = x;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = liczbachar(currx);
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x - i >= 0 && x - i < 8 && y - i >= 0 && y - i < 8 && wolnebicie(x, y, x - i, y-i, 'q')) //po ukosie w prawy gorny rog
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - i][y - i] = c;
					currx = x - i;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x - i >= 0 && x - i < 8 && y + i >= 0 && y + i < 8 && wolnebicie(x, y, x - i, y+i, 'q')) //po ukosie w lewy gorny rog
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - i][y + i] = c;
					currx = x - i;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 =8- currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + i >= 0 && x + i < 8 && y + i >= 0 && y + i < 8 && wolnebicie(x, y, x + i, y+i, 'q')) //po ukosie w prawy dolny rog
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + i][y + i] = c;
					currx = x + i;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + i >= 0 && x + i < 8 && y - i >= 0 && y - i < 8 && wolnebicie(x, y, x + i, y-i, 'q'))//po ukosie w lewy dolny rog
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + i][y - i] = c;
					currx = x + i;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		case'r'://wieza
		{
			for (int i = 1; i < 8; i++)
			{
				if (x - i >= 0 && x -i< 8 && wolnebicie(x, y, x - i, y, 'r')) //w gore
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - i][y ] = c;
					currx = x - i;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x+i>=0 && x+i<8 && wolnebicie(x, y, x + i, y, 'r')) //w dol
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + i][y ] = c;
					currx = x +i;
					curry = y ;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (y-i>=0 && y-i<8 && wolnebicie(x, y, x , y-i, 'r')) //w lewo
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x ][y - i] = c;
					currx = x ;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (y + i >= 0 && y + i < 8 && wolnebicie(x, y, x , y+i, 'r'))//w prawo
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x ][y + i] = c;
					currx = x ;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		case'b'://goniec
		{
			for (int i = 1; i < 8; i++)
			{
				if (x-i>=0 && x-i<8 && y-i>=0 && y-i<8 && wolnebicie(x, y, x - i, y-i, 'b'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x-i][y - i] = c;
					currx = x-i;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x - i >= 0 && x - i < 8 && y + i >= 0 && y + i < 8 && wolnebicie(x, y, x - i, y + i, 'b'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x-i][y + i] = c;
					currx = x-i;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + i >= 0 && x + i < 8 && y + i >= 0 && y + i < 8 && wolnebicie(x, y, x + i, y + i, 'b'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x+i][y + i] = c;
					currx = x+i;
					curry = y + i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + i >= 0 && x + i < 8 && y - i >= 0 && y - i < 8 && wolnebicie(x, y, x + i, y - i, 'b'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x+i][y - i] = c;
					currx = x+i;
					curry = y - i;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		case'n': //skoczek
		{
			for (int i = 0; i < 8; i++)
			{
				if (i == 0 && x-2>=0 && x-2<8 && y-1>=0 && y-1<8 && wolnebicie(x, y, x - 2, y - 1, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 2][y - 1] = c;
					currx = x - 2;
					curry = y - 1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 1 && x - 2 >= 0 && x - 2 < 8 && y + 1 >= 0 && y + 1 < 8 && wolnebicie(x, y, x - 2, y +1, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 2][y + 1] = c;
					currx = x - 2;
					curry = y + 1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 2 && x - 1 >= 0 && x - 1 < 8 && y + 2 >= 0 && y +2 < 8 && wolnebicie(x, y, x - 1, y +2, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y + 2] = c;
					currx = x - 1;
					curry = y + 2;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 3 && x + 1 >= 0 && x + 1 < 8 && y + 2 >= 0 && y + 2 < 8 && wolnebicie(x, y, x +1, y +2, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y + 2] = c;
					currx = x + 1;
					curry = y + 2;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 4 && x + 2 >= 0 && x + 2 < 8 && y + 1 >= 0 && y + 1 < 8 && wolnebicie(x, y, x +2, y +1, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 2][y + 1] = c;
					currx = x + 2;
					curry = y + 1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 5 && x + 2 >= 0 && x + 2 < 8 && y - 1 >= 0 && y - 1 < 8 && wolnebicie(x, y, x +2, y - 1, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 2][y - 1] = c;
					currx = x + 2;
					curry = y - 1;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 6 && x +1 >= 0 && x + 1 < 8 && y - 2 >= 0 && y - 2 < 8 && wolnebicie(x, y, x +1, y - 2, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y - 2] = c;
					currx = x + 1;
					curry = y - 2;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (i == 7 && x - 1 >= 0 && x - 1 < 8 && y - 2 >= 0 && y - 2 < 8 && wolnebicie(x, y, x - 1, y - 2, 'n'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y -2] = c;
					currx = x - 1;
					curry = y -2;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		case'p': //pionek
		{
			if (uklad == 0) //biale sa na dole
			{
				if (x - 1 >= 0 && x - 1 < 8 && wolnebicie(x, y, x - 1, y , 'p'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 1][y] = c;
					currx = x - 1;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x - 2 >= 0 && x - 2 < 8 && wolnebicie(x, y, x - 2, y, 'p'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x - 2][y] = c;
					currx = x - 2;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			else
			{
				if (x + 1 >= 0 && x + 1 < 8 && wolnebicie(x, y, x +1, y , 'p'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 1][y] = c;
					currx = x + 1;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
				if (x + 2 >= 0 && x + 2 < 8 && wolnebicie(x, y, x +2, y , 'p'))
				{
					czyscbicia();
					if (ok)
					{
						plansza[currx][curry] = " ";
						ok = false;
					}
					else
						plansza[currx][curry] = kopia[currx][curry];
					plansza[x + 2][y] = c;
					currx = x + 2;
					curry = y;
					wypelnbiciaH(xH, yH, uklad);
					if (czybicieK(xH, yH))
					{
						char pomoc2 = 8-currx + 48;
						wynik = a + b + zIntNaAbc(curry) + pomoc2;
						return wynik;
					}
				}
			}
			plansza[currx][curry] = kopia[currx][curry];
		}break;
		default:
		{
			return "";
		}break;
	}
	plansza[x][y] = kopia[x][y];
	return "";
}


string jakisruchdomata()
{
	//zakladamy ze zawsze jest mozliwy mat w jednym ruchu
	string ruchwygrana;
	int idH_x, idH_y;
	for (int i = 0; i < 8; i++)
		bicieK[i] = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (plansza[i][j]=="K")
			{
				idH_x = i;
				idH_y = j;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (czybialypionek(i, j))
			{

				ruchwygrana = czyonmozemat(i, j, idH_x, idH_y); //jezeli tak, to fcja zwroci w jakim ruchu
				if (ruchwygrana != "")
				{
					return ruchwygrana;
				}
			}
		}
	}
	return "";
}
int gratreningowa()
{
	printf("WYBIERZ JEDNA Z TRZECH OPCJI: \n");
	printf("1 - czytanie z pliku o formacie PGN \n");
	printf("2 - losowanie gry 'MAT W JEDNYM RUCHU' \n");
	printf("3 - wypisanie ustawienia planszy do gry 'MAT W JEDNYM RUCHU'\n");
	int a;
	cin >> a;
	switch (a)
	{
		case 1:
		{

		}break;
		case 2:
		{
			srand((unsigned int)time(NULL));
			int liczbarand = (rand() % 10) + 1;
			string szachy[8][8];
			gra(szachy, liczbarand);
		}break;
		case 3:
		{
			wgrajplansze();
			string ruchdomata=jakisruchdomata();
			opcjatrzecia(ruchdomata);
		}break;
		default:
			break;
	}
	return 0;
}
