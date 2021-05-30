#ifndef COLLISION_H
#define COLLISION_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QSize>

class Collision : public QObject
{
    Q_OBJECT
public:
    explicit Collision(QObject *parent = nullptr);
    bool checkCollison(QPoint pos1, QSize size1, QPoint pos2, QSize size2);
    bool checkCollisonRect(QRect rect, QPoint pos, QSize size);
    bool checkInside(QRect, QPoint pos, QSize size);

signals:

};

#endif // COLLISION_H
