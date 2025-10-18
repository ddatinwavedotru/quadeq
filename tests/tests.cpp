#include "gtest/gtest.h"
#include "solve.h"

const double epsilon=1e-7;

TEST(solve, x_sq_plus_1) {
    EXPECT_EQ(solve(1, 0, 1, epsilon), std::vector<double>());
}

TEST(solve, x_sq_minus_1) {
    EXPECT_EQ(solve(1, 0, -1, epsilon), std::vector<double>({-1,1}));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
