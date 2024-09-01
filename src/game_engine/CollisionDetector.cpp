#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {}

boolean CollisionDetector::checkCollision(AbstractGameObject *callerGameObject, AbstractGameObject *gameObject)
{

    if (!callerGameObject->getHitBox() || !gameObject->getHitBox())
    {
        Serial.println("No collision detection, missing hitbox");
        return false;
    }

    // Check if callerGameObject and gameObject are the same object
    if (callerGameObject == gameObject)
    {
        Serial.println("No collision detection, identical gameobjects");
        return false;
    }

    // Calculate the bounding boxes for both objects
    int callerLeft = callerGameObject->getHitBox()->getX();
    int callerRight = callerGameObject->getHitBox()->getX() + callerGameObject->getHitBox()->getWidth();
    int callerTop = callerGameObject->getHitBox()->getY();
    int callerBottom = callerGameObject->getHitBox()->getY() + callerGameObject->getHitBox()->getHeight();

    int objectLeft = gameObject->getHitBox()->getX();
    int objectRight = gameObject->getHitBox()->getX() + gameObject->getHitBox()->getWidth();
    int objectTop = gameObject->getHitBox()->getY();
    int objectBottom = gameObject->getHitBox()->getY() + gameObject->getHitBox()->getHeight();

    // Check for collision using Axis-Aligned Bounding Box (AABB) method
    if (callerRight >= objectLeft && callerLeft <= objectRight && callerBottom >= objectTop && callerTop <= objectBottom)
    {
        return true;
    }

    return false;
}
