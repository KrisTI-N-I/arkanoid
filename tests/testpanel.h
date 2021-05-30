#ifndef TESTPANEL_H
#define TESTPANEL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QPoint>
#include <QSize>

#include "../app/panel.h"

TEST(panel_test, usual)
{
    Panel panel;
    QPoint pos = QPoint(1, 1);
    panel.setPos(pos);

    QPoint res = panel.getPos();
    EXPECT_EQ(res.x(), 1);
    EXPECT_EQ(res.y(), 1);
}

TEST(panel_test, minus)
{
    Panel panel;
    QPoint pos = QPoint(-1000, -1000);
    panel.setPos(pos);

    QPoint res = panel.getPos();
    EXPECT_EQ(res.x(), -1000);
    EXPECT_EQ(res.y(), -1000);
}

TEST(panel_test, more)
{
    Panel panel;
    QPoint pos = QPoint(1000, 1000);
    panel.setPos(pos);

    QPoint res = panel.getPos();
    EXPECT_EQ(res.x(), 1000);
    EXPECT_EQ(res.y(), 1000);
}

TEST(panel_test, diff)
{
    Panel panel;
    QPoint pos = QPoint(100, 1000);
    panel.setPos(pos);

    QPoint res = panel.getPos();
    EXPECT_EQ(res.x(), 100);
    EXPECT_EQ(res.y(), 1000);
}


TEST(panel_test, usual_size)
{
    Panel panel;
    QSize size = QSize(100, 100);
    panel.setSize(size);

    QSize res = panel.getSize();
    EXPECT_EQ(res.width(), 100);
    EXPECT_EQ(res.height(), 100);
    EXPECT_TRUE(!res.isEmpty());
}

TEST(panel_test, minus_size)
{
    Panel panel;
    QSize size = QSize(-1000, -1000);
    panel.setSize(size);

    QSize res = panel.getSize();
    EXPECT_EQ(res.width(), -1000);
    EXPECT_EQ(res.height(), -1000);
    EXPECT_TRUE(res.isEmpty());
}

TEST(panel_test, more_size)
{
    Panel panel;
    QSize size = QSize(1000, 1000);
    panel.setSize(size);

    QSize res = panel.getSize();
    EXPECT_EQ(res.width(), 1000);
    EXPECT_EQ(res.height(), 1000);
    EXPECT_TRUE(!res.isEmpty());
}

TEST(panel_test, zero_size)
{
    Panel panel;
    QSize size = QSize(0, 0);
    panel.setSize(size);

    QSize res = panel.getSize();
    EXPECT_EQ(res.width(), 0);
    EXPECT_EQ(res.height(), 0);
    EXPECT_TRUE(res.isEmpty());
}

TEST(panel_test, not_init)
{
    Panel panel;

    QPoint res_pos = panel.getPos();

    EXPECT_TRUE(res_pos.isNull());
}



#endif // TESTPANEL_H
