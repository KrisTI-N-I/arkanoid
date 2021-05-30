#ifndef TESTBALL_H
#define TESTBALL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QPoint>
#include <QSize>
#include <QRandomGenerator>

#include "../app/ball.h"

TEST(ball_test, usual)
{
    Ball ball;
    QPoint pos = QPoint(1, 1);
    ball.setPos(pos);

    QPoint res = ball.getPos();
    EXPECT_EQ(res.x(), 1);
    EXPECT_EQ(res.y(), 1);
}

TEST(ball_test, minus)
{
    Ball ball;
    QPoint pos = QPoint(-1000, -1000);
    ball.setPos(pos);

    QPoint res = ball.getPos();
    EXPECT_EQ(res.x(), -1000);
    EXPECT_EQ(res.y(), -1000);
}

TEST(ball_test, more)
{
    Ball ball;
    QPoint pos = QPoint(1000, 1000);
    ball.setPos(pos);

    QPoint res = ball.getPos();
    EXPECT_EQ(res.x(), 1000);
    EXPECT_EQ(res.y(), 1000);
}

TEST(ball_test, diff)
{
    Ball ball;
    QPoint pos = QPoint(100, 1000);
    ball.setPos(pos);

    QPoint res = ball.getPos();
    EXPECT_EQ(res.x(), 100);
    EXPECT_EQ(res.y(), 1000);
}


TEST(ball_test, usual_size)
{
    Ball ball;
    QSize size = QSize(100, 100);
    ball.setSize(size);

    QSize res = ball.getSize();
    EXPECT_EQ(res.width(), 100);
    EXPECT_EQ(res.height(), 100);
    EXPECT_TRUE(!res.isEmpty());
}

TEST(ball_test, minus_size)
{
    Ball ball;
    QSize size = QSize(-1000, -1000);
    ball.setSize(size);

    QSize res = ball.getSize();
    EXPECT_EQ(res.width(), -1000);
    EXPECT_EQ(res.height(), -1000);
    EXPECT_TRUE(res.isEmpty());
}

TEST(ball_test, more_size)
{
    Ball ball;
    QSize size = QSize(1000, 1000);
    ball.setSize(size);

    QSize res = ball.getSize();
    EXPECT_EQ(res.width(), 1000);
    EXPECT_EQ(res.height(), 1000);
    EXPECT_TRUE(!res.isEmpty());
}

TEST(ball_test, zero_size)
{
    Ball ball;
    QSize size = QSize(0, 0);
    ball.setSize(size);

    QSize res = ball.getSize();
    EXPECT_EQ(res.width(), 0);
    EXPECT_EQ(res.height(), 0);
    EXPECT_TRUE(res.isEmpty());
}

TEST(ball_test, not_init)
{
    Ball ball;

    QPoint res_pos = ball.getPos();

    EXPECT_TRUE(res_pos.isNull());
}

TEST(ball_test, reset)
{
    Ball ball;

    ball.acceleration = QPoint(10, 10);
    ball.resetAcc();

    EXPECT_EQ(ball.acceleration.x(), 0);
    EXPECT_EQ(ball.acceleration.y(), 5);
}

TEST(ball_test, update_usual)
{
    Ball ball;

    ball.setPos(QPoint(1, 10));
    ball.acceleration = QPoint(10, 100);

    ball.update();

    EXPECT_EQ(11, ball.getPos().x());
    EXPECT_EQ(110, ball.getPos().y());
}

TEST(ball_test, update_minus)
{
    Ball ball;

    ball.setPos(QPoint(1, 10));
    ball.acceleration = QPoint(-10, -100);

    ball.update();

    EXPECT_EQ(-9, ball.getPos().x());
    EXPECT_EQ(-90, ball.getPos().y());
}

TEST(ball_test, update_more)
{
    Ball ball;

    ball.setPos(QPoint(1000, 10));
    ball.acceleration = QPoint(1000, 100);

    ball.update();

    EXPECT_EQ(2000, ball.getPos().x());
    EXPECT_EQ(110, ball.getPos().y());
}

TEST(ball_test, update_minus_pos)
{
    Ball ball;

    ball.setPos(QPoint(-100, -10));
    ball.acceleration = QPoint(1000, 100);

    ball.update();

    EXPECT_EQ(900, ball.getPos().x());
    EXPECT_EQ(90, ball.getPos().y());
}

TEST(ball_test, update_minus_all)
{
    Ball ball;

    ball.setPos(QPoint(-100, -10));
    ball.acceleration = QPoint(-1000, -100);

    ball.update();

    EXPECT_EQ(-1100, ball.getPos().x());
    EXPECT_EQ(-110, ball.getPos().y());
}

TEST(ball_test, goup_plus)
{
    Ball ball;

    ball.acceleration = QPoint(1, 100);

    ball.goUp();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(-100, ball.acceleration.y());
}

TEST(ball_test, goup_minus)
{
    Ball ball;

    ball.acceleration = QPoint(1, -100);

    ball.goUp();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(-100, ball.acceleration.y());
}

TEST(ball_test, goup_zero)
{
    Ball ball;

    ball.acceleration = QPoint(1, 0);

    ball.goUp();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(0, ball.acceleration.y());
}

TEST(ball_test, godown_plus)
{
    Ball ball;

    ball.acceleration = QPoint(1, 100);

    ball.goDown();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(100, ball.acceleration.y());
}

TEST(ball_test, godown_minus)
{
    Ball ball;

    ball.acceleration = QPoint(1, -100);

    ball.goDown();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(100, ball.acceleration.y());
}

TEST(ball_test, godown_zero)
{
    Ball ball;

    ball.acceleration = QPoint(1, 0);

    ball.goDown();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(0, ball.acceleration.y());
}

TEST(ball_test, goleft_plus)
{
    Ball ball;

    ball.acceleration = QPoint(1, 1);

    ball.goLeft();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(1, ball.acceleration.y());
}

TEST(ball_test, goleft_minus)
{
    Ball ball;

    ball.acceleration = QPoint(-1, -1);

    ball.goLeft();

    EXPECT_EQ(1, ball.acceleration.x());
    EXPECT_EQ(-1, ball.acceleration.y());
}

TEST(ball_test, goleft_zero)
{
    Ball ball;

    ball.acceleration = QPoint(0, 1);

    ball.goLeft();

    EXPECT_EQ(0, ball.acceleration.x());
    EXPECT_EQ(1, ball.acceleration.y());
}

TEST(ball_test, goright_plus)
{
    Ball ball;

    ball.acceleration = QPoint(1, 1);

    ball.goRight();

    EXPECT_EQ(-1, ball.acceleration.x());
    EXPECT_EQ(1, ball.acceleration.y());
}

TEST(ball_test, goright_minus)
{
    Ball ball;

    ball.acceleration = QPoint(-1, -1);

    ball.goRight();

    EXPECT_EQ(-1, ball.acceleration.x());
    EXPECT_EQ(-1, ball.acceleration.y());
}

TEST(ball_test, goright_zero)
{
    Ball ball;

    ball.acceleration = QPoint(0, 1);

    ball.goRight();

    EXPECT_EQ(0, ball.acceleration.x());
    EXPECT_EQ(1, ball.acceleration.y());
}

#endif // TESTBALL_H
