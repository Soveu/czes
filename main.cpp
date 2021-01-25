#include <iostream>
#include <string>
#include <array>

#include <assert.h>

#include "definitions.cpp"
#include "gamefunc.cpp"


std::array<Position, 2> parse_position(const char* str, size_t len)
{
    assert(len == 4);

    assert(str[0] >= 'a' && str[0] <= 'z');
    assert(str[1] >= '1' && str[1] <= '9');
    assert(str[2] >= 'a' && str[2] <= 'z');
    assert(str[3] >= '1' && str[3] <= '9');

    return
    {
        Position { str[0] - 'a', str[1] - '1' },
        Position { str[2] - 'a', str[3] - '1' },
    };
}

bool string_starts_with(const std::string& s1, const char* s2)
{
    if(s2[0] == '\0')
    {
        return true;
    }
    if(s1.size() == 0)
    {
        return false;
    }

    for(size_t i=0; i<s1.size(); ++i)
    {
        if(s2[i] == '\0') return true;
        if(s2[i] != s1[i]) return false;
    }

    return false;
}

int main(int argc, const char* argv[])
{
    /*for(int i=1; i<argc; ++i) {
      std::cout << '"' << argv[i] << "\"\n";
    }

    Game game;
    game.clear_board();

    for(uint16_t i=0; i<5; i += 1) {
      for(uint16_t j=0; j<5; j += 1) {
        game.board[i][j] = Piece {
          static_cast<PieceColor>((i) % 2),
          PieceType::Rook
        };
      }
    }

    std::string line;
    for(;;) {
      std::cout << "Command: " << std::flush;
      if(!std::getline(std::cin, line)) break;

      if(line == "show") {
        game.draw_board();
        continue;
      }

      if(string_starts_with(line, "move ")) {
        if(line.size() <= 5) {
          break;
        }

        auto positions = parse_position(line.data() + 5, line.size() - 5);
        bool has_moved = game.move_piece(positions[0], positions[1]);
        std::cout << (has_moved ? "Piece was moved" : "Invalid move") << std::endl;

        continue;
      }

      if(line == "exit") break;
      std::cout << "Command not supported!" << std::endl;
    }
    */
    int odp,disp;
    bool cont=true;
    char od;
    std::cout<<"Wybierz tryb gry:\n 1 - hot-seat  2 - zagadki szachowe  3 - gra sieciowa 4 - wyjscie z programu\n";
    while(cont)
    {
        std::cin>>odp;
        switch(odp)
        {
        case 1:
            std::cout<<"Zaczynamy gre\n";
            std::cout<<"Instrukcje:\n"<<"Aby poruszyc sie figura nalezy wpisac koordynaty poczatku ruchu i koñca np \"a2a4\", malymi literami, razem\n";
            std::cout<<"Zeby poprosic o remis wpisz \"draw\"\n";
            std::cout<<"Zeby zakonczyc gre wpisz \"quit\"\n";
            std::cout<<"Zeby poddac sie wpisz \"surr\"\n"<<"\n";

            std::cout<<"Tryb wyswietlania: b - biale na dole, c - czarne na dole \n";
            std::cin>>od;
            if(od=='b')
                disp=1;
            else
                disp=2;

            chessGame(true,1,disp);
            std::cout<<"Czy chcesz wyjsc z programu? T/N \n";
            std::cin>>od;
            if(od=='T')
                cont=false;
            else
                std::cout<<"Wybierz tryb gry:\n 1 - hot-seat  2 - zagadki szachowe  3 - gra sieciowa 4 - wyjscie z programu \n";

            break;
        case 2:
            //nie wiem czy cos tu trzeba
            gratreningowa();
            std::cout<<"Czy chcesz wyjsc z programu? T/N \n";
            std::cin>>od;
            if(od=='T')
                cont=false;
            else
                std::cout<<"Wybierz tryb gry:\n 1 - hot-seat  2 - zagadki szachowe  3 - gra sieciowa 4 - wyjscie z programu\n";
            break;
        case 3:
            std::cout<<"Gra sieciowa nie jest jeszcze zaimplementowana\n Wybierz ponownie: ";
            break;
        case 4:
            cont=false;
            break;
        default:
            std::cout<<"Bledny tryb, podaj odpowiedz ponownie: ";
            break;
        }
    }
    return 0;
}

