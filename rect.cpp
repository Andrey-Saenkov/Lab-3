#include "rect.h"
#include <QPainter>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

Rect::Rect()
    : Rect(0, 0, 0, 0)
{

}

Rect::Rect(int x1, int y1, int x2, int y2)
{
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        if (x1 > x2)
            std::swap(x1,x2);
        if (y1 > y2)
            std::swap(y1,y2);

}

//Rect Rect::InterSection(Rect *other) // 4 координаты
//{

//}

void Rect::draw(QPainter *painter, int n)
{
    QColor palette[] = {Qt::red, Qt::yellow, Qt::green, Qt::blue, Qt::black};
    painter->setBrush(n==0? QBrush() : QBrush(palette[n - 1]));
    painter->drawRect(x1, y1, x2 - x1, y2 - y1);
}

bool Rect::contains(int x, int y)
{
    //return false;
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}

Rect Rect::InterSection(const Rect &r)
{
    int xl = max(x1, r.x1);
    int xr = min(x2, r.x2);
    int yl = max(y1, r.y1);
    int yr = min(y2, r.y2);
    bool valid = (xr >= xl) && (yr >= yl);

    return valid ? Rect(xl, yl, xr, yr) : Rect();
//    return Rect();
}


