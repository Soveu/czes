#include <iostream>
#include <string>
#include <array>

#include <assert.h>

#include "definitions.cpp"

std::array<Position, 2> parse_position(const char* str, size_t len) {
  assert(len == 4);

  assert(str[0] >= 'a' && str[0] <= 'z');
  assert(str[1] >= '1' && str[1] <= '9');
  assert(str[2] >= 'a' && str[2] <= 'z');
  assert(str[3] >= '1' && str[3] <= '9');

  return {
    Position { str[0] - 'a', str[1] - '1' },
    Position { str[2] - 'a', str[3] - '1' },
  };
}

int main(int argc, const char* argv[]) {
  for(int i=1; i<argc; ++i) {
    std::cout << '"' << argv[i] << "\"\n";
  }

  Game game;
  game.clear_board();

  for(uint16_t i=0; i<5; i += 1) {
    for(uint16_t j=0; j<5; j += 1) {
      game.board[i][j] = Piece {
        static_cast<PieceColor>((i) % 2),
        PieceType::King
      };
    }
  }

  std::string line;
  for(;;) {
    std::cout << "Command: " << std::flush;
    if(!std::getline(std::cin, line)) break;

    if(line.starts_with("show")) {
      draw_board(game);
      continue;
    }

    if(line.starts_with("move ")) {
      if(line.size() <= 5) {
        break;
      }

      auto [from, to] = parse_position(line.data() + 5, line.size() - 5);
      bool has_moved = game.move_piece(from, to);
      std::cout << (has_moved ? "Piece was moved" : "Invalid move") << std::endl;

      continue;
    }

    if(line == "exit") break;
    std::cout << "Command not supported!" << std::endl;
  }

  return 0;
}

