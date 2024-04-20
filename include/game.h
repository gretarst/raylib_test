
#include "raylib.h"

#define ACCELERATION 1000;

typedef struct Player {
  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;
  float friction;
} Player;

typedef struct Game {
  Player player;
  Camera2D camera;
} Game;

typedef struct Map {
} Map;

void UpdateGame(Game* game, float delta);
void DrawGame(Game* game);
void InitializeGame(Game* game, int screenWidth, int screenHeight);