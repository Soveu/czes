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
			/*char a, c;
			int b, d;
			cin >> a >> b >> c >> d;
			if (a == 'a' && b == 7 && c == 'e' && d == 7)
			{
				cout << "WYGRANA";
			}
			else
			{
				cout << "ZLY RUCH\n";
			}*/
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
			
		}break;
		case 3:
		{
			
		}break;
		case 4:
		{
			
		}break;
		case 5:
		{
			
		}break;
		case 6:
		{
			
		}break;
		case 7:
		{
			
		}break;
		case 8:
		{
			
		}break;
		case 9:
		{
			
		}break;
		case 10:
		{
			
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
	
}
bool czybicieK(int xH, int yH)
{
	return false;
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
