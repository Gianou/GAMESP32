#ifndef FOOD_H
#define FOOD_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../../../../config/Constants.h"

class Food : public AbstractGameObject
{
public:
    Food(int x, int y, int size);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void respawn();
    HitBox *getHitBox() override { return hitBox; };

private:
    int x, y, size;
    HitBox *hitBox;
};

#endif
