#include "BounceSphere.h"

BounceSphere::BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY)
    : radius(radius), x(initialX), y(initialY), speedX(speedX), speedY(speedY)
{
    rigidBody = new RigidBody(x - radius, y - radius, radius * 2, radius * 2);
}

void BounceSphere::update()
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

    // Check bounds and bounce if necessary
    if (x - radius < 0 || x + radius > SCREEN_WIDTH)
    {
        speedX = -speedX;
    }
    if (y - radius < 0 || y + radius > SCREEN_HEIGHT)
    {
        speedY = -speedY;
    }
    // Check for collisions
    CollisionDetector collisionDetector = getParentScene()->getCollisionDetector();
    std::vector<AbstractGameObject *> sceneGameObjects = getParentScene()->getChildren();
    for (AbstractGameObject *gameObject : sceneGameObjects)
    {

        // Check collision between the paddle and each game object
        if (collisionDetector.checkCollision(this, gameObject))
        {
            speedX = -speedX;
            speedY = -speedY;
        }
    }
}

void BounceSphere::render(TFT_eSprite &sprite)
{
    // Draw the sphere with 1 sprite per
    sprite.fillRect(rigidBody->getX(), rigidBody->getY(), rigidBody->getWidth(), rigidBody->getHeight(), TFT_BLUE);
    sprite.fillCircle(x, y, radius, TFT_WHITE);
}

void BounceSphere::setParentScene(GameScene *parent)
{
    this->parent = parent;
}

GameScene *BounceSphere::getParentScene()
{
    return parent;
}