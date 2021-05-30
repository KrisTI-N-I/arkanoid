#ifndef TESTCOLLISION_H
#define TESTCOLLISION_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QPoint>
#include <QRect>
#include <QSize>

#include "../app/collision.h"

TEST(collision_test, no_collision)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(1, 1);

    QPoint pos2 = QPoint(2, 0);
    QSize size2 = QSize(1, 1);

    bool res = collision.checkCollison(pos1, size1, pos2, size2);
    EXPECT_FALSE(res);
}

TEST(collision_test, collision_edge)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(2, 2);

    QPoint pos2 = QPoint(2, 0);
    QSize size2 = QSize(1, 1);

    bool res = collision.checkCollison(pos1, size1, pos2, size2);
    EXPECT_FALSE(res);
}

TEST(collision_test, collision)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);

    QPoint pos2 = QPoint(2, 2);
    QSize size2 = QSize(2, 2);

    bool res = collision.checkCollison(pos1, size1, pos2, size2);
    EXPECT_TRUE(res);
}

TEST(collision_test, collision_corner)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);

    QPoint pos2 = QPoint(3, 3);
    QSize size2 = QSize(2, 2);

    bool res = collision.checkCollison(pos1, size1, pos2, size2);
    EXPECT_FALSE(res);
}

TEST(collision_test, no_rect_collision)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(1, 1);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(2, 0);
    QSize size = QSize(1, 1);

    bool res = collision.checkCollisonRect(rect, pos, size);
    EXPECT_FALSE(res);
}

TEST(collision_test, rect_collision_edge)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(2, 2);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(2, 0);
    QSize size = QSize(1, 1);

    bool res = collision.checkCollisonRect(rect, pos, size);
    EXPECT_FALSE(res);
}

TEST(collision_test, rect_collision)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(2, 2);
    QSize size = QSize(2, 2);

    bool res = collision.checkCollisonRect(rect, pos, size);
    EXPECT_TRUE(res);
}

TEST(collision_test, rect_collision_corner)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(3, 3);
    QSize size = QSize(2, 2);

    bool res = collision.checkCollisonRect(rect, pos, size);
    EXPECT_FALSE(res);
}

TEST(collision_test, inside)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(1, 1);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_TRUE(res);
}

TEST(collision_test, outside)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(5, 5);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_FALSE(res);
}

TEST(collision_test, inside_on_corner)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(2, 2);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_TRUE(res);
}

TEST(collision_test, outside_on_corner)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(3, 3);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_FALSE(res);
}

TEST(collision_test, inside_on_edge)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(2, 0);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_TRUE(res);
}

TEST(collision_test, outside_on_edge)
{
    Collision collision;

    QPoint pos1 = QPoint(0, 0);
    QSize size1 = QSize(3, 3);
    QRect rect = QRect(pos1, size1);

    QPoint pos = QPoint(3, 2);
    QSize size = QSize(1, 1);

    bool res = collision.checkInside(rect, pos, size);
    EXPECT_FALSE(res);
}


#endif // TESTCOLLISION_H
