#include "PongGameScene.h"

PongGameScene::PongGameScene()
{
    collisionDetector = CollisionDetector();
    scoreHandler = ScoreHandler();
}

void PongGameScene::update() // Make an adapter pattern to have gameSceneAware objects only?
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->update();
    }
}

void PongGameScene::render(TFT_eSprite &sprite)
{
    for (AbstractGameObject *gameObject : gameObjects)
    {
        gameObject->render(sprite);
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

CollisionDetector PongGameScene::getCollisionDetector()
{
    return collisionDetector;
}