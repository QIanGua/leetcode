// File Name: 0009-PALINDROME.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 22 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    bool isParlindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x!= 0)) {
            return false;
        }
        int revertedNum = 0;
        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNum || x == revertedNum / 10;
    }

};

TEST(TTT, TTT) {
    Solution s;
    int num = 121;
    bool expect = true,actual = Solution().isParlindrome(num);
    EXPECT_EQ(expect,actual);
}


int main(int argc, char **argv) {
    cout << "Problem: 0009-PALINDROME.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}