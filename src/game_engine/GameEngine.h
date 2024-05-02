#ifndef Game_Engine_H
#define Game_Engine_H

#include <vector>
#include <algorithm>
#include <TFT_eSPI.h>
#include "AbstractGameObject.h"
#include "AbstractCompositGameObject.h"

class GameEngine : public AbstractGameObject,
                   public AbstractCompositeGameObject
{
public:
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void addGameObject(AbstractGameObject *gameObject) override;
    void removeGameObject(AbstractGameObject *gameObject) override;
    std::vector<AbstractGameObject *> getChildren() override;

private:
    std::vector<AbstractGameObject *> gameObjects;
};

#endif