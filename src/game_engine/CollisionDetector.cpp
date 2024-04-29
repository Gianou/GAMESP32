#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {}

boolean CollisionDetector::detectCollisions(AbstractGameObject gameObject)
{
    return false;
}

boolean CollisionDetector::checkCollision(AbstractGameObject *callerGameObject, AbstractGameObject *gameObject)
{
    // return false;
    if (!callerGameObject->getRigidBody() || !gameObject->getRigidBody())
    {
        Serial.println("Test 1");
        return false;
    }

    // Check if callerGameObject and gameObject are the same object
    if (callerGameObject == gameObject)
    {
        // They are the same object, so no collision
        Serial.println("Test 2");

        return false;
    }

    // Calculate the bounding boxes for both objects
    int callerLeft = callerGameObject->getRigidBody()->getX();
    int callerRight = callerGameObject->getRigidBody()->getX() + callerGameObject->getRigidBody()->getWidth();
    int callerTop = callerGameObject->getRigidBody()->getY();
    int callerBottom = callerGameObject->getRigidBody()->getY() + callerGameObject->getRigidBody()->getHeight();

    int objectLeft = gameObject->getRigidBody()->getX();
    int objectRight = gameObject->getRigidBody()->getX() + gameObject->getRigidBody()->getWidth();
    int objectTop = gameObject->getRigidBody()->getY();
    int objectBottom = gameObject->getRigidBody()->getY() + gameObject->getRigidBody()->getHeight();

    // Check for collision using Axis-Aligned Bounding Box (AABB) method
    if (callerRight >= objectLeft && callerLeft <= objectRight && callerBottom >= objectTop && callerTop <= objectBottom)
    {
        Serial.println("Collision detected");

        // Collision detected
        return true;
    }
    Serial.println("End of function, returns false");

    return false;
}
