bool is_legal_pawn(Position from, Position to, const Game& game) {
  /* If there is a piece of the same color, we cannot jump there */
  if(game.board[to.y][to.x].color == game.board[from.y][from.x].color) {
    return false;
  }

  const Piece piece = game.board[from.y][from.x];
  const Position allowed_moves[2][2] = {
    {{-1,1}, {-1,-1}},
    {{1,1}, {1,-1}}
  };
  const Position move = {
    to.x - from.x,
    to.y - from.y
  };

  /* Now we check if we capture */
  if(game.board[to.y][to.x].color != piece.color) {
    /* We can only go one square diagonally forward */
    if(allowed_moves[piece.color][0] == move) {
      return true;
    }
    if(allowed_moves[piece.color][1] == move) {
      return true;
    }

    return false;
  }

  /* We don't capture and we don't have friendly piece there
   * So it means it is a free square */

  /* First, check if we go straight */
  if(from.x != to.x) {
    return false;
  }

  /* Black pieces can only go down and white can only go up */
  const int directions[2] = {-1, 1};
  return from.y + directions[piece.color] == to.x;
}

bool is_legal_rook(Position from, Position to, const Game& game) {
  /* We can only go horizontally or vertically */
  if(from.x != to.x && from.y != to.y) {
    return false;
  }

  /* We cannot capture friendly pieces */
  if(game.board[to.y][to.x].color == game.board[from.y][from.x].color) {
    return false;
  }

  /* Now we must check if nothing is on our way */

  /* Check from above down */
  for(int y = from.y-1; y>to.y; y -= 1) {
    if(game.board[y][from.x].type != PieceType::None) {
      return false;
    }
  }
  /* Check up down */
  for(int y = from.y+1; y<to.y; y += 1) {
    if(game.board[y][from.x].type != PieceType::None) {
      return false;
    }
  }
  /* Check from left */
  for(int x = from.x-1; x>to.x; x -= 1) {
    if(game.board[from.y][x].type != PieceType::None) {
      return false;
    }
  }
  /* Check from right */
  for(int x = from.x+1; x<to.x; x += 1) {
    if(game.board[from.y][x].type != PieceType::None) {
      return false;
    }
  }

  return true;
}

