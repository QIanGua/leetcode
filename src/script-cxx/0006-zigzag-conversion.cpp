// File Name: 0006-ZIGZAG-CONVERSION.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 12 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        int d = s.size();
        int step = 2 * numRows - 2;
        int add = 0;
        int idx;
        for (int i = 0; i < numRows; i++) {
            idx = i;
            add = 2*i;
            while (idx < d) {
                ret += s[idx];
                add = step - add;
                idx += ( i == 0 || i == numRows - 1 ? step : add);
            }
        }
        return ret;
    }
};

TEST(TTT, TTT1)
{
    Solution s;
    string s1 = "PAYPALISHIRING";
    string expect = "PAHNAPLSIIGYIR";
    int num = 3;
    string actual = s.convert(s1,num);
    EXPECT_TRUE(expect == actual);

}

TEST(TTT, TTT2)
{
    Solution s;
    string s1 = "PAYPALISHIRING";
    int num = 4;
    string expect = "PINALSIGYAHRPI";
    string actual = s.convert(s1,num);
    EXPECT_TRUE(expect == actual);
}

TEST(TTT, TTT3)
{
    Solution s;
    string s1 = "A";
    int num = 1;
    string expect = "A";
    string actual = s.convert(s1,num);
    EXPECT_TRUE(expect == actual);
}

int main(int argc, char **argv)
{
    cout << "Problem: 0006-ZIGZAG-CONVERSION.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}