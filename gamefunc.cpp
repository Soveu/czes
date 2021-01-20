#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "gamefunc.h"

#ifndef __unix__
#include <windows.h>
#endif // __unix__


using namespace std;


void initboard(figura board[8][8],int tryb)
{
    //tryb 1 - wczytanie nowej tablicy //tryb 2 - wczytanie z pgn
    if(tryb==1)
    {
        board[0][0].fig='T';
        board[0][0].tim=1;
        board[0][1].fig='N';
        board[0][1].tim=1;
        board[0][2].fig='B';
        board[0][2].tim=1;
        board[0][3].fig='Q';
        board[0][3].tim=1;
        board[0][4].fig='K';
        board[0][4].tim=1;
        board[0][5].fig='B';
        board[0][5].tim=1;
        board[0][6].fig='N';
        board[0][6].tim=1;
        board[0][7].fig='T';
        board[0][7].tim=1;

        for(int i=0; i<8; i++)
        {
            board[1][i].fig='P';
            board[1][i].tim=1;
        }

        for(int i=2; i<6; i++)
        {
            for(int j=0; j<8; j++)
            {
                board[i][j].fig=' ';
                board[i][j].tim=-1;
            }
        }

        board[7][0].fig='T';
        board[7][0].tim=2;
        board[7][1].fig='N';
        board[7][1].tim=2;
        board[7][2].fig='B';
        board[7][2].tim=2;
        board[7][3].fig='Q';
        board[7][3].tim=2;
        board[7][4].fig='K';
        board[7][4].tim=2;
        board[7][5].fig='B';
        board[7][5].tim=2;
        board[7][6].fig='N';
        board[7][6].tim=2;
        board[7][7].fig='T';
        board[7][7].tim=2;

        for(int i=0; i<8; i++)
        {
            board[6][i].fig='P';
            board[6][i].tim=2;
        }
    }
    else if(tryb==2)
    {

    }
    else
    {
        cout<<"Bledny tryb"<<endl;

    }

}

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/)
{
    int i=1;
#ifndef __unix__
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

#ifdef __unix__
    // cout<<"\033[50:10x20";
#endif // WIN32
    if(tryb==1)
        printf("  a b c d e f g h\n");
    else
        printf("  h g f e d c b a\n");

    for(int y=0; y<8; y++)
    {
        i--;
        printf("%d|",tryb==1 ? 8-(y) : y+1);
        for(int x=0; x<8; x++)
        {
            if(i%2==1)
            {
#ifndef __unix__
                if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==1)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                else if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==2)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
#endif
#ifdef __unix__

                if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==1)
                    cout<<"\u001b[37m\u001b[41m";//white
                else if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==2)
                    cout<<"\u001b[30m\u001b[41m";//black
                else
                    cout<<"\u001b[41m";
#endif // WIN32

            }
            else
            {
#ifdef WIN32
                if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==1)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN| BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
                else if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==2)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
#endif
#ifndef WIN32
                if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==1)
                    cout<<"\u001b[37m\u001b[45m";//white
                else if(board[tryb==1?7-y:y][tryb==0?7-x:x].tim==2)
                    cout<<"\u001b[30m\u001b[45m";//black
                else
                    cout<<"\u001b[45m";
#endif // WIN32

            }
            i++;

            printf("%c ",board[tryb==1?7-y:y][tryb==0?7-x:x].fig);
        }
#ifdef WIN32
        SetConsoleTextAttribute(hConsole, 0x7);
#endif // WIN32
#ifndef WIN32
        cout<<"\u001b[0m";

#endif // WIN32


        printf("\n");
    }
}

int isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4])
{
    if(board[yP][xP].fig==' ')
        return 0;


    if(yP<0||xP<0||yK>7||xK>7||yK<0||xK<0||yP>7||xP>7)
        return 0;

    if(board[yP][xP].tim==board[yK][xK].tim)
        return 0;

    /////pionek
    if(board[yP][xP].fig=='P')
    {
        /////jesli bije
        if(board[yK][xK].tim!=-1&&board[yK][xK].tim!=board[yP][xP].tim)
        {
            if(abs(yK-yP)!=1||abs(xK-xP)!=1)
                return 0;

        }////jesli nie bije
        else if( (board[yP][xP].tim==1)?(yP==1):(yP==6))
        {
            if(abs(yK-yP)>2||xP!=xK)
                return 0;

            if(abs(yK-yP)==2)
                if(board[yK>yP ? yK-1 : yK+1][xP].fig!=' '||xP!=xK)
                    return 0;
        }
        else
        {
            if(abs(yK-yP)>1||xP!=xK)
                return 0;
        }
    }////wieza
    else if(board[yP][xP].fig=='T')
    {
        if(yP!=yK&&xP!=xK)
            return 0;

        //pionowo-góra
        for(int i=yP-1; i>yK; i--)
        {
            if(board[i][xP].fig!=' ')
                return 0;
        }
        //pionowo-dół
        for(int i=yP+1; i<yK; i++)
        {
            if(board[i][xP].fig!=' ')
                return 0;
        }
        //poziomo-lewo
        for(int i=xP-1; i>xK; i--)
        {
            if(board[yP][i].fig!=' ')
                return 0;
        }
        //poziomo-prawo
        for(int i=xP+1; i<xK; i++)
        {
            if(board[yP][i].fig!=' ')
                return 0;
        }
    }////goniec
    else if(board[yP][xP].fig=='B')
    {
        if(abs(yK-yP)!=abs(xK-xP))
            return 0;

        //lewo-góra
        if(yK-yP<0&&xK-xP<0)
        {
            for(int i=1; i<abs(yK-yP); i++)
            {
                if(board[yP-i][xP-i].fig!=' ')
                    return 0;
            }
        }
        else if(yK-yP<0&&xK-xP>0)
        {
            //prawo-góra
            for(int i=1; i<abs(yK-yP); i++)
            {
                if(board[yP-i][xP+i].fig!=' ')
                    return 0;
            }
        }
        else if(yK-yP>0&&xK-xP<0)
        {
            //lewo-dół
            for(int i=1; i<abs(yK-yP); i++)
            {
                if(board[yP+i][xP-i].fig!=' ')
                    return 0;
            }
        }
        else
        {
            //prawo-dół
            for(int i=1; i<abs(yK-yP); i++)
            {
                if(board[yP+i][xP+i].fig!=' ')
                    return 0;
            }
        }
    }////kun
    else if(board[yP][xP].fig=='N')
    {
        if(abs(xK-xP)==2)
        {
            if(abs(yK-yP)!=1)
                return 0;
        }
        else if(abs(xK-xP)==1)
        {
            if(abs(yK-yP)!=2)
                return 0;
        }
        else
        {
            return 0;
        }

    }////krolowa
    else if(board[yP][xP].fig=='Q')
    {
        if(yP!=yK&&xP!=xK)
            if(abs(yK-yP)!=abs(xK-xP))
                return 0;

        if(xP==xK||yP==yK)
        {
            //pionowo-góra
            for(int i=yP-1; i>yK; i--)
            {
                if(board[i][xP].fig!=' ')
                    return 0;
            }
            //pionowo-dół
            for(int i=yP+1; i<yK; i++)
            {
                if(board[i][xP].fig!=' ')
                    return 0;
            }
            //poziomo-lewo
            for(int i=xP-1; i>xK; i--)
            {
                if(board[yP][i].fig!=' ')
                    return 0;
            }
            //poziomo-prawo
            for(int i=xP+1; i<xK; i++)
            {
                if(board[yP][i].fig!=' ')
                    return 0;
            }
        }
        else
        {
            //lewo-góra
            if(yK-yP<0&&xK-xP<0)
            {
                for(int i=1; i<abs(yK-yP); i++)
                {
                    if(board[yP-i][xP-i].fig!=' ')
                        return 0;
                }
            }
            else if(yK-yP<0&&xK-xP>0)
            {
                //prawo-góra
                for(int i=1; i<abs(yK-yP); i++)
                {
                    if(board[yP-i][xP+i].fig!=' ')
                        return 0;
                }
            }
            else if(yK-yP>0&&xK-xP<0)
            {
                //lewo-dół
                for(int i=1; i<abs(yK-yP); i++)
                {
                    if(board[yP+i][xP-i].fig!=' ')
                        return 0;
                }
            }
            else
            {
                //prawo-dół
                for(int i=1; i<abs(yK-yP); i++)
                {
                    if(board[yP+i][xP+i].fig!=' ')
                        return 0;
                }
            }
        }
    }////krol
    else
    {
        //castle[0]==e8g8, castle[1]==e8c8, castle[2]==e1g1, castle[3]=e1c1
        //roszada 04-06 04-02 74-76 74-72
        if(yP==0&&yK==0)
        {
            if(xP==4&&xK==6)
            {
                if(cas[2]==1)
                {
                    for(int i=1; xP+i<7; i++)
                    {
                        if(board[yP][xP+i].fig!=' ')
                            return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else if(xP==4&&xK==2)
            {
                if(cas[3]==1)
                {
                    for(int i=1; xP-i>0; i++)
                    {
                        if(board[yP][xP-i].fig!=' ')
                            return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
        else if(yP==7&&yK==7)
        {
            if(xP==4&&xK==6)
            {
                if(cas[0]==1)
                {
                    for(int i=1; xP+i<7; i++)
                    {
                        if(board[yP][xP+i].fig!=' ')
                            return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else if(xP==4&&xK==2)
            {
                if(cas[1]==1)
                {
                    for(int i=1; xP-i>0; i++)
                    {
                        if(board[yP][xP-i].fig!=' ')
                            return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }//zwykly ruch
        else if(abs(yK-yP)>1||abs(xK-xP)>1)
            return 0;
    }

    return 1;
}

int isChecked(int yKing, int xKing, figura board[8][8])
{
    //krolowie
    int yr[]= {-1,-1,-1,0,1,1, 1, 0};
    int xr[]= {-1, 0, 1,1,1,0,-1,-1};

    for(int i=0; i<8; i++)
    {
        if(yKing+yr[i]>=0&&xKing+xr[i]>=0&&yKing+yr[i]<8&&xKing+xr[i]<8)
        {
            if(board[yKing+yr[i]][xKing+xr[i]].fig=='K')
                return 1;
        }
    }
    //piony
    if(board[yKing][xKing].tim==2) // jesli krol jest czarny
    {
        if(yKing<8)
        {
            if(xKing>1)
                if(board[yKing+1][xKing-1].fig=='P'&&board[yKing+1][xKing-1].tim==1)
                    return 1;

            if(xKing<8)
                if(board[yKing+1][xKing+1].fig=='P'&&board[yKing+1][xKing+1].tim==1)
                    return 1;
        }
    }
    else       // jesli krol jest bialy
    {
        if(yKing>1)
        {
            if(xKing>1)
                if(board[yKing-1][xKing-1].fig=='P'&&board[yKing-1][xKing-1].tim==2)
                    return 1;

            if(xKing<8)
                if(board[yKing-1][xKing+1].fig=='P'&&board[yKing-1][xKing+1].tim==2)
                    return 1;
        }
    }
    // pionowo-góra
    for(int y=yKing-1; y>=0; y--)
    {
        if(board[y][xKing].fig!=' ')
        {
            if(board[y][xKing].tim==board[yKing][xKing].tim)
                break;
            else if(board[y][xKing].fig=='T'||board[y][xKing].fig=='Q')
                return 1;
            else
                break;
        }
    }
    // pionowo-dół
    for(int y=yKing+1; y<8; y++)
    {
        if(board[y][xKing].fig!=' ')
        {
            if(board[y][xKing].tim==board[yKing][xKing].tim)
                break;
            else if(board[y][xKing].fig=='T'||board[y][xKing].fig=='Q')
                return 1;
            else
                break;
        }
    }
    // poziomo-prawo
    for(int x=xKing+1; x<8; x++)
    {
        if(board[yKing][x].fig!=' ')
        {
            if(board[yKing][x].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing][x].fig=='T'||board[yKing][x].fig=='Q')
                return 1;
            else
                break;
        }
    }
    // ppoziomo-lewo
    for(int x=xKing-1; x>=0; x--)
    {
        if(board[yKing][x].fig!=' ')
        {
            if(board[yKing][x].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing][x].fig=='T'||board[yKing][x].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //góra-lewo
    for(int i=1; yKing-i>=0&&xKing-i>=0; i++)
    {
        if(board[yKing-i][xKing-i].fig!=' ')
        {
            if(board[yKing-i][xKing-i].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing-i][xKing-i].fig=='B'||board[yKing-i][xKing-i].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //góra-prawo
    for(int i=1; yKing-i>=0&&xKing+i<8; i++)
    {
        if(board[yKing-i][xKing+i].fig!=' ')
        {
            if(board[yKing-i][xKing+i].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing-i][xKing+i].fig=='B'||board[yKing-i][xKing+i].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //dół-lewo
    for(int i=1; yKing+i<8&&xKing-i>=0; i++)
    {
        if(board[yKing+i][xKing-i].fig!=' ')
        {
            if(board[yKing+i][xKing-i].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing+i][xKing-i].fig=='B'||board[yKing+i][xKing-i].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //dół-prawo
    for(int i=1; yKing+i<8&&xKing+i<8; i++)
    {
        if(board[yKing+i][xKing+i].fig!=' ')
        {
            if(board[yKing+i][xKing+i].tim==board[yKing+i][xKing+i].tim)
                break;
            else if(board[yKing+i][xKing+i].fig=='B'||board[yKing+i][xKing+i].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //kunie
    int ruchY[] = {1, 1,-1,-1,2,-2, 2,-2};
    int ruchX[] = {2,-2, 2,-2,1, 1,-1,-1};

    for(int i=0; i<8; i++)
    {
        if(xKing+ruchX[i]<8&&xKing+ruchX[i]>=0&&yKing+ruchY[i]<8&&yKing+ruchY[i]>=0)
        {
            if(board[yKing+ruchY[i]][xKing+ruchX[i]].fig=='N')
                if(board[yKing+ruchY[i]][xKing+ruchX[i]].tim!=board[yKing][xKing].tim)
                    return 1;
        }
    }
    return 0;
}

int isMating(int yKing, int xKing, figura board[8][8])
{
    int castle[]= {0,0,0,0};
    int timK=board[yKing][xKing].tim;
    figura temp= {' ',-1};
    for(int yp=0; yp<8; yp++)
    {
        for(int xp=0; xp<8; xp++)
        {
            if(board[yp][xp].tim==timK)
            {
                for(int yk=0; yk<8; yk++)
                {
                    for(int xk=0; xk<8; xk++)
                    {
                        if(isLegal(board,yp,xp,yk,xk,castle))
                        {
                            temp.fig=board[yk][xk].fig;
                            temp.tim=board[yk][xk].tim;
                            board[yk][xk].fig=board[yp][xp].fig;
                            board[yk][xk].tim=board[yp][xp].tim;
                            board[yp][xp].fig=' ';
                            board[yp][xp].tim=-1;

                            if(isChecked(yKing,xKing,board)==0)
                            {
                                board[yp][xp].fig=board[yk][xk].fig;
                                board[yp][xp].tim=board[yk][xk].tim;
                                board[yk][xk].fig=temp.fig;
                                board[yk][xk].tim=temp.tim;
                                return 0;
                            }
                            else
                            {
                                board[yp][xp].fig=board[yk][xk].fig;
                                board[yp][xp].tim=board[yk][xk].tim;
                                board[yk][xk].fig=temp.fig;
                                board[yk][xk].tim=temp.tim;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int inputMove(char *xP,char *yP,char *xK,char *yK,int mode)
{
    char input[4];
    if(mode==0) //mode==0 - gra lokalna
    {
        cin>>input;
        *xP=input[0];
        *yP=input[1];
        *xK=input[2];
        *yK=input[3];

        return 1;
    }
    else if(mode==1) //mode==1 - gra sieciowa
    {
        //costamcsotam
        //costamcostam
        return 1;
    }
    else
    {
        cout<<"bledny tryb"<<endl;
        return 0;
    }
}

int chessGame(int mode)
{
    figura board[8][8];
    cout<<"Zaczynamy gre"<<endl;
    int czywczytac,display;


    /////inicjalizacja szachownicy//////
    cout<<"Instrukcje:"<<endl<<"Aby poruszyc sie figura nalezy wpisac koordynaty poczatku ruchu i końca np \"a2a4\", malymi literami, razem"<<endl;
    cout<<"Zeby poprosic o remis wpisz \"draw\""<<endl;
    cout<<"Zeby przerwac gre z mozliwoscia kontynuacji wpisz \"stop\""<<endl;
    cout<<"Zeby zakonczyc gre bez zapisywania wpisz \"quit\""<<endl;
    cout<<"Zeby poddac sie wpisz \"surr\""<<endl<<endl;
    cout<<"Chcesz rozpoczac nowa gre, czy kontynuowac zapisana rozgrywke?"<<endl<<"1 - nowa gra, 2 - zapisana gra"<<endl;
    cin>>czywczytac;
    cout<<"Perspektywa 1 - biale, 2 - czarne"<<endl;
    cin>>display;
    initboard(board,czywczytac);

#ifdef WIN32
    system("cls");
#endif // WIN32
#ifndef WIN32
    cout<<"\u001b[2J\033[0;0H\033[0;0H";
#endif // WIN32

    printBoard(board,display);

    cout<<"Ruch bialego"<<endl;

    char xPc,xKc,yPc,yKc;
    int xP, xK, yP, yK;
    int tura=1;
    int posKing[4]= {0,4,7,4}; //////yWhite=0,xWhite=1,yBlack=2,xBlack=3
    int castle[4]= {1,1,1,1}; ///////castle[0]==e8g8, castle[1]==e8c8, castle[2]==e1g1, castle[3]=e1c1
    figura temp;

    while(1) //gameloop
    {
        inputMove(&xPc,&yPc,&xKc, &yKc,mode);

        if(xPc=='d'&&yPc=='r'&&xKc=='a'&&yKc=='w')
        {
            printf("remis!!!\n");
            break;
        }
        if(xPc=='q'&&yPc=='u'&&xKc=='i'&&yKc=='t')
        {
            printf("koniec gry!!!\n");
            break;
        }

        if(xPc=='w'&&yPc=='t'&&xKc=='o'&&yKc=='p')
        {
            printf("gra przerwana!!\n");
            break;
        }

        xP=xPc-97;
        xK=xKc-97;
        yP=yPc-49;
        yK=yKc-49;

        if(yP<0||yP>7||yK<0||yK>7||xP<0||xP>7||xK<0||xK>7)
        {
            cout<<"Bledny ruch"<<endl;
            continue;
        }

        if(board[yP][xP].tim!=tura)
        {
            cout<<"To nie twoja figura"<<endl;
            continue;
        }

        if(isLegal(board,yP,xP,yK,xK,castle)==1)
        {
            /////zmiana pozycji króla
            if(board[yP][xP].fig=='K')
            {
                if(tura==1)
                {
                    posKing[0]=yK;
                    posKing[1]=xK;
                }
                else
                {
                    posKing[2]=yK;
                    posKing[3]=xK;
                }
            }

            ////przesuniecie figur
            temp.fig=board[yK][xK].fig;
            temp.tim=board[yK][xK].tim;
            board[yK][xK].fig=board[yP][xP].fig;
            board[yK][xK].tim=board[yP][xP].tim;
            board[yP][xP].fig=' ';
            board[yP][xP].tim=-1;

            ////sprawdzenie czy jest szach, cofniecie ruchu jesli tak
            if(isChecked(posKing[tura==1?0:2],posKing[tura==1?1:3],board)==1)
            {
                board[yP][xP].fig=board[yK][xK].fig;
                board[yP][xP].tim=board[yK][xK].tim;
                board[yK][xK].fig=temp.fig;
                board[yK][xK].tim=temp.tim;
                cout<<"Twoj krol bylby szachowany"<<endl;

                if(board[yP][xP].fig=='K')
                {
                    posKing[tura==1?0:2]=yP;
                    posKing[tura==1?1:3]=xP;

                }
            }
            else
            {
                /////////roszady - wylaczenie
                if(board[yK][xK].fig=='T')
                {
                    if(xP==0)
                        castle[tura==1?3:1]=0;
                    if(xP==7)
                        castle[tura==1?2:0]=0;
                }
                if(board[yK][xK].fig=='K')
                {
                    castle[tura==1?3:1]=0;
                    castle[tura==1?2:1]=0;
                }
                /////////roszady - wykonanie dla bialych
                if(yP==0&&xP==4&&board[yK][xK].fig=='K')
                {
                    if(yK==0&&xK==6)
                    {
                        board[0][5].fig='T';
                        board[0][5].tim=1;
                        board[0][7].fig=' ';
                        board[0][7].tim=-1;
                    }
                    else if(yK==0&&xK==2)
                    {
                        board[0][3].fig='T';
                        board[0][3].tim=1;
                        board[0][0].fig=' ';
                        board[0][0].tim=-1;
                    }
                }////////roszady - wykonanie dla czarnych
                else if(yP==7&&xP==4&&board[yK][xK].fig=='K')
                    {
                        if(yK==7&&xK==6)
                        {
                            board[7][5].fig='T';
                            board[7][5].tim=2;
                            board[7][7].fig=' ';
                            board[7][7].tim=-1;
                        }
                        else if(yK==7&&xK==2)
                        {
                            board[7][3].fig='T';
                            board[7][3].tim=2;
                            board[7][0].fig=' ';
                            board[7][0].tim=-1;
                        }
                    }

#ifdef WIN32
                system("cls");
#endif // WIN32
#ifndef WIN32
                cout<<"\u001b[2J\033[0;0H";
#endif // WIN32
                printBoard(board,display);

                /////zamiana pionka po dojsciu na koniec planszy
                if(yK==(tura==1?7:0)&&board[yK][xK].fig=='P')
                {
                    char f;
                    cout<<"Na jaka figure chcesz zamienic swojego pionka?"<<endl;
                    while(1)
                    {
                        cin>>f;
                        if(f=='T')
                        {
                            board[yK][xK].fig='T';
                            break;
                        }
                        else if(f=='B')
                        {
                            board[yK][xK].fig='B';
                            break;
                        }
                        else if(f=='N')
                        {
                            board[yK][xK].fig='N';
                            break;
                        }
                        else if(f=='Q')
                        {
                            board[yK][xK].fig='Q';
                            break;
                        }
                        else
                        {
                            cout<<"Bledna figura"<<endl;
                        }
                    }
                }
#ifdef WIN32
                system("cls");
#endif // WIN32
#ifndef WIN32
                cout<<"\u001b[2J\033[0;0H";
#endif // WIN32
                printBoard(board,display);


                //Sprawdzenie szacha i mata
                if(isChecked(posKing[tura==1?2:0],posKing[tura==1?3:1],board)==1)
                {
                    if(isMating(posKing[tura==1?2:0],posKing[tura==1?3:1],board)==1)
                        cout<<"Szach i mat!"<<endl;
                    else
                        cout<<"Szach!"<<endl;
                }
                if(tura==1)
                {
                    tura++;
                    cout<<"Ruch czarnego"<<endl;
                }
                else
                {
                    tura--;
                    cout<<"Ruch bialego"<<endl;
                }
            }
        }
        else
        {
            cout<<"Nielegalny ruch!!!"<<endl;
        }
    }

    return 1;
}
