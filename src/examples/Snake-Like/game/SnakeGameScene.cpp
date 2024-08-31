#include "SnakeGameScene.h"

SnakeGameScene::SnakeGameScene(String name) : GameScene(name), score(0)
{
    collisionDetector = new CollisionDetector();
}

void SnakeGameScene::update()
{
    GameScene::update();

    // Check for collision between the snake's head and the food
    // if (collisionDetector->checkCollision(food, food))
    // {
    //     // Snake eats the food
    //     // snake->grow();
    //     // food->respawn();
    // }

    // Check for self-collision
    // if (snake->checkSelfCollision())
    // {
    //     // End the game
    //     endGame();
    // }
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
