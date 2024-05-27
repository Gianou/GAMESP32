#ifndef Bounce_Sphere_H
#define Bounce_Sphere_H

#include "../../../game_engine/AbstractGameObject.h"
#include "PongGameScene.h"
#include "../../../game_engine/CollisionDetector.h"
#include "../../../../config/Constants.h"

class BounceSphere : public AbstractGameObject
{
public:
    BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

    void setParentScene(PongGameScene *parent);
    PongGameScene *getParentScene();

    HitBox *getHitBox() override { return hitBox; };

private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;
    boolean isGameGoing = true;

    PongGameScene *parent;
    HitBox *hitBox;
    void moveSphere();
    void checkForScoring();
    void checkForBounce();
    void resetAfterScoring();
};

#endif
