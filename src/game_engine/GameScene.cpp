
#include "GameScene.h"

GameScene::GameScene(String name) : name(name)
{
}

void GameScene::update()
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->update();
    }
}

void GameScene::render(Adafruit_SSD1325 &display)
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->render(display);
    }
}

void GameScene::addGameObject(AbstractGameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void GameScene::removeGameObject(AbstractGameObject *gameObject)
{
    // Find the game object in the vector
    std::vector<AbstractGameObject *>::iterator it = std::find(gameObjects.begin(), gameObjects.end(), gameObject);

    // Check if the game object was found
    if (it != gameObjects.end())
    {
        // Remove the game object from the vector
        gameObjects.erase(it);

        // Delete the game object
        delete gameObject;
    }
}

std::vector<AbstractGameObject *> GameScene::getChildren()
{
    return gameObjects;
}

String GameScene::getName()
{
    return name;
}

void GameScene::onEnterScene() {}
void GameScene::onExitScene() {}
