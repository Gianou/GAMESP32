#include "SnakeGameScene.h"

SnakeGameScene::SnakeGameScene(String name) : GameScene(name), score(0)
{
    collisionDetector = new CollisionDetector();
}

void SnakeGameScene::update()
{
    GameScene::update();
}

CollisionDetector *SnakeGameScene::getCollisionDetector()
{
    return collisionDetector;
}

void SnakeGameScene::endGame()
{
    SceneManager *sceneManager = SceneManager::getInstance();
    sceneManager->setCurrentGameScene("End");
}

void SnakeGameScene::render(Adafruit_SSD1325 &display)
{
    GameScene::render(display);
    // Optionally render the score
    // display.setCursor(0, 0);
    // display.print("Score: ");
    // display.print(score);
}
