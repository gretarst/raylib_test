#include "raylib.h"

int main() {

  int window_width = 800;
  int window_height = 600;

  InitWindow(window_width, window_height, "Railroad Colony");
  Font font = LoadFont("font.otf");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(WHITE);

    Vector2 position = {10.00, 10.00};
    DrawTextEx(font, "Hello, Raylib!", position, 24.0, 1.5, BLACK);

    DrawRectangle(10, 42, 50, 50, DARKGREEN);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
