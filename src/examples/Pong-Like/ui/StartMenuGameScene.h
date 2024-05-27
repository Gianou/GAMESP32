#ifndef Start_Menu_Game_Scene_H
#define Start_Menu_Game_Scene_H

#include "../../../game_engine/GameScene.h"

class StartMenuGameScene : public GameScene
{
public:
    StartMenuGameScene(String name);

    void onEnterScene() override;
    void onExitScene() override;

private:
    std::vector<AbstractGameObject *> gameObjects;
};
#endif