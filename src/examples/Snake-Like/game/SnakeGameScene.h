#ifndef SNAKE_GAME_SCENE_H
#define SNAKE_GAME_SCENE_H

#include "../../../game_engine/GameScene.h"
#include "../../../managers/SceneManager.h"
#include "../../../game_engine/CollisionDetector.h"
#include "Food.h"
#include "Snake.h"

class SnakeGameScene : public GameScene
{
public:
    SnakeGameScene(String name, int x, int y, int width, int height);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void endGame();

    CollisionDetector *getCollisionDetector();
    void setSnake(Snake *newSnake) { snake = newSnake; };
    void setFood(Food *newFood) { food = newFood; };
    void respawnFood();

    void
    onEnterScene() override;

private:
    Snake *snake;
    Food *food;
    int score, displayScore;
    int arenaX, arenaY, arenaWidth, arenaHeight;
    CollisionDetector *collisionDetector;
};

#endif
