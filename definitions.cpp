#pragma once

#include <stdint.h>
#include <map>

struct Coord {
  uint16_t x, y;

  /*
  const uint16_t& operator[](size_t i) const {
    if(i == 0) return this->x;
    if(i == 1) return this->y;
    assert(false);
  }
  uint16_t& operator[](size_t i) {
    if(i == 0) return this->x;
    if(i == 1) return this->y;
    assert(false);
  }
  */
};

bool operator==(const Coord& a, const Coord& b) {
  return a.x == b.x && a.y == b.y;
}
bool operator<(const Coord& a, const Coord& b) {
  if(a.y == b.y) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

enum Piece {
  Pawn,
  Bishop,
  Knight,
  Rook,
  Queen,
  King,
};

const char* pieces[7] = {
  "P",
  "B",
  "k",
  "R",
  "Q",
  "K"
};

struct Game {
  uint16_t height;
  uint16_t width;

  std::map<Coord, Piece> board;
};

void draw_part_of_board(const Game& game, Coord lu_corner, Coord rd_corner) {
}

void draw_board(const Game& game) {
  auto iter = game.board.begin();
  auto end = game.board.end();

  uint16_t y=0;
  uint16_t x=0;

  for(; y<game.height && iter != end; ++y) {
    x=0;

    std::cout << '\n';
    for(int i=0; i<game.height; ++i) {
      std::cout << "----";
    }
    std::cout << '\n';

    for(; x<game.width && iter != end; ++x) {
      std::cout << ' ';

      if(iter->first == Coord{x,y}) {
        std::cout << pieces[iter->second];
        ++iter;
      } else {
        std::cout << ' ';
      }

      std::cout << " |";
    }
  }

  for(; y<game.height; ++y) {
    for(; x<game.width; ++x) {
      std::cout << "   |";
    }

    x=0;
    std::cout << '\n';
    for(int i=0; i<game.height; ++i) {
      std::cout << "----";
    }
    std::cout << '\n';
  }
}

