#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QRandomGenerator>

class Ball : public QObject
{
    Q_OBJECT
public:
    explicit Ball(QObject *parent = nullptr);
    QPoint getPos();
    void setPos(QPoint newPos);
    QSize getSize();
    void setSize(QSize newSize);
    void resetAcc();
    void update();
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void randomizeX();

    QPoint acceleration;

private:
    QPoint pos;
    QSize size;



signals:

};

#endif // BALL_H
