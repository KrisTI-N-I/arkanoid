#include "panel.h"

Panel::Panel()
{

}

void Panel::setPos(QPoint newPos) {
    pos = newPos;
}

QPoint Panel::getPos() {
    return pos;
}

void Panel::setSize(QSize newSize) {
    size = newSize;
}

QSize Panel::getSize() {
    return size;
}
