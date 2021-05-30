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
    QList<QPair<bool, QRect>> blocks;

    QList<int> posX;
    QList<int> posY;
    int w = 20, h = 30;

    for (int i = 0; i < 10; i++) {
        posX.push_back(w*i);
        posY.push_back(0);
    }

    game.setBlocks(posX, posY, w, h);
    game.resetBlocks();
    for(int i = 0; i < blocks.length(); i++) {
        EXPECT_TRUE(blocks[i].first);
    }
}

#endif // TESTGAME_H
