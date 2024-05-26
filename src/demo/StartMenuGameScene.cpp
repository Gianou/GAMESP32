#include "StartMenuGameScene.h"

StartMenuGameScene::StartMenuGameScene(String name) : GameScene(name)
{
}

void StartMenuGameScene::onExitScene()
{
    Serial.println("Exiting " + getName());
}
void StartMenuGameScene::onEnterScene() { Serial.println("Entering " + getName()); }