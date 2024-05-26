#include "PongGameScene.h"

PongGameScene::PongGameScene(String name) : GameScene(name)
{
    collisionDetector = new CollisionDetector();
    scoreHandler = new ScoreHandler();
    scoreUI = new ScoreUI(scoreHandler);
    addGameObject(scoreUI);
}

void PongGameScene::update() // Make an adapter pattern to have gameSceneAware objects only?
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->update();
    }
}

void PongGameScene::render(Adafruit_SSD1325 &display)
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->render(display);
    }
}

void PongGameScene::addGameObject(AbstractGameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void PongGameScene::removeGameObject(AbstractGameObject *gameObject)
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

std::vector<AbstractGameObject *> PongGameScene::getChildren()
{
    return gameObjects;
}

CollisionDetector *PongGameScene::getCollisionDetector()
{
    return collisionDetector;
}

ScoreHandler *PongGameScene::getScoreHandler()
{
    return scoreHandler;
}

void PongGameScene::onExitScene()
{
    Serial.println("Exiting " + getName());
}
void PongGameScene::onEnterScene() { Serial.println("Entering " + getName()); }