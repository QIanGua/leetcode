// File Name: 0007-REVERSE.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 14 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    int reverse(int x) {
        int tmp = 0;
        if (x == 0)  return 0;
        while (x != 0) {
            if (tmp > INT_MAX/10 || tmp < INT_MIN/10) {
                return 0;
            }
            else {
                tmp = tmp * 10 + x % 10;
                x = x/10;
            }
        }
        return tmp;
    }

};

// TEST(TTT, TTT1) {
//     Solution s;
//     int n1 = 123;
//     int expect = 321;
//     int actual = s.reverse(n1);
//     EXPECT_EQ(expect,actual);
// }

// TEST(TTT, TTT2) {
//     Solution s;
//     int n1 = -123;
//     int expect = -321;
//     int actual = s.reverse(n1);
//     EXPECT_EQ(expect,actual);
// }

// TEST(TTT, TTT3) {
//     Solution s;
//     int n1 = -123;
//     int expect = -321;
//     int actual = s.reverse(n1);
//     EXPECT_EQ(expect,actual);
// }

TEST(TTT, TTT4) {
    Solution s;
    int n1 = -2147483412;
    int expect = -2143847412;
    int actual = s.reverse(n1);
    EXPECT_EQ(expect,actual);
}

int main(int argc, char **argv)
{
    cout << "Problem: 0007-REVERSE.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}