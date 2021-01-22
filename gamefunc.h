typedef struct figura
{
    unsigned char fig;
    int tim; //1 = biały, 2 = czarny
} figura;

#ifndef __unix__
const char* PIECES[7] = {
  " ",//0
  "♟",//1
  "♝",//2
  "♞",//3
  "♜",//4
  "♛",//5
  "♚",//6
};
#endif

void initboard(figura board[8][8],int tryb);

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/);

bool isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4]);

bool isChecked(int yKing, int xKing, figura board[8][8]);

bool isMating(int yKing, int xKing, figura board[8][8]);

int inputMove(char *xP,char *yP,char *xK,char *yK,int mode);

int chessGame(int mode);
