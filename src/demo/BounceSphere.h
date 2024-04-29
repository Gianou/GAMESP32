#ifndef Bounce_Sphere_H
#define Bounce_Sphere_H

#include "../game_engine/AbstractGameObject.h"
#include "PongGameScene.h"
#include "../game_engine/CollisionDetector.h"
#include "../game_engine/AbstractGameSceneAware.h"
#include "../../config/Constants.h"

class BounceSphere : public AbstractGameObject
//,
// public AbstractGameSceneAware
{
public:
    BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    void setParentScene(PongGameScene *parent);
    PongGameScene *getParentScene();

    RigidBody *getRigidBody() override { return rigidBody; };

private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;

    PongGameScene *parent;
    RigidBody *rigidBody;
};

#endif
