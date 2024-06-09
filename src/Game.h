#define GAME_H

#include "Board.h"
#include "raylib-cpp.hpp"

struct Game {
  Game();

  void draw();
  void update();

  raylib::Color backgroundColor = GRAY;
  std::unique_ptr<raylib::Window> window;

  Board board;
};
