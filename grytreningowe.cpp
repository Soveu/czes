#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;
string plansza[8][8];
int uklad;
bool bicieK[8]; //tablica,ktora zawiera pola wokol krola czarnego, 0-gdy pole nie jest bite, 1-gdy pole jest bite
void gra(string szachy[8][8], int liczbarand)
{
	switch (liczbarand)
	{
		case 1:
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					szachy[i][j]="__";
				}
			}
			szachy[0][4]="K";
			szachy[2][3] = "n"; //bialy skoczek
			szachy[4][0] = "p";
			szachy[1][0] = "r"; //biala wieza
			szachy[6][6] = "k"; //bialy krol
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8-i << " ";
				for (int j=0;j<8;j++)
				{
					cout <<"*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'a' || (ruch[1] - 48) != 7 || ruch[2] != 'e' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][5] = "K";
			szachy[5][7] = "r"; //biala wieza
			szachy[4][0] = "p"; //bialy pionek
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 3 || ruch[2] != 'h' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[2][3] = "K"; //czarny krol
			szachy[3][3] = "n"; //bialy skoczek
			szachy[4][3] = "k"; //bialy krol
			szachy[4][7] = "q"; //biala krolowa
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 4 || ruch[2] != 'd' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][2] = "R";
			szachy[0][3] = "K"; //czarny krol
			szachy[0][4] = "R"; //czarna wieza
			szachy[5][6] = "q"; //biala krolowa
			szachy[6][6] = "k"; //bialy krol
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'g' || (ruch[1] - 48) != 3 || ruch[2] != 'd' || (ruch[3] - 48) != 6 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][6] = "R"; //czarna wieza
			szachy[0][7] = "K"; // czarny krol
			szachy[1][6] = "P"; //czarny pionek
			szachy[2][6] = "q"; //biala krolowa
			szachy[6][6] = "k"; //bialy krol
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'g' || (ruch[1] -48)!= 6 || ruch[2] != 'h' || (ruch[3]-48) != 5 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[2][3] = "K"; //CK czarny krol
			szachy[0][3] = "N"; //CG czarny skoczek
			szachy[5][1] = "q"; //BH bialy hetman
			szachy[4][3] = "k"; //BK- bialy krol
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'b' || (ruch[1] - 48) != 3 || ruch[2] != 'd' || (ruch[3] - 48) != 5 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[1][0] = "q";//BH biala krolowa
			szachy[4][0] = "p";//BP bialy pionek
			szachy[6][6] = "k";//BK bialy krol
			szachy[2][6] = "n";//BE bialy skoczek
			szachy[0][4] = "K";//CK czarny krol
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'a' || (ruch[1] - 48) != 7 || ruch[2] != 'e' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][3] = "K";// czarny krol
			szachy[2][4] = "k";//bialy krol
			szachy[6][7] = "q";// bialy hetman
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 2 || ruch[2] != 'b' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][7] = "K"; //CK
			szachy[4][7] = "q";//BH
			szachy[1][5] = "P";//CP
			szachy[1][7] = "P";//CP
			szachy[2][6] = "P";//CP
			szachy[2][7] = "p";//BP
			szachy[5][6] = "k";//BK
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'h' || (ruch[1] - 48) != 4 || ruch[2] != 'd' || (ruch[3] - 48) != 8 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
					szachy[i][j] = "__";
				}
			}
			szachy[0][0] = "R";//CW
			szachy[0][2] = "B";//CG
			szachy[0][5] = "R";//CW
			szachy[0][6] = "K";//CK
			szachy[1][0] = "P";//CP
			szachy[1][1] = "P";//CP
			szachy[1][4] = "B";//CG
			szachy[1][5] = "P";//CP
			szachy[1][6] = "P";//CP
			szachy[5][3] = "q";//BH
			szachy[2][2] = "P";//CP
			szachy[2][5] = "Q";//CH
			szachy[3][0] = "N";//CE
			szachy[4][2] = "p";//
			szachy[5][1] = "p";//
			szachy[5][2] = "n";//BE
			szachy[5][5] = "n";//BE
			szachy[6][0] = "p";//
			szachy[6][1] = "b";//
			szachy[6][2] = "b";//
			szachy[6][5] = "p";//
			szachy[6][6] = "p";//
			szachy[6][7] = "p";//
			szachy[7][3] = "r";//BW
			szachy[7][4] = "r";///BW
			szachy[7][6] = "k"; //BK
			cout << "  *************************\n";
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					cout << "*" << szachy[i][j];
				}
				cout << "*" << endl;
			}
			cout << "  *************************\n";
			cout << "   a  b  c  d  e  f  g  h\n";
			string ruch;
			cin >> ruch;
			while (ruch[0] != 'd' || (ruch[1] - 48) != 4 || ruch[2] != 'h' || (ruch[3] - 48) != 7 || ruch.length() != 4)
			{
				cout << "ZLY RUCH\n";
				cin >> ruch;
				if (ruch == "exit")
				{
					break;
				}
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
		cout << "ZLY RUCH\n";
		cin >> ruch;
		if (ruch == "exit")
		{
			break;
		}
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
		}
	}
	for (int i = 0; i < ustawienie.length(); i+=3)
	{
		char pionek = ustawienie[i];
		int id_x = 8-(ustawienie[i + 2] - 48);
		int id_y = zAbcNaInt(ustawienie[i + 1]);
		plansza[id_x][id_y] = pionek;
	}
	cout << "  *****************\n";
	for (int i = 0; i < 8; i++)
	{
		cout << 8 - i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << "*" << plansza[i][j];
		}
		cout << "*" << endl;
	}
	cout << "  *****************\n";
	cout << "  a b c d e f g h\n";
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

void wypelnbiciaH(int xH,int yH, bool uklad) //jak uklad=0 to bia³e s¹ na dole tablicy, uklad=1 to przypadek przeciwny
{
	
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
int main()
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
	}
	return 0;
}
