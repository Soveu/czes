#pragma once

#include <stdint.h>

struct Coord {
  uint16_t x, y;

  bool operator==(const Coord& a) const {
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
const char* UNICODE_PIECES[7] = {
  " ",
  "♙",
  "♖",
  "♘",
  "♗",
  "♕",
  "♔",
};

/*
const char* UNICODE_PIECES[7] = {
  " ",
  "♟",
  "♝",
  "♞",
  "♜",
  "♛",
  "♚",
};
*/

enum PieceColor : uint8_t {
  Black = 0,
  White = 1,
};

struct Piece {
  /* INVARIANT: color is stored in youngest bit and rest gets shifted */
  uint8_t _data;

  static Piece with_type_and_color(const PieceType type, const PieceColor color) {
    uint8_t _type = static_cast<uint8_t>(type);
    uint8_t _color = static_cast<uint8_t>(color);
    uint8_t data = (_type << 1) | (_color << 0);
    return Piece { data };
  }

  PieceColor color() const {
    uint8_t col = this->_data & 1;
    /* SAFETY: color can be either 0 (black) or 1 (white) */
    return static_cast<PieceColor>(col);
  }

  PieceType type() const {
    uint8_t p = this->_data >> 1;
    /* SAFETY: see invariant */
    return static_cast<PieceType>(p);
  }
};

struct Game {
  Piece board[8][8];

  void clear_board() {
    const Piece EMPTY_FIELD = Piece::with_type_and_color(
      PieceType::None,
      PieceColor::Black
    );

    for(size_t y=0; y<8; y+=1) {
      for(size_t x=0; x<8; x+=1) {
        this->board[y][x] = EMPTY_FIELD;
      }
    }
  }
};

void draw_board(const Game& game) {
  std::cout << "\n";

  const char* WHITE_BACKGROUND = "\033[47m";
  const char* BLACK_BACKGROUND = "\033[100m";

  const char* WHITE_FOREGROUND = "\033[97m";
  const char* BLACK_FOREGROUND = "\033[30m";

  const char* RESET = "\033[0m";

  for(size_t y=0; y<8; y+=1) {
    for(size_t x=0; x<8; x+=1) {
      bool is_background_white = ((x+y) % 2) == 0;
      Piece piece = game.board[y][x];

      std::cout << (is_background_white ? WHITE_BACKGROUND : BLACK_BACKGROUND);
      std::cout << (piece.color() == PieceColor::Black ? BLACK_FOREGROUND : WHITE_FOREGROUND);
      std::cout << " " << UNICODE_PIECES[piece.type()] << " ";
    }

    std::cout << RESET << "\n";
  }

  /* std::endl also flushes output */
  std::cout << RESET << std::endl;
}

