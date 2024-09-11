#ifndef SNAKE_GAME_SCENE_H
#define SNAKE_GAME_SCENE_H

#include "../../../game_engine/GameScene.h"
#include "../../../game_engine/CollisionDetector.h"
#include "../../../managers/SceneManager.h"
#include "../../../managers/NetworkManager.h"
#include "Food.h"
#include "Snake.h"
#include "SnakeScoreHandler.h"

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
    void setScoreHandler(SnakeScoreHandler *newScoreHandler) { scoreHandler = newScoreHandler; };
    void respawnFood();

    void
    onEnterScene() override;

private:
    Snake *snake;
    Food *food;
    SnakeScoreHandler *scoreHandler;
    int score, displayScore;
    int arenaX, arenaY, arenaWidth, arenaHeight;
    CollisionDetector *collisionDetector;
    void drawConnectionQualityBar(int quality, Adafruit_SSD1325 &display);
};

#endif
