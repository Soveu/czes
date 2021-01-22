#include <string>
#include <sstream>
#include <fstream>

typedef struct figura
{
    unsigned char fig;
    int tim; //1 = biały, 2 = czarny
} figura;

typedef struct savedMove
{
    unsigned char fig;  // 'P', 'T', 'B', 'N', 'Q', 'K'
    int tim;            // 1 = biały, 2 = czarny
    int coords[4];      // yP,xP,yK,xK
    bool szach;         // czy w tym ruchu byl szach
	bool mat;			// czy w tym ruchu byl mat
}savedMove;

void initboard(figura board[8][8],int tryb);

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/);

bool isLegal(figura board[8][8],int yP,int x	P,int yK,int xK,int cas[4]);

bool isChecked(int yKing, int xKing, figura board[8][8]);

bool isMating(int yKing, int xKing, figura board[8][8]);

void inputMove(char *xP,char *yP,char *xK,char *yK,int mode);

void outputMsg(bool local,int mesydz, int tim);

char converter(int znak);

void checkStar(std::string &edytowane, std::ostringstream &strim);

void basicMove(savedMove &ruch, std::ostringstream &dane, int tura);

void zbicieMove(savedMove &ruch, std::ostringstream &dane, int tura);

bool checkRoszada(savedMove &ruch);

void roszadaMove(savedMove &ruch, std::ostringstream &dane, int tura);

int chessGame(int mode);
