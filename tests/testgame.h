#ifndef TESTGAME_H
#define TESTGAME_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QTimer>
#include <iostream>
#include <QPoint>
#include <QSize>
#include <QRect>
#include <QList>
#include <QPair>

#include "../app/ball.h"
#include "../app/panel.h"
#include "../app/collision.h"
#include "../app/game.h"

TEST(game_test, init)
{
    Game game;

    EXPECT_FALSE(game.timer == nullptr);
    EXPECT_FALSE(game.ball == nullptr);
    EXPECT_FALSE(game.panel == nullptr);
    EXPECT_TRUE(game.state == GameState::playing);
}

TEST(game_test, setFieldSize)
{
    Game game;

    game.setFieldSize(600, 800);

    EXPECT_EQ(game.fieldSize, QSize(600, 800));
    EXPECT_EQ(game.topWall, QRect(QPoint(0, 0), QSize(600, 1)));
    EXPECT_EQ(game.rightWall, QRect(QPoint(0, 0), QSize(1, 800)));
    EXPECT_EQ(game.leftWall, QRect(QPoint(600, 0), QSize(1, 800)));
}

TEST(game_test, setFieldSize_zero)
{
    Game game;

    game.setFieldSize(0, 0);

    EXPECT_EQ(game.fieldSize, QSize(0, 0));
    EXPECT_TRUE(game.fieldSize.isEmpty());

    EXPECT_EQ(game.topWall, QRect(QPoint(0, 0), QSize(0, 1)));
    EXPECT_EQ(game.rightWall, QRect(QPoint(0, 0), QSize(1, 0)));
    EXPECT_EQ(game.leftWall, QRect(QPoint(0, 0), QSize(1, 0)));
}

TEST(game_test, setFieldSize_minus)
{
    Game game;

    game.setFieldSize(-10, -50);

    EXPECT_EQ(game.fieldSize, QSize(-10, -50));
    EXPECT_EQ(game.topWall, QRect(QPoint(0, 0), QSize(-10, 1)));
    EXPECT_EQ(game.rightWall, QRect(QPoint(0, 0), QSize(1, -50)));
    EXPECT_EQ(game.leftWall, QRect(QPoint(-10, 0), QSize(1, -50)));
}

TEST(game_test, setBlocks_usual)
{
    Game game;
    QList<QPair<bool, QRect>> blocks;

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    bool res = game.setBlocks(posX, posY, w, h);
    EXPECT_TRUE(res);
}

TEST(game_test, setBlocks_false)
{
    Game game;
    QList<QPair<bool, QRect>> blocks;

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    posY.push_back(1);
    bool res = game.setBlocks(posX, posY, w, h);
    EXPECT_FALSE(res);
}

TEST(game_test, resetBlocks)
{
    Game game;

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.resetBlocks();
    for(int i = 0; i < game.blocks.length(); i++) {
        EXPECT_TRUE(game.blocks[i].first);
    }
}

TEST(game_test, usual)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(1000, 1000));
    game.ball->setSize(QSize(1, 1));
    game.update();
    EXPECT_TRUE(game.state == GameState::lose);
}

TEST(game_test, usual2)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(100, 100));
    game.ball->setSize(QSize(2, 2));
    game.panel->setPos(QPoint(100, 100));
    game.panel->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(1, 100);

    game.update();
    EXPECT_EQ(-100, game.ball->acceleration.y());
}

TEST(game_test, usual3)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(0, -1));
    game.ball->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(1, -100);

    game.update();
    EXPECT_EQ(100, game.ball->acceleration.y());
}

TEST(game_test, usual4)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(0, 50));
    game.ball->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(-1, 100);

    game.update();
    EXPECT_EQ(1, game.ball->acceleration.x());
}

TEST(game_test, usual5)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(600, 50));
    game.ball->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(1, 100);

    game.update();
    EXPECT_EQ(-1, game.ball->acceleration.x());
}

TEST(game_test, usual6)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(600, 50));
    game.ball->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(1, 100);

    for(int i = 0; i < game.blocks.length(); i++) {
        game.blocks[i].first = false;
    }
    game.update();
    EXPECT_TRUE(game.state == GameState::win);
}

TEST(game_test, usual7)
{
    Game game;

    game.setPanelSize(10, 10);
    game.setPanelPos(1, 1);

    QPoint res = game.panel->getPos();
    EXPECT_EQ(res.x(), 1);
    EXPECT_EQ(res.y(), 1);

    QSize res2 = game.panel->getSize();
    EXPECT_EQ(res2.width(), 10);
    EXPECT_EQ(res2.height(), 10);

    game.setBallSize(100, 100);
    game.setBallPos(10, 10);

    QPoint res3 = game.ball->getPos();
    EXPECT_EQ(res3.x(), 10);
    EXPECT_EQ(res3.y(), 10);

    QSize res4 = game.ball->getSize();
    EXPECT_EQ(res4.width(), 100);
    EXPECT_EQ(res4.height(), 100);
}

TEST(game_test, usual8)
{
    Game game;

    game.setFieldSize(600, 800);

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.ball->setPos(QPoint(600, 50));
    game.ball->setSize(QSize(2, 2));
    game.ball->acceleration = QPoint(1, 100);

    for(int i = 0; i < game.blocks.length(); i++) {
        game.blocks[i].first = false;
    }
    game.update();
    game.timer->start();
    game.newGame();
    EXPECT_EQ(game.ball->acceleration, QPoint(0, 5));
    for(int i = 0; i < game.blocks.length(); i++) {
        EXPECT_TRUE(game.blocks[i].first);
    }
}


#endif // TESTGAME_H
