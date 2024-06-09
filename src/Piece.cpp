#include "Piece.h"
#include "Constants.h"
#include "Pieces.h"

Piece::Piece() {
  for (int x = 0; x < PIECE_WIDTH; x++) {
    for (int y = 0; y < PIECE_HEIGHT; y++) {
      data[x][y] = O[x][y];
    }
  }
}

Piece::Piece(PieceType pt) {
  for (int x = 0; x < PIECE_WIDTH; x++) {
    for (int y = 0; y < PIECE_HEIGHT; y++) {
      switch (pt) {
      case PieceType::I:
        data[x][y] = I[x][y];
        break;
      case PieceType::O:
        data[x][y] = O[x][y];
        break;
      case PieceType::T:
        data[x][y] = T[x][y];
        break;
      case PieceType::S:
        data[x][y] = S[x][y];
        break;
      case PieceType::Z:
        data[x][y] = Z[x][y];
        break;
      case PieceType::J:
        data[x][y] = J[x][y];
        break;
      case PieceType::L:
        data[x][y] = L[x][y];
        break;
      }
    }
  }
}

int Piece::at(int x, int y) { return data[x][y]; }

Vector2 Piece::getPosition() { return position; }

void Piece::rotate() {
  int newData[PIECE_WIDTH][PIECE_HEIGHT] = {0};

  for (int x = 0; x < PIECE_WIDTH; x++) {
    for (int y = 0; y < PIECE_HEIGHT; y++) {
      newData[x][y] = data[y][PIECE_WIDTH - x - 1];
    }
  }

  for (int x = 0; x < PIECE_WIDTH; x++) {
    for (int y = 0; y < PIECE_HEIGHT; y++) {
      data[x][y] = newData[x][y];
    }
  }
}

void Piece::move(Vector2 direction) {
  Vector2 newPosition = {position.x + direction.x, position.y + direction.y};
  if (newPosition.x < 0 || newPosition.x > BOARD_WIDTH || newPosition.y < 0 ||
      newPosition.y > BOARD_HEIGHT) {
    return;
  }
  this->position = newPosition;
}

int Piece::getColorAt(Vector2 pos) {
  int x = pos.x - position.x;
  int y = pos.y - position.y;
  if (x < 0 || x >= PIECE_WIDTH || y < 0 || y >= PIECE_HEIGHT) {
    return 0;
  }
  return data[x][y];
}
