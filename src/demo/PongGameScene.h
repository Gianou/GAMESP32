#ifndef Pong_Game_Scene_H
#define Pong_Game_Scene_H

#include "../game_engine/GameScene.h"
#include "ScoreHandler.h"
#include "ScoreUI.h"

class PongGameScene : public GameScene
// HasCollisionDetector interface?
{
public:
    PongGameScene();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void addGameObject(AbstractGameObject *gameObject) override;
    void removeGameObject(AbstractGameObject *gameObject) override;
    std::vector<AbstractGameObject *> getChildren() override;
    CollisionDetector *getCollisionDetector() override;
    ScoreHandler *getScoreHandler();

private:
    std::vector<AbstractGameObject *> gameObjects;
    CollisionDetector *collisionDetector;
    ScoreHandler *scoreHandler;
    ScoreUI *scoreUI;
};

#endif