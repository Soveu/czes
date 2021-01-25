#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#ifndef __unix__
#include <windows.h>
#endif // __unix__

#include "grytreningowe.cpp"

void initboard(figura board[8][8],int tryb)
{
    //tryb 1 - wczytanie nowej tablicy //tryb 2 - wczytanie z PGN
    if(tryb==2)
    {
        /////////////////////////////////////////////MIEJSCE NA IMPORT Z PGN////////////////////////////////////////
        //mozesz napisac calosc importu tutaj, mozesz napisac osobne funkcje i w tym miejscu ich uzywac jak wolisz//
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        //																										  //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else
    {
        board[0][0].fig='R';
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
        board[0][7].fig='R';
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

        board[7][0].fig='R';
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
        board[7][7].fig='R';
        board[7][7].tim=2;

        for(int i=0; i<8; i++)
        {
            board[6][i].fig='P';
            board[6][i].tim=2;
        }
    }
}

void printBoard(figura board[8][8],int tryb /*1==biale 0==czarne*/)
{
    int i=1;
#ifndef __unix__
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
#endif

#ifdef __unix__

    const char* WHITE_BG = "\033[48;5;180m";
    const char* BLACK_BG = "\033[48;5;94m";

    const char* WHITE_FG = "\033[38;5;254m";
    const char* BLACK_FG = "\033[38;5;235m";

    const char* CLEAR = "\u001b[0m";

    std::cout<<"\u001b[2J\033[0;0H\033[0;0H";

    const char* PIECES[7] =
    {
        " ",//0
        "♟",//1
        "♝",//2
        "♞",//3
        "♜",//4
        "♛",//5
        "♚",//6
    };

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
                if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==1)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                else if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==2)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
#endif
#ifdef __unix__

                std::cout<<BLACK_BG;
                if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==1)
                    std::cout<<WHITE_FG;//white
                else if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==2)
                    std::cout<<BLACK_FG;//black
#endif

            }
            else
            {
#ifndef __unix__
                if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==1)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN| BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
                else if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==2)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
#endif
#ifdef __unix__
                std::cout<<WHITE_BG;
                if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==1)
                    std::cout<<WHITE_FG;//white
                else if(board[tryb==1?7-y:y][tryb==1?x:7-x].tim==2)
                    std::cout<<BLACK_FG;//black

#endif
            }
            i++;
#ifndef __unix__
            std::cout<<board[tryb==1?7-y:y][tryb==1?x:7-x].fig<<" ";
#endif

#ifdef __unix__

            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig==' ')
                std::cout<<PIECES[0]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='P')
                std::cout<<PIECES[1]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='B')
                std::cout<<PIECES[2]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='N')
                std::cout<<PIECES[3]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='R')
                std::cout<<PIECES[4]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='Q')
                std::cout<<PIECES[5]<<" ";
            if(board[tryb==1?7-y:y][tryb==1?x:7-x].fig=='K')
                std::cout<<PIECES[6]<<" ";
#endif
        }
#ifndef __unix__
        SetConsoleTextAttribute(hConsole, 0x7);
#endif
#ifdef __unix__
        std::cout<<CLEAR;
#endif

        std::cout<<"\n";
    }
}

bool isLegal(figura board[8][8],int yP,int xP,int yK,int xK,int cas[4],savedMove saved)
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
            if(board[yP][xP].tim==1)
            {
                if(yK-yP!=1||abs(xK-xP)!=1)
                    return 0;
            }
            else
            {
                if(yP-yK!=1||abs(xK-xP)!=1)
                    return 0;
            }

        }////en passant
        else if(((board[yP][xP+1].fig=='P')&&(board[yP][xP+1].tim!=board[yP][xP].tim)&&xP!=xK)||((board[yP][xP-1].fig=='P')&&(board[yP][xP-1].tim!=board[yP][xP].tim)&&xP!=xK))
        {
            if(saved.fig!='P')
                return 0;
            else if(abs(saved.coords[0]-saved.coords[2])!=2)
                return 0;
            else if(saved.coords[1]!=xK)
                return 0;
        }////jesli nie bije
        else if((board[yP][xP].tim==1)?(yP==1):(yP==6))
        {
            if(board[yP][xP].tim==1)
            {
                if(yK-yP>2||xP!=xK)
                    return 0;

                if(yK-yP==2)
                    if(board[yK>yP ? yK-1 : yK+1][xP].fig!=' '||xP!=xK)
                        return 0;

                if(yK<yP)
                    return 0;
            }
            else
            {
                if(yP-yK>2||xP!=xK)
                    return 0;

                if(yP-yK==2)
                    if(board[yK>yP ? yK-1 : yK+1][xP].fig!=' '||xP!=xK)
                        return 0;
                if(yP<yK)
                    return 0;
            }
        }
        else
        {
            if(xP!=xK)
                return 0;

            if(board[yP][xP].tim==1)
            {
                if(yP>yK)
                    return 0;

                if(yK-yP>1)
                    return 0;
            }
            else
            {
                if(yK>yP)
                    return 0;

                if(yP-yK>1)
                    return 0;
            }
        }
    }////wieza
    else if(board[yP][xP].fig=='R')
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
        if(yP==0&&yK==0&&isChecked(yP,xP,board)==false)
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
        else if(yP==7&&yK==7&&isChecked(yP,xP,board)==false)
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

bool isChecked(int yKing, int xKing, figura board[8][8])
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
    for(int y=yKing+1; y<8; y++)
    {
        if(board[y][xKing].fig!=' ')
        {
            if(board[y][xKing].tim==board[yKing][xKing].tim)
                break;
            else if(board[y][xKing].fig=='R'||board[y][xKing].fig=='Q')
                return 1;
            else
                break;
        }
    }
    // pionowo-dół
    for(int y=yKing-1; y>=0; y--)
    {
        if(board[y][xKing].fig!=' ')
        {
            if(board[y][xKing].tim==board[yKing][xKing].tim)
                break;
            else if(board[y][xKing].fig=='R'||board[y][xKing].fig=='Q')
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
            else if(board[yKing][x].fig=='R'||board[yKing][x].fig=='Q')
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
            else if(board[yKing][x].fig=='R'||board[yKing][x].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //góra-lewo
    for(int i=1; yKing+i>=0&&xKing-i>=0; i++)
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
    //góra-prawo
    for(int i=1; yKing+i>=0&&xKing+i<8; i++)
    {
        if(board[yKing+i][xKing+i].fig!=' ')
        {
            if(board[yKing+i][xKing+i].tim==board[yKing][xKing].tim)
                break;
            else if(board[yKing+i][xKing+i].fig=='B'||board[yKing+i][xKing+i].fig=='Q')
                return 1;
            else
                break;
        }
    }
    //dół-lewo
    for(int i=1; yKing-i<8&&xKing-i>=0; i++)
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
    //dół-prawo
    for(int i=1; yKing-i<8&&xKing+i<8; i++)
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

bool isMating(int yKing, int xKing, figura board[8][8])
{
    savedMove saved= {' ',-1,0,0,0,0,false,false,false};
    int castle[4]= {0,0,0,0};
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
                        if(isLegal(board,yp,xp,yk,xk,castle,saved))
                        {
                            temp.fig=board[yk][xk].fig;
                            temp.tim=board[yk][xk].tim;
                            board[yk][xk].fig=board[yp][xp].fig;
                            board[yk][xk].tim=board[yp][xp].tim;
                            board[yp][xp].fig=' ';
                            board[yp][xp].tim=-1;
                            if(board[yk][xk].fig=='K')
                            {
                                yKing=yk;
                                xKing=xk;
                            }

                            if(isChecked(yKing,xKing,board)==false)
                            {
                                board[yp][xp].fig=board[yk][xk].fig;
                                board[yp][xp].tim=board[yk][xk].tim;
                                board[yk][xk].fig=temp.fig;
                                board[yk][xk].tim=temp.tim;
                                std::cout<<yp<<" "<<xp<<" "<<yk<<" "<<xk<<"\n";
                                return false;
                            }
                            else
                            {
                                board[yp][xp].fig=board[yk][xk].fig;
                                board[yp][xp].tim=board[yk][xk].tim;
                                board[yk][xk].fig=temp.fig;
                                board[yk][xk].tim=temp.tim;
                            }
                            if(board[yp][xp].fig=='K')
                            {
                                yKing=yp;
                                xKing=xp;
                            }

                        }
                    }
                }
            }
        }
    }
    return true;
}

void inputMove(char *xP,char *yP,char *xK,char *yK,bool local)
{
    char input[4];
    if(local) // gra lokalna
    {
        std::cin>>input;
        *xP=input[0];
        *yP=input[1];
        *xK=input[2];
        *yK=input[3];
    }
    else    // gra sieciowa
    {
        //costamcsotam
        //costamcostam
    }
}

void outputMsg(bool local,int mesydz, int tim)
{
    if(local)//gra lokalna
    {
        switch(mesydz)
        {
        case 1: //Nielegalny ruch
            std::cout<<"Bledny ruch\n";
            break;
        case 2: //Ruch przeciwnika
            if(tim==2)
                std::cout<<"Ruch czarnego\n";
            else
                std::cout<<"Ruch bialego\n";
            break;
        case 3: //Szach
            std::cout<<"Szach!\n";
            break;
        case 4: //Szach i mat
            std::cout<<"Szach i mat!\n";
            break;
        case 5: //zamiana pionka
            std::cout<<"Na jaka figure chcesz zamienic swojego pionka?\n";
            break;
        case 6: //bledna figura
            std::cout<<"Bledna figura\n";
            break;
        case 7: //remis
            std::cout<<"Gra zakonczona remisem\n";
            std::cout<<"Czy chcesz zapisac rozgrywke? T/N\n";
            break;
        case 8://gra przerwana
            std::cout<<"Gra przerwana\n";
            std::cout<<"Czy chcesz zapisac rozgrywke? T/N\n";
            break;
        case 9: //wygrana bialych
            std::cout<<"Wygrywa bialy\n";
            std::cout<<"Czy chcesz zapisac rozgrywke? T/N\n";
            break;
        case 10: //wygrana czarnych
            std::cout<<"Wygrywa czarny\n";
            std::cout<<"Czy chcesz zapisac rozgrywke? T/N\n";
            break;
        case 11:
            break;
        }
    }
    else //gra sieciowa
    {

    }
}

void inputMsg(bool local, int ktora, int *mesydz, char *msg)
{
    if(local)
    {
        char f;
        int n;
        if(ktora==1)
        {
            //////////////char
            std::cin>>f;
            *msg=f;
            return;
        }
        else
        {
            //////////////int
            std::cin>>n;
            *mesydz=n;
            return;
        }
    }
    else
    {

    }
}


int chessGame(bool mode, int czywczytac, int display)
{
    figura board[8][8];
    std::ofstream plik;
    std::ostringstream dane;
    std::ostringstream nazwapliku;
    std::string edycja;
    int licznik=1;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    ////plik PGN

    nazwapliku<<1900+ltm->tm_year;
    nazwapliku<<"-";
    nazwapliku<< 1+ltm->tm_mon;
    nazwapliku<<"-";
    nazwapliku<< ltm->tm_mday;
    nazwapliku<<"-";
    nazwapliku<<ltm->tm_hour;
    nazwapliku<<"-";
    nazwapliku<<ltm->tm_min;
    nazwapliku<<"-";
    nazwapliku<<ltm->tm_sec;
    nazwapliku<<".pgn";
    plik.open(nazwapliku.str());

    ////zapisywanie tagow PGN

    dane<<"[Event \"-\"]\n";
    dane<<"[Site \"-\"]\n";
    dane<<"[Date \"";
    dane<<1900+ltm->tm_year;
    dane<<".";
    dane<< 1+ltm->tm_mon;
    dane<< ".";
    dane<< ltm->tm_mday;
    dane<< "\"]\n";
    dane<<"[Round \"-\"]\n";
    dane<< "[White \"bialy\"]\n";
    dane<< "[Black \"czarny\"]\n";
    dane<< "[Result \"*\"]\n\n";

    initboard(board,czywczytac);

    printBoard(board,display);

    char xPc,xKc,yPc,yKc;
    int xP, xK, yP, yK;
    int tura=1;
    int posKing[4]= {0,4,7,4}; //////yWhite=0,xWhite=1,yBlack=2,xBlack=3
    int castle[4]= {1,1,1,1}; ///////castle[0]==e8g8, castle[1]==e8c8, castle[2]==e1g1, castle[3]=e1c1
    char odp;
    figura temp;
    savedMove prevMove= {' ',-1,0,0,1,0,false,false,false};

    outputMsg(mode,2,tura);



    while(1) //gameloop
    {
        inputMove(&xPc,&yPc,&xKc, &yKc,mode);

        // Komendy na przerwanie gry - surr, quit, stop, draw
        if(xPc=='d'&&yPc=='r'&&xKc=='a'&&yKc=='w')
        {
            outputMsg(mode,7,tura);
            inputMsg(mode,1,NULL,&odp);////<-------------zapytanie o zapisanie do PGN
            if(odp=='T')
            {
                plik<<dane.str();
                plik.flush();
            }


            break;
        }
        if(xPc=='q'&&yPc=='u'&&xKc=='i'&&yKc=='t')
        {
            outputMsg(mode,8,tura);
            inputMsg(mode,1,NULL,&odp);////<-------------zapytanie o zapisanie do PGN
            if(odp=='T')
            {
                plik<<dane.str();
                plik.flush();
            }


            break;
        }
        if(xPc=='s'&&yPc=='u'&&xKc=='r'&&yKc=='r')
        {
            outputMsg(mode,(tura==1?10:9),tura);
            inputMsg(mode,1,NULL,&odp);////<-------------zapytanie o zapisanie do PGN
            if(odp=='T')
            {
                plik<<dane.str();
                plik.flush();
            }


            break;
        }

        xP=xPc-97;
        xK=xKc-97;
        yP=yPc-49;
        yK=yKc-49;

        if(board[yP][xP].tim!=tura)
        {
            outputMsg(mode,1,tura);
            continue;
        }

        if(isLegal(board,yP,xP,yK,xK,castle,prevMove))
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
            if(isChecked(posKing[tura==1?0:2],posKing[tura==1?1:3],board))
            {
                board[yP][xP].fig=board[yK][xK].fig;
                board[yP][xP].tim=board[yK][xK].tim;
                board[yK][xK].fig=temp.fig;
                board[yK][xK].tim=temp.tim;
                outputMsg(mode,1,tura);

                if(board[yP][xP].fig=='K')
                {
                    posKing[tura==1?0:2]=yP;
                    posKing[tura==1?1:3]=xP;
                }
            }
            else
            {
                /////////roszady - wylaczenie
                if(board[yK][xK].fig=='R')
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
                        board[0][5].fig='R';
                        board[0][5].tim=1;
                        board[0][7].fig=' ';
                        board[0][7].tim=-1;
                    }
                    else if(yK==0&&xK==2)
                    {
                        board[0][3].fig='R';
                        board[0][3].tim=1;
                        board[0][0].fig=' ';
                        board[0][0].tim=-1;
                    }
                }////////roszady - wykonanie dla czarnych
                else if(yP==7&&xP==4&&board[yK][xK].fig=='K')
                {
                    if(yK==7&&xK==6)
                    {
                        board[7][5].fig='R';
                        board[7][5].tim=2;
                        board[7][7].fig=' ';
                        board[7][7].tim=-1;
                    }
                    else if(yK==7&&xK==2)
                    {
                        board[7][3].fig='R';
                        board[7][3].tim=2;
                        board[7][0].fig=' ';
                        board[7][0].tim=-1;
                    }
                }

                ////wykonanie zbicia en passant
                if(temp.fig==' '&&board[yK][xK].fig=='P'&&xK!=xP)
                {
                    if(board[yK][xK].tim==1)
                    {
                        board[yK-1][xK].tim=-1;
                        board[yK-1][xK].fig=' ';
                    }
                    else
                    {
                        board[yK+1][xK].tim=-1;
                        board[yK+1][xK].fig=' ';
                    }
                    prevMove.passant=true;
                }
                else
                {
                    prevMove.passant=false;
                }

                printBoard(board,display);
                char f='x';
                /////zamiana pionka po dojsciu na koniec planszy
                if(yK==(tura==1?7:0)&&board[yK][xK].fig=='P')
                {

                    outputMsg(mode,5,tura);
                    while(1)
                    {
                        inputMsg(mode,1,NULL,&f);
                        if(f=='R')
                        {
                            board[yK][xK].fig='R';
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
                            outputMsg(mode,6,tura);
                        }
                    }
                    printBoard(board,display);
                }

                ////Zapisanie poprzedniego ruchu
                prevMove.fig=board[yK][xK].fig;
                prevMove.tim=board[yK][xK].tim;
                prevMove.coords[0]=yP;
                prevMove.coords[1]=xP;
                prevMove.coords[2]=yK;
                prevMove.coords[3]=xK;

                //Sprawdzenie szacha i mata
                if(isChecked(posKing[tura==1?2:0],posKing[tura==1?3:1],board))
                {
                    if(isMating(posKing[tura==1?2:0],posKing[tura==1?3:1],board))
                    {
                        outputMsg(mode,4,tura);
                        prevMove.mat=true;
                    }
                    else
                    {
                        outputMsg(mode,3,tura);
                        prevMove.szach=true;
                    }
                }
                else
                {
                    prevMove.szach=false;
                }

                ///////////////////////////MIEJSCE NA ZAPISANIE DO PGN(chyba tu)/////////////////////////////////////

                checkStar(edycja, dane);

                if(tura==1)
                {
                    dane<<licznik;
                    dane<<". ";
                }

                if(checkRoszada(prevMove)==true)
                {
                    roszadaMove(prevMove, dane, tura);
                }
                else
                {
                    if(temp.fig!=' ')
                    {
                        zbicieMove(prevMove, dane, tura, f);
                    }
                    else
                    {
                        basicMove(prevMove, dane, tura, f);
                    }
                }



                /////////////////////////////////////////////////////////////////////////////////////////////////////

                if(prevMove.mat)
                {
                    plik<<dane.str();
                    plik.flush();
                    outputMsg(mode,8+tura,tura);
                    inputMsg(mode,1,NULL,&odp);////<-------------zapytanie o zapisanie do PGN
                    break;
                }

                if(tura==1)
                    tura++;
                else
                    tura--;

                if(tura==2)
                    licznik+=1;


                outputMsg(true,2,tura);
            }
        }
        else
        {
            outputMsg(true,1,tura);
        }

    }
    plik.close();
    return 1;
}
bool checkRoszada(savedMove& prevMove)
{
    if(prevMove.coords[1]==4&&prevMove.fig=='K'&&(prevMove.coords[3]==2||prevMove.coords[3]==6))
        return 1;
    else
        return 0;
}

void roszadaMove(savedMove& prevMove, std::ostringstream &dane, int tura)
{
    if(prevMove.coords[3]==2)
    {
        dane<<"O-O-O";
    }
    if(prevMove.coords[3]==6)
    {
        dane<<"O-O";
    }
    if(prevMove.szach==false&&prevMove.mat==false)
    {
        dane<<" *";
    }
    if(prevMove.szach==true&&prevMove.mat==false)
    {
        dane<<"+";
        dane<<" *";
    }
    if(prevMove.mat==true)
    {
        if(tura==1)
            dane<<" 1-0";
        if(tura==2)
            dane<<" 0-1";
    }
}

void zbicieMove(savedMove& prevMove, std::ostringstream &dane, int tura, char f)
{
    switch(prevMove.fig)
    {
    case 'P':
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'N':
        dane<<"N";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'B':
        dane<<"B";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'R':
        dane<<"R";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'Q':
        dane<<"Q";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'K':
        dane<<"K";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<"x";
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    }
    if(f!='x')
    {
        dane<<"=";
        dane<<f;
    }
    if(prevMove.szach==false&&prevMove.mat==false)
    {
        dane<<" *";
    }
    if(prevMove.szach==true&&prevMove.mat==false)
    {
        dane<<"+";
        dane<<" *";
    }
    if(prevMove.mat==true)
    {
        if(tura==1)
            dane<<"# 1-0";
        if(tura==2)
            dane<<"# 0-1";
    }

}

void basicMove(savedMove& prevMove, std::ostringstream &dane, int tura, char f)
{
    switch(prevMove.fig)
    {
    case 'P':
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'N':
        dane<<"N";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'B':
        dane<<"B";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'R':
        dane<<"R";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'Q':
        dane<<"Q";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    case 'K':
        dane<<"K";
        dane<<converter(prevMove.coords[1]);
        dane<<prevMove.coords[0]+1;
        dane<<converter(prevMove.coords[3]);
        dane<<prevMove.coords[2]+1;
        break;
    }
    if(f!='x')
    {
        dane<<"=";
        dane<<f;
    }
    if(prevMove.szach==false&&prevMove.mat==false)
    {
        dane<<" *";
    }
    if(prevMove.szach==true&&prevMove.mat==false)
    {
        dane<<"+";
        dane<<" *";
    }
    if(prevMove.mat==true)
    {
        if(tura==1)
            dane<<"# 1-0";
        if(tura==2)
            dane<<"# 0-1";
    }
}

char converter(int znak)
{
    char a;
    if(znak==0)
        a='a';
    if(znak==1)
        a='b';
    if(znak==2)
        a='c';
    if(znak==3)
        a='d';
    if(znak==4)
        a='e';
    if(znak==5)
        a='f';
    if(znak==6)
        a='g';
    if(znak==7)
        a='h';
    return a;
}

void checkStar(std::string &edytowane, std::ostringstream &strim)
{
    edytowane=strim.str();
    if(edytowane[edytowane.length()-1]=='*')
    {
        edytowane.pop_back();
        strim.str("");
        strim.clear();
        strim<<edytowane;
    }

}
