#ifndef Game_Scene_H
#define Game_Scene_H

#include "AbstractGameObject.h"
#include "AbstractCompositGameObject.h"
#include "CollisionDetector.h"

class GameScene : public AbstractGameObject,
                  public AbstractCompositeGameObject
// HasCollisionDetector interface?
{
public:
    GameScene();
    void update() override;
    void render(TFT_eSprite &sprite) override;
    void addGameObject(AbstractGameObject *gameObject) override;
    void removeGameObject(AbstractGameObject *gameObject) override;
    virtual std::vector<AbstractGameObject *> getChildren() override;
    virtual CollisionDetector *getCollisionDetector();

private:
    std::vector<AbstractGameObject *> gameObjects;
    CollisionDetector collisionDetector;
};

#endif