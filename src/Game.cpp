#include "Game.h"
#include "Constants.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game");

  SetTargetFPS(60);

  this->window = std::move(window);
  this->board = Board();
}

void Game::draw() {
  // Draw the game
  BeginDrawing();

  this->backgroundColor.ClearBackground();

  this->board.draw();

  EndDrawing();
}

void Game::update() {
  // Update the game
  this->board.update();
}
