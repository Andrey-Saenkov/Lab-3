#ifndef RECT_H
#define RECT_H

class QPainter;

class Rect
{
public:
    Rect();
    Rect(int x1, int y1, int x2, int y2);
    //Rect InterSection(Rect *other);

    void draw(QPainter *painter, int n = 0);
    bool contains(int x, int y);
    Rect InterSection(const Rect & r);

private:
    int x1, y1, x2, y2;

};


#endif // RECT_H
