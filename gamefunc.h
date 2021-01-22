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
}savedMove;



void initboard(figura board[8][8],int tryb);

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/);

bool isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4]);

bool isChecked(int yKing, int xKing, figura board[8][8]);

bool isMating(int yKing, int xKing, figura board[8][8]);

void inputMove(char *xP,char *yP,char *xK,char *yK,int mode);

void outputMsg(bool local,int mesydz, int tim);

int chessGame(int mode);
