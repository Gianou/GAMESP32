#include "Snake.h"
#include "../../../managers/InputManager.h"

Snake::Snake(int startX, int startY, int segmentSize, int length, int speed) : directionX(1), directionY(0), segmentSize(segmentSize), length(length), framesSinceLastMove(0), speed(speed)
{
    segments.push_back(new SnakeSegment(startX, startY, segmentSize));
    for (int i = 0; i < length; i++)
    {
        grow();
    }
}

void Snake::update()
{
    InputManager *inputManager = InputManager::getInstance();

    // Handling the direction based on input
    if (inputManager->getInputValue("X axis") > 2000)
    {
        directionX = 1;
        directionY = 0;
    }
    else if (inputManager->getInputValue("X axis") < 1900)
    {
        directionX = -1;
        directionY = 0;
    }
    else if (inputManager->getInputValue("Y axis") > 2000)
    {
        directionX = 0;
        directionY = 1;
    }
    else if (inputManager->getInputValue("Y axis") < 1900)
    {
        directionX = 0;
        directionY = -1;
    }

    // Move the segments from tail to head
    for (int i = segments.size() - 1; i > 0; i--)
    {
        segments[i]->setPosition(segments[i - 1]->getX(), segments[i - 1]->getY());
    }

    // Move the head
    segments[0]->setPosition(segments[0]->getX() + directionX * segmentSize, segments[0]->getY() + directionY * segmentSize);

    // Check for self-collision
    // if (checkSelfCollision())
    // {
    //     // Handle game over
    //     SceneManager::getInstance()->setCurrentGameScene("End");
    // }
}

void Snake::render(Adafruit_SSD1325 &display)
{
    for (auto segment : segments)
    {
        segment->render(display);
    }
}

void Snake::grow()
{
    SnakeSegment *tail = segments.back();

    // Calculate the position for the new segment based on the current direction
    int newX = tail->getX() - directionX * segmentSize;
    int newY = tail->getY() - directionY * segmentSize;

    // Add the new segment at the calculated position
    segments.push_back(new SnakeSegment(newX, newY, segmentSize));
}

bool Snake::checkSelfCollision()
{
    SnakeSegment *head = segments[0];
    for (int i = 1; i < segments.size(); i++)
    {
        if (head->getX() == segments[i]->getX() && head->getY() == segments[i]->getY())
        {
            return true;
        }
    }
    return false;
}

SnakeSegment *Snake::getHead()
{
    return segments[0];
}
