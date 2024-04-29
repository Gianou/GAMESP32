#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {}

boolean detectCollisions(AbstractRigidBody gameObject)
{
    return false;
}

bool checkCollision(AbstractRigidBody callerGameObject, AbstractRigidBody gameObject)
{

    // Check if callerGameObject and gameObject are the same object
    if (&callerGameObject == &gameObject)
    {
        // They are the same object, so no collision
        return false;
    }

    // Calculate the bounding boxes for both objects
    int callerLeft = callerGameObject.getX();
    int callerRight = callerGameObject.getX() + callerGameObject.getWidth();
    int callerTop = callerGameObject.getY();
    int callerBottom = callerGameObject.getY() + callerGameObject.getHeight();

    int objectLeft = gameObject.getX();
    int objectRight = gameObject.getX() + gameObject.getWidth();
    int objectTop = gameObject.getY();
    int objectBottom = gameObject.getY() + gameObject.getHeight();

    // Check for collision using Axis-Aligned Bounding Box (AABB) method
    if (callerRight >= objectLeft && callerLeft <= objectRight && callerBottom >= objectTop && callerTop <= objectBottom)
    {
        // Collision detected
        return true;
    }
    else
    {
        // No collision detected
        return false;
    }
}
