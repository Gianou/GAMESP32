#ifndef SNAKE_SEGMENT_H
#define SNAKE_SEGMENT_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../../../game_engine/HitBox.h"

class SnakeSegment : public AbstractGameObject
{
public:
    SnakeSegment(int x, int y, int size);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void setPosition(int x, int y);
    int getX();
    int getY();
    int getSize();
    HitBox *getHitBox() override { return hitBox; };

private:
    int x, y, size;
    HitBox *hitBox;
};

#endif
