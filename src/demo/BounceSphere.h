#ifndef Bounce_Sphere_H
#define Bounce_Sphere_H

#include "../game_engine/AbstractGameObject.h"
#include "../game_engine/GameScene.h"
#include "../game_engine/CollisionDetector.h"
#include "../game_engine/AbstractGameSceneAware.h"
#include "../game_engine/AbstractRigidBody.h"
#include "../../config/Constants.h"

class BounceSphere : public AbstractGameObject,
                     public AbstractGameSceneAware,
                     public AbstractRigidBody
{
public:
    BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    void setParentScene(GameScene *parent);
    GameScene *getParentScene();

    int getX() override { return x; }
    int getY() override { return y; }
    int getWidth() override { return radius * 2; }
    int getHeight() override { return radius * 2; }

private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;

    GameScene *parent;
};

#endif
