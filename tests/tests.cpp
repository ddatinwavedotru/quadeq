#include "gtest/gtest.h"
#include "solve.h"

const double epsilon=1e-7;

TEST(solve, x_sq_plus_1) {
    EXPECT_EQ(solve(1, 0, 1, epsilon), std::vector<double>());
}

TEST(solve, x_sq_minus_1) {
    EXPECT_EQ(solve(1, 0, -1, epsilon), std::vector<double>({-1,1}));
}

TEST(solve, x_sq_plus_2_x_plus_1) {
    EXPECT_EQ(solve(1, 2, 1, epsilon), std::vector<double>({-1,-1}));
}

TEST(solve, a_is_almost_zero) {
    EXPECT_THROW(solve(1e-9,2,1,epsilon),a_is_almost_zero_exception);
}

TEST(solve, D_is_almost_zero) {
    std::vector<double> solution=solve(1, 2+epsilon/5, 1, epsilon);
    EXPECT_EQ(solution.size(), 2);
    EXPECT_EQ(solution[0], solution[1]);
}

TEST(solve, not_a_numbers) {
    double special_values[]={
        std::numeric_limits<double>::quiet_NaN(),
        std::numeric_limits<double>::signaling_NaN(),
        std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity()
    };
    for(double a: special_values) {
        EXPECT_THROW(solve(a,2,1,epsilon),a_is_special_double_exception);
    }
    for(double b: special_values) {
        EXPECT_THROW(solve(1,b,1,epsilon),b_is_special_double_exception);
    }
    for(double c: special_values) {
        EXPECT_THROW(solve(1,2,c,epsilon),c_is_special_double_exception);
    }
    for(double epsilon: special_values) {
        EXPECT_THROW(solve(1,2,1,epsilon),epsilon_is_special_double_exception);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
