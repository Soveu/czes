#pragma once

#include <iostream>

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

struct Position {
  uint16_t x, y;

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

/* WARNING: unicode chararacter like these cannot fit into 'char' so that why
 * they are inside strings */

/*
const char* UNICODE_PIECES[7] = {
  " ",
  "♙",
  "♖",
  "♘",
  "♗",
  "♕",
  "♔",
};
*/

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

struct Game;
bool return_true(const Position& from, const Position& to, const Game& game) {
  return true;
}
bool return_false(const Position& from, const Position& to, const Game& game) {
  return false;
}

using MoveCheckFunction = bool(*)(const Position&, const Position&, const Game& game);
const MoveCheckFunction MOVE_CHECK_FUNCTIONS[7] = {
  return_false,
  return_true,
  return_true,
  return_true,
  return_true,
  return_true,
  return_true,
};

struct Game {
  Piece board[8][8];

  void clear_board() {
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

  bool move_piece(const Position& from, const Position& to) {
    auto can_move_f = MOVE_CHECK_FUNCTIONS[this->board[from.y][from.x].type];
    if(can_move_f(from, to, *this) == false) {
      return false;
    }

    this->board[to.y][to.x] = this->board[from.y][from.x];
    this->board[from.y][from.x] = Piece { PieceColor::Black, PieceType::None };
  }
};

void draw_board(const Game& game) {
  std::cout << "\n";

  const char* WHITE_BACKGROUND = "\033[48;5;180m";
  const char* BLACK_BACKGROUND = "\033[48;5;94m";

  const char* WHITE_FOREGROUND = "\033[38;5;254m";
  const char* BLACK_FOREGROUND = "\033[38;5;235m";

  const char* RESET = "\033[0m";

  for(size_t y=0; y<8; y+=1) {
    for(size_t x=0; x<8; x+=1) {
      bool is_background_white = ((x+y) % 2) == 0;
      Piece piece = game.board[y][x];

      std::cout << (is_background_white ? WHITE_BACKGROUND : BLACK_BACKGROUND);
      std::cout << (piece.color == PieceColor::Black ? BLACK_FOREGROUND : WHITE_FOREGROUND);
      std::cout << " " << UNICODE_PIECES[piece.type] << " ";
    }

    std::cout << RESET << "\n";
  }

  /* std::endl also flushes output */
  std::cout << RESET << std::endl;
}

