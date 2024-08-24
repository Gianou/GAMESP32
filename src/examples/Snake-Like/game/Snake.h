#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SnakeSegment.h"
#include "../../../game_engine/AbstractGameObject.h"

class Snake : public AbstractGameObject
{
public:
    Snake(int startX, int startY, int segmentSize);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void grow();
    bool checkSelfCollision();
    SnakeSegment *getHead();

private:
    std::vector<SnakeSegment *> segments;
    int directionX, directionY, segmentSize;
    int framesSinceLastMove;
};

#endif
