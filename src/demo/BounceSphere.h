#ifndef Bounce_Sphere_H
#define Bounce_Sphere_H

#include "../game_engine/AbstractGameObject.h"
#include "../game_engine/GameScene.h"
#include "../game_engine/CollisionDetector.h"
#include "../game_engine/AbstractGameSceneAware.h"
#include "../../config/Constants.h"

class BounceSphere : public AbstractGameObject,
                     public AbstractGameSceneAware
{
public:
    BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    void setParentScene(GameScene *parent);
    GameScene *getParentScene();

    RigidBody *getRigidBody() override { return rigidBody; };

private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;

    GameScene *parent;
    RigidBody *rigidBody;
};

#endif
