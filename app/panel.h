#ifndef PANEL_H
#define PANEL_H

#include <QPoint>
#include <QSize>

class Panel
{
public:
    Panel();
    void setPos(QPoint newPos);
    QPoint getPos();
    void setSize(QSize newSize);
    QSize getSize();

private:
    QPoint pos;
    QSize size;
};

#endif // PANEL_H
