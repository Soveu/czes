#pragma once

#include <iostream>
#include <vector>

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

struct Position {
  int32_t x, y;

  bool operator==(const Position& a) const {
    return a.x == this->x && a.y == this->y;
  }
};

enum PieceType : uint8_t {
  None = 0,
  Pawn,
  Bishop,
  Knight,
  Rook,
  Queen,
  King,
};

/* WARNING: unicode chararacter like these cannot fit into 'char' so that's why
 * they are inside strings */

const char* UNICODE_PIECES[7] = {
  " ",
  "♟",
  "♝",
  "♞",
  "♜",
  "♛",
  "♚",
};

enum PieceColor : uint8_t {
  Black = 0,
  White = 1,
};

struct Piece {
  PieceColor color;
  PieceType type;
};

struct Game {
  Piece board[8][8];
  std::vector<std::array<Position, 2>> history;

  void clear_board();
  bool move_piece(Position from, Position to);
  void draw_board();
};

#include "check_funcs.cpp"

bool return_true(Position from, Position to, const Game& game) {
  return true;
}
bool return_false(Position from, Position to, const Game& game) {
  return false;
}

using MoveCheckFunction = bool(*)(Position, Position, const Game& game);
const MoveCheckFunction MOVE_CHECK_FUNCTIONS[7] = {
  return_false,
  is_legal_pawn,
  is_legal_bishop,
  is_legal_knight,
  is_legal_rook,
  is_legal_queen,
  is_legal_king,
};

void Game::clear_board() {
  const Piece EMPTY_FIELD = Piece {
    PieceColor::Black,
    PieceType::None
  };

  for(size_t y=0; y<8; y+=1) {
    for(size_t x=0; x<8; x+=1) {
      this->board[y][x] = EMPTY_FIELD;
    }
  }
}

bool Game::move_piece(Position from, Position to) {
  /* TODO: gdy gracz jest szachowany, nie może wykonać innego ruchu
   * niż ruch królem */

  auto can_move_f = MOVE_CHECK_FUNCTIONS[this->board[from.y][from.x].type];
  if(can_move_f(from, to, *this) == false) {
    return false;
  }

  this->board[to.y][to.x] = this->board[from.y][from.x];
  this->board[from.y][from.x] = Piece{PieceColor::Black, PieceType::None};
  this->history.push_back({from, to});

  return true;
}

void Game::draw_board() {
  const Game& game = *this;
  std::cout << "\n";

  const char* WHITE_BACKGROUND = "\033[48;5;180m";
  const char* BLACK_BACKGROUND = "\033[48;5;94m";

  const char* WHITE_FOREGROUND = "\033[38;5;254m";
  const char* BLACK_FOREGROUND = "\033[38;5;235m";

  const char* RESET = "\033[0m";

  for(int y=7; y>=0; y-=1) {
    for(int x=0; x<8; x+=1) {
      bool is_background_white = ((x+y) % 2) == 0;
      Piece piece = game.board[y][x];

      std::cout << (is_background_white ? WHITE_BACKGROUND : BLACK_BACKGROUND);
      std::cout << (piece.color == PieceColor::Black ? BLACK_FOREGROUND : WHITE_FOREGROUND);
      std::cout << " " << UNICODE_PIECES[piece.type] << " ";
    }

    std::cout << RESET << ' ' << static_cast<char>(y+'1') << "\n";
  }

  for(int i=0; i<8; i+=1) {
    std::cout << ' ' << static_cast<char>(i+'a') << ' ';
  }
  /* std::endl also flushes output */
  std::cout << RESET << std::endl;
}

