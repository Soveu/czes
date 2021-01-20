


typedef struct figura
{
    unsigned char fig;
    int tim; //1 = biały, 2 = czarny
} figura;

void initboard(figura board[8][8],int tryb);

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/);

int isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4]);

int isChecked(int yKing, int xKing, figura board[8][8]);

int isMating(int yKing, int xKing, figura board[8][8]);

int isMating(int yKing, int xKing, figura board[8][8]);

int chessGame(int mode);
