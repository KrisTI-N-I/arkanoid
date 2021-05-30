#include "ball.h"

Ball::Ball(QObject *parent) : QObject(parent)
{
    resetAcc();
}

QPoint Ball::getPos() {
    return pos;
}

void Ball::update() {
    pos += acceleration;
}

void Ball::setPos(QPoint newPos) {
    pos = newPos;
}

void Ball::resetAcc() {
    acceleration = QPoint(0, 5);
}

void Ball::setSize(QSize newSize) {
    size = newSize;
}

QSize Ball::getSize() {
    return size;
}

void Ball::goUp() {
    if(acceleration.y() < 0) return;
    acceleration = QPoint(acceleration.x(), acceleration.y() * -1);
}

void Ball::goDown() {
    if(acceleration.y() > 0) return;
    acceleration = QPoint(acceleration.x(), acceleration.y() * -1);
}

void Ball::goLeft() {
    if(acceleration.x() > 0) return;
    acceleration = QPoint(acceleration.x() * -1, acceleration.y());
}

void Ball::goRight() {
    if(acceleration.x() < 0) return;
    acceleration = QPoint(acceleration.x() * -1, acceleration.y());
}

void Ball::randomizeX() {
    int minX = -2;
    int maxX = 2;
    if(acceleration.x() <= -4) {
        minX = 0;
    } else if(acceleration.x() >= 4) {
        maxX = 0;
    }
    int accShift = QRandomGenerator::system()->bounded(minX, maxX + 1);
    acceleration += QPoint(accShift, 0);
}
