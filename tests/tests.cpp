#include "gtest/gtest.h"
#include "solve.h"

TEST(solve, x_sq_plus_1) {
    EXPECT_EQ(solve(1, 0, 1), std::vector<double>());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
