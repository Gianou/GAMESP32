#ifndef Collision_Detector_H
#define Collision_Detector_H

#include "AbstractRigidBody.h"
#include "AbstractGameObject.h"
#include <vector>

class CollisionDetector
{
public:
    CollisionDetector();
    boolean detectCollisions(AbstractRigidBody gameObject);
    boolean checkCollision(AbstractRigidBody callerGameObject, AbstractRigidBody gameObject);
    // For now, just a boolean

    // For later
    // the GameObject that calls this functions expect in return, a feedback on all the collisions with other GameObjects of the scene
    // should return a vector of map<String,boolean>
    // so that the GameObject can implement the logic

private:
    std::vector<AbstractGameObject *> gameObjects;
};
#endif