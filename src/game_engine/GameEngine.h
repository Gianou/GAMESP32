#ifndef Game_Engine_H
#define Game_Engine_H

#include <vector>
#include <algorithm>
#include <TFT_eSPI.h>
#include "AbstractGameObject.h"

class GameEngine : public AbstractGameObject
{
public:
    void update() override;
    void render(TFT_eSprite &sprite) override;
    void addGameObject(AbstractGameObject *gameObject);
    void removeGameObject(AbstractGameObject *gameObject);
    std::vector<AbstractGameObject *> getChildren();

private:
    std::vector<AbstractGameObject *> gameObjects;
};

#endif