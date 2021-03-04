#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "../headers/rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    srand(8);
    Rand* test = new Rand();
    EXPECT_EQ(test->evaluate(), 96);
}

#endif //__RAND_TEST_HPP__
