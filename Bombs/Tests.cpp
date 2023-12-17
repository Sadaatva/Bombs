#include <gtest/gtest.h>
#include "explosion.h"

TEST(ExplosionTest, TestVariant1) {
    Explosion explosion;

    std::vector<std::vector<int>> bombs = {{1, 1, 5}, {10, 10, 5}};
    auto result = explosion.maximumDetonated(bombs);

    EXPECT_EQ(result.first, 1);
    EXPECT_TRUE((result.second == std::vector<int>{1, 1, 5}) || (result.second == std::vector<int>{10, 10, 5}));
}

TEST(ExplosionTest, TestVariant2) {
    Explosion explosion;

    std::vector<std::vector<int>> bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    auto result = explosion.maximumDetonated(bombs);

    EXPECT_EQ(result.first, 5); //  количество взорванных бомб
    EXPECT_EQ(result.second[0], 1); // x-координата
    EXPECT_EQ(result.second[1], 2); // y-координата
    EXPECT_EQ(result.second[2], 3); // радиус
}

TEST(ExplosionTest, TestVariant3) {
    Explosion explosion;

    std::vector<std::vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    auto result = explosion.maximumDetonated(bombs);

    EXPECT_EQ(result.first, 2); 
    EXPECT_TRUE((result.second == std::vector<int>{2, 1, 3}) || (result.second == std::vector<int>{6, 1, 4}));
}
