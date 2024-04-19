#ifndef Abstract_Game_Object_H
#define Abstract_Game_Object_H

class AbstractGameObject
{
public:
    virtual void update();
    virtual void render();

private:
};
#endif