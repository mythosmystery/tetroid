#include "Board.h"

Board::Board() {}

void Board::draw() {
  for (int x = 0; x < BOARD_WIDTH; x++) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
      raylib::Vector2 blockPosition =
          raylib::Vector2((x * BLOCK_SIZE) + HORIZONTAL_MARGIN, y * BLOCK_SIZE);

      raylib::Vector2 blockSize =
          raylib::Vector2(BLOCK_SIZE - 1, BLOCK_SIZE - 1);

      raylib::Rectangle block = raylib::Rectangle(blockPosition, blockSize);

      int pieceColor = currentPiece.getColorAt(raylib::Vector2(x, y));

      if (pieceColor != 0) {
        block.Draw(COLORS.at(pieceColor));
        continue;
      }
      block.Draw(COLORS.at(data[x][y]));
    }
  }
}

void Board::update() {
  if (IsKeyDown(KEY_LEFT))
    currentPiece.move(raylib::Vector2(-1, 0));
  if (IsKeyDown(KEY_RIGHT))
    currentPiece.move(raylib::Vector2(1, 0));
}

// void Board::addPiece(Piece piece) {
//   Vector2 pos = piece.getPosition();
//   for (int x = pos.x; x < PIECE_WIDTH + pos.x; x++) {
//     for (int y = pos.y; y < PIECE_HEIGHT + pos.y; y++) {
//       data[x][y] = piece.at(x, y);
//     }
//   }
// }
