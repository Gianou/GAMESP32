#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SnakeSegment.h"
#include "SnakeGameScene.h"
#include "../../../game_engine/AbstractGameObject.h"
#include "../../../game_engine/CollisionDetector.h"

class Snake : public AbstractGameObject
{
public:
    Snake(int startX, int startY, int segmentSize, int length, int speed);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void grow();
    bool checkSelfCollision();
    SnakeSegment *getHead();

    void setParentScene(SnakeGameScene *parent);
    SnakeGameScene *getParentScene();

private:
    std::vector<SnakeSegment *> segments;
    int directionX, directionY, segmentSize, length, speed;
    int framesSinceLastMove;
    SnakeGameScene *parent;
};

#endif
