#include "BounceSphere.h"

BounceSphere::BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY)
    : radius(radius), x(initialX), y(initialY), speedX(speedX), speedY(speedY)
{
    rigidBody = new RigidBody(x - radius, y - radius, radius * 2, radius * 2);
}

void BounceSphere::update()
{
    moveSphere();
    checkForScoring();
    checkForBounce();
    resetAfterScoring();
}

void BounceSphere::render(Adafruit_SSD1325 &display)
{
    // display.fillRect(rigidBody->getX(), rigidBody->getY(), rigidBody->getWidth(), rigidBody->getHeight(), WHITE);
    display.fillCircle(x, y, radius, WHITE);
}

void BounceSphere::setParentScene(PongGameScene *parent)
{
    this->parent = parent;
}

PongGameScene *BounceSphere::getParentScene()
{
    return parent;
}

void BounceSphere::moveSphere()
{
    // Update position based on speed
    x += speedX;
    y += speedY;
    // Same for rigidBody
    int newRigidBodyX = rigidBody->getX();
    newRigidBodyX += speedX;
    rigidBody->setX(newRigidBodyX);

    int newRigidBodyY = rigidBody->getY();
    newRigidBodyY += speedY;
    rigidBody->setY(newRigidBodyY);
}

void BounceSphere::checkForScoring()
{
    // Check for scoring
    if (x + radius > SCREEN_WIDTH && isGameGoing)
    {
        // left player scores
        ScoreHandler *scoreHandler = getParentScene()->getScoreHandler();
        int currentScore = scoreHandler->getLeftPlayerScore();
        scoreHandler->setLeftPlayerScore(currentScore + 1);
        isGameGoing = false;
    }
    if (x - radius < 0 && isGameGoing)
    {
        // right player scores
        ScoreHandler *scoreHandler = getParentScene()->getScoreHandler();
        int currentScore = scoreHandler->getRightPlayerScore();
        scoreHandler->setRightPlayerScore(currentScore + 1);
        isGameGoing = false;
    }
}
void BounceSphere::checkForBounce()
{
    // Check for bounce on walls
    if (y - radius < 0 || y + radius > SCREEN_HEIGHT)
    {
        speedY = -speedY;
    }
    // Check for collisions with paddles
    CollisionDetector *collisionDetector = getParentScene()->getCollisionDetector();
    std::vector<AbstractGameObject *> sceneGameObjects = getParentScene()->getChildren();
    for (AbstractGameObject *gameObject : sceneGameObjects)
    {
        // Check collision between the paddle and each game object
        if (collisionDetector->checkCollision(this, gameObject))
        {
            speedX = -speedX;
            speedY = -speedY;
        }
    }
}
void BounceSphere::resetAfterScoring()
{
    // reset ball if way out
    if (x < -60 || x > 60 + SCREEN_WIDTH)
    {
        x = SCREEN_WIDTH / 2;
        y = SCREEN_HEIGHT / 2;
        rigidBody->setX(x - radius);
        rigidBody->setY(y - radius);
        speedY = -speedY;
        speedX = -speedX;
        isGameGoing = true;
    }
}