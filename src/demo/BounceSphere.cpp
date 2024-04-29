#include "BounceSphere.h"

BounceSphere::BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY)
    : radius(radius), x(initialX), y(initialY), speedX(speedX), speedY(speedY)
{
}

void BounceSphere::update()
{
    // Update position based on speed
    x += speedX;
    y += speedY;

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
        // Check if gameObject is a SolidBody
        if (typeid(gameObject) != typeid(AbstractRigidBody))
        {
            // do nothing
        }
        // Check collision between the paddle and each game object
        else if (collisionDetector.checkCollision(*this, *gameObject))
        {
            speedX = -speedX;
            speedY = -speedY;
        }
    }
}

void BounceSphere::render(TFT_eSprite &sprite)
{
    // Draw the sphere with 1 sprite per
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
