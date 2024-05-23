#ifndef Abstract_Composite_Game_Object_H
#define Abstract_Composite_Game_Object_H

#include <vector>
#include "AbstractGameObject.h"

class AbstractCompositeGameObject
{
public:
    virtual void addGameObject(AbstractGameObject *gameObject);
    virtual void removeGameObject(AbstractGameObject *gameObject);
    virtual std::vector<AbstractGameObject *> getChildren();

private:
};

#endif