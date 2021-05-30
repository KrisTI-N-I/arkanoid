#include "collision.h"

Collision::Collision(QObject *parent) : QObject(parent)
{

}

bool Collision::checkCollison(QPoint pos1, QSize size1, QPoint pos2, QSize size2) {
    QRect rect1 = QRect(pos1, size1);
    QRect rect2 = QRect(pos2, size2);

    return rect1.intersects(rect2);
}

bool Collision::checkCollisonRect(QRect rect, QPoint pos, QSize size) {
    QRect rect2 = QRect(pos, size);

    return rect.intersects(rect2);
}

bool Collision::checkInside(QRect rect, QPoint pos, QSize size) {
    QRect rect2 = QRect(pos, size);

    return rect.contains(rect2);
}
