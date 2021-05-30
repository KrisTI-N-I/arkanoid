#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include <QPoint>
#include <QSize>
#include <QRect>
#include <QList>
#include <QPair>
#include "ball.h"
#include "panel.h"
#include "collision.h"

enum class GameState {
    playing,
    win,
    lose
};

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    GameState state;
    QSize fieldSize;
    QRect topWall;
    QRect leftWall;
    QRect rightWall;
    QTimer *timer;
    Ball *ball;
    Panel *panel;
    Collision collision;
    QList<QPair<bool, QRect>> blocks;

public slots:
    void update();
    void newGame();
    void setFieldSize(int w, int h);
    void setPanelSize(int w, int h);
    void setBallSize(int w, int h);
    void setPanelPos(int x, int y);
    void setBallPos(int x, int y);
    bool setBlocks(QList<int> posX, QList<int> posY, int w, int h);
    void resetBlocks();


signals:
    void updateGame(int ballX, int ballY, QList<bool> blocksState);
    void resetField();
    void winGame();
    void loseGame();
};


#endif // GAME_H
