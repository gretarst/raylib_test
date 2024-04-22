#include "game.h"

#include <math.h>

#include "raylib.h"

void InitializeGame(Game *game, int screenWidth, int screenHeight)
{
  game->player = (Player){(Vector2){screenWidth / 2, screenHeight / 2},
                          (Vector2){0, 0}, (Vector2){0, 0}, 0.10f};

  game->camera = (Camera2D){(Vector2){0}, game->player.position, 0.0f, 1.0f};
}

void DrawGame(Game *game)
{
  BeginDrawing();
  ClearBackground(WHITE);
  BeginMode2D(game->camera);
  DrawRectangle(game->player.position.x, game->player.position.y, 50, 50,
                DARKGREEN);
  EndMode2D();
  EndDrawing();
}

void UpdateGame(Game *game, float delta)
{
  game->player.acceleration = (Vector2){0, 0};

  if (IsKeyDown(KEY_W))
    game->player.acceleration.y -= ACCELERATION;

  if (IsKeyDown(KEY_S))
    game->player.acceleration.y += ACCELERATION;

  if (IsKeyDown(KEY_A))
    game->player.acceleration.x -= ACCELERATION;

  if (IsKeyDown(KEY_D))
    game->player.acceleration.x += ACCELERATION;

  game->player.velocity.x += game->player.acceleration.x * delta;
  game->player.velocity.y += game->player.acceleration.y * delta;

  // Apply friction (exponential decay of the velocity)
  game->player.velocity.x *= pow(game->player.friction, delta);
  game->player.velocity.y *= pow(game->player.friction, delta);

  // Zero-out tiny velocities to prevent unwanted slow movement
  if (fabs(game->player.velocity.x) < 1.0f)
    game->player.velocity.x = 0;
  if (fabs(game->player.velocity.y) < 1.0f)
    game->player.velocity.y = 0;

  game->player.position.x += game->player.velocity.x * delta;
  game->player.position.y += game->player.velocity.y * delta;
}
