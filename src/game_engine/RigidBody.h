#ifndef Rigid_Body
#define Rigid_Body

class RigidBody
{
public:
    RigidBody(int x, int y, int width, int height);
    int getX() { return x; };
    int getY() { return y; };
    int getWidth() { return width; };
    int getHeight() { return height; };
    void setX(int newX);
    void setY(int newY);

private:
    int x;
    int y;
    int width;
    int height;
};

#endif