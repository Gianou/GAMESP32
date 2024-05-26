#ifndef Game_Scene_H
#define Game_Scene_H

#include "AbstractGameObject.h"
#include "AbstractCompositGameObject.h"

class GameScene : public AbstractGameObject,
                  public AbstractCompositeGameObject
{
public:
    GameScene(String name);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

    void addGameObject(AbstractGameObject *gameObject) override;
    void removeGameObject(AbstractGameObject *gameObject) override;
    virtual std::vector<AbstractGameObject *> getChildren() override;

    virtual void onEnterScene();
    virtual void onExitScene();

    String getName();

private:
    std::vector<AbstractGameObject *> gameObjects;
    String name;
};

#endif