#include <iostream>
#include <string>
#include "definitions.cpp"

int main(int argc, const char* argv[]) {
  for(int i=1; i<argc; ++i) {
    std::cout << '"' << argv[i] << "\"\n";
  }

  Game game;
  game.clear_board();

  for(uint16_t i=0; i<5; i += 1) {
    for(uint16_t j=0; j<5; j += 1) {
      game.board[i][j] = Piece::with_type_and_color(
        PieceType::King,
        static_cast<PieceColor>((i+j) % 2)
      );
    }
  }

  std::string line;
  for(;;) {
    std::cout << "Command: " << std::flush;
    if(!std::getline(std::cin, line)) break;

    if(line.starts_with("show")) {
      std::cout << "Command: show\n";
      draw_board(game);
      continue;
    }

    if(line.starts_with("move ")) {
      std::cout << "Command: move\n";
      continue;
    }

    if(line == "exit") break;
    std::cout << "Command not supported!" << std::endl;
  }

  return 0;
}

