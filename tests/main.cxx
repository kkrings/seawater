/**
 *
 * Main test executable
 *
 * (c) 2019
 * Kai Krings
 *
 * @file main.cxx
 * @date 2019-08-26
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
