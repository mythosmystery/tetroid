#define PIECE_H

#include <raylib.h>

const int PIECE_WIDTH = 4;
const int PIECE_HEIGHT = 4;

enum class PieceType {
  I = 1,
  O = 2,
  T = 3,
  S = 4,
  Z = 5,
  J = 6,
  L = 7,
};

constexpr int toInt(PieceType type) { return static_cast<int>(type); }

class Piece {
public:
  Piece();
  Piece(PieceType type);

  int at(int x, int y);
  void rotate();

  void move(Vector2 direction);

  void setPosition(Vector2 position);
  Vector2 getPosition();

  int getColorAt(Vector2 position);

private:
  int data[PIECE_WIDTH][PIECE_HEIGHT] = {0};
  Vector2 position = {0, 0};
};
