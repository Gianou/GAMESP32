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
        respawnFood();
        scoreHandler->setScore(scoreHandler->getScore() + 1);
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
    display.print(scoreHandler->getDisplayScore());
    // Show wifi connexion
    NetworkManager *networkManager = NetworkManager::getInstance();
    display.setCursor(64, 0);
    display.print(networkManager->getConnectionQuality());
}

void SnakeGameScene::onEnterScene()
{
    Serial.println("Entering " + getName());
    score = 0;
    displayScore = 0;
    snake->reset();
    food->reset();
    scoreHandler->reset();
}

void SnakeGameScene::respawnFood()
{
    int foodX, foodY;
    bool validPosition = false;

    while (!validPosition)
    {
        // Generate random coordinates within the arena
        foodX = 1 + random(arenaX, arenaX + arenaWidth - food->getSize());
        foodY = 1 + random(arenaY, arenaY + arenaHeight - 1 - food->getSize());
        food->respawn(foodX, foodY);
        // Check if the generated coordinates overlap with the snake
        validPosition = true;
        for (SnakeSegment *segment : snake->getSegments())
        {
            if (collisionDetector->checkCollision(food, segment))
            {
                validPosition = false;
                break; // Break out of the loop if there's a collision
            }
        }
    }

    // Set the food's position to the valid coordinates
}
