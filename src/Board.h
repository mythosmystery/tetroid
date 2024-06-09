#define BOARD_H

#include "Constants.h"
#include "Piece.h"
#include "raylib-cpp.hpp"

class Board {
public:
  Board();

  void draw();
  void update();

private:
  int data[BOARD_WIDTH][BOARD_HEIGHT] = {0};

  Piece currentPiece;
};
