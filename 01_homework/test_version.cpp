#include <gtest/gtest.h>
#include "lib.hpp"

TEST(Hello_World, Version_test)
{
    ASSERT_TRUE(version() != 0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}