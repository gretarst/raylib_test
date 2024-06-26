#include <math.h>
#include <stdlib.h>

#include "game.h"
#include "raylib.h"

int main()
{
  const int screenWidth = 1000;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "The Green Box");
  HideCursor();
  SetTargetFPS(60);

  Game game;
  InitializeGame(&game, screenWidth, screenHeight);

  while (!WindowShouldClose())
  {
    float delta = GetFrameTime();

    UpdateGame(&game, delta);
    DrawGame(&game);
  }

  CloseWindow();

  return 0;
}
