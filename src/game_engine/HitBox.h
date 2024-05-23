#ifndef Hit_Box
#define Hit_Box

class HitBox
{
public:
    HitBox(int x, int y, int width, int height);
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