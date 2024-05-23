#ifndef Collision_Detector_H
#define Collision_Detector_H

#include "AbstractGameObject.h"
#include <vector>

class CollisionDetector
{
public:
    CollisionDetector();
    boolean checkCollision(AbstractGameObject *callerGameObject, AbstractGameObject *gameObject);

private:
};
#endif