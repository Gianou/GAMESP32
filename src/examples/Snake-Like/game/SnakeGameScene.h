#ifndef SNAKE_GAME_SCENE_H
#define SNAKE_GAME_SCENE_H

#include "../../../game_engine/GameScene.h"
#include "../../../managers/SceneManager.h"
#include "../../../game_engine/CollisionDetector.h"

class SnakeGameScene : public GameScene
{
public:
    SnakeGameScene(String name);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void endGame();

    CollisionDetector *getCollisionDetector();

private:
    int score;
    CollisionDetector *collisionDetector;
};

#endif
