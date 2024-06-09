#pragma once

#include "raylib.h"
#include <map>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

const int BLOCK_SIZE = 40;

const int HORIZONTAL_MARGIN = 100;

const int SCREEN_WIDTH = BOARD_WIDTH * BLOCK_SIZE + HORIZONTAL_MARGIN * 2;
const int SCREEN_HEIGHT = BOARD_HEIGHT * BLOCK_SIZE;

const Vector2 SCREEN_CENTER = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};

const std::map<int, Color> COLORS = {
    {0, WHITE},  {1, BLUE},   {2, RED},    {3, GREEN},
    {4, YELLOW}, {5, ORANGE}, {6, PURPLE}, {7, BROWN},
};
