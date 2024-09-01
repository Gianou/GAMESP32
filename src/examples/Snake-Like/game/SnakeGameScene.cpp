#include "SnakeGameScene.h"

SnakeGameScene::SnakeGameScene(String name, int x, int y, int width, int height)
    : GameScene(name), arenaX(x), arenaY(y), arenaWidth(width), arenaHeight(height), score(0)
{
    collisionDetector = new CollisionDetector();
}

void SnakeGameScene::update()
{
    GameScene::update();

    // Check collision between snake and food
    if (collisionDetector->checkCollision(snake->getHead(), food))
    {
        Serial.println("Collision");
        snake->grow();
        food->respawn();
        score += 1;
    }
    if (displayScore < score * 100)
    {
        displayScore += 3;
        if (displayScore > score * 100)
        {
            displayScore = score * 100;
        }
    }
    // Check if snake goes out of bound
    if (
        snake->getHead()->getX() < arenaX ||
        snake->getHead()->getX() + snake->getHead()->getSize() > arenaX + arenaWidth ||
        snake->getHead()->getY() < arenaY ||
        snake->getHead()->getY() + snake->getHead()->getSize() > arenaY + arenaHeight)
    {
        snake->endGame();
    }
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
    // Draw arena
    display.drawRect(arenaX, arenaY, arenaWidth, arenaHeight, WHITE);
    // Render the score
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Score: ");
    display.print(displayScore);
}

void SnakeGameScene::onEnterScene()
{
    Serial.println("Entering " + getName());
    score = 0;
    displayScore = 0;
    snake->reset();
    food->reset();
}
