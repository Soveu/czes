#include <string>
#include <sstream>
#include <fstream>

typedef struct figura
{
    unsigned char fig; //' ', 'P', 'R', 'B', 'N', 'Q', 'K'
    int tim; //1 = bialy, 2 = czarny, -1 - puste
}figura;

typedef struct savedMove
{
    unsigned char fig;  // 'P', 'R', 'B', 'N', 'Q', 'K'
    int tim;            // 1 = bialy, 2 = czarny
    int coords[4];      // yP,xP,yK,xK
    bool szach;         // czy w tym ruchu byl szach
    bool mat;            // czy w tym ruchu byl mat
    bool passant;
}savedMove;

void initboard(figura board[8][8],int tryb);

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/);

bool isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4]);

bool isChecked(int yKing, int xKing, figura board[8][8]);

bool isMating(int yKing, int xKing, figura board[8][8]);

void inputMove(char *xP,char *yP,char *xK,char *yK,bool local);

void outputMsg(bool local,int mesydz, int tim);

void inputMsg(bool local, int ktora, int *mesydz, char *msg);

char converter(int znak);

void checkStar(std::string &edytowane, std::ostringstream &strim);

void basicMove(savedMove &ruch, std::ostringstream &dane, int tura);

void zbicieMove(savedMove &ruch, std::ostringstream &dane, int tura);

bool checkRoszada(savedMove &ruch);

void roszadaMove(savedMove &ruch, std::ostringstream &dane, int tura);

int chessGame(bool mode, int czywczytac, int display);
