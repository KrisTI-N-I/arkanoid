#include <gtest/gtest.h>

#include "testpanel.h"
#include "testcollision.h"
#include "testball.h"
#include "testgame.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
