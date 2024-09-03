#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SnakeSegment.h"
#include "../../../managers/SceneManager.h"
#include "../../../game_engine/AbstractGameObject.h"
#include "../../../game_engine/CollisionDetector.h"

class Snake : public AbstractGameObject
{
public:
    Snake(int startX, int startY, int segmentSize, int length, int speed);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    SnakeSegment *getHead();
    std::vector<SnakeSegment *> getSegments() { return segments; }
    void reset();
    void grow();
    void endGame();

private:
    std::vector<SnakeSegment *> segments;
    int initialX, initialY, initialLength;
    int directionX, directionY, segmentSize, length, speed;
    int framesSinceLastMove;
    void checkSelfCollision();
};

#endif
