// File Name: 02-FIBONACCI.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 27 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    //loop
    int  fib1(int n) {
        int MOD=1000000007;
        if (n >=0 && n < 2) {
            return n;
        }
        else {
            return (fib1(n-1) + fib1(n-2)) % MOD;
        }

    }
    //dynamical
    int fib2(int n) {
        int MOD=1000000007;
        if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; i++) {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};

TEST(TTT, TTT) {
    Solution s;
    EXPECT_EQ(s.fib1(0),0);
    EXPECT_EQ(s.fib1(1),1);
    EXPECT_EQ(s.fib1(2),1);
    EXPECT_EQ(s.fib1(3),2);
    EXPECT_EQ(s.fib1(4),3);

    EXPECT_EQ(s.fib2(0),0);
    EXPECT_EQ(s.fib2(1),1);
    EXPECT_EQ(s.fib2(2),1);
    EXPECT_EQ(s.fib2(3),2);
    EXPECT_EQ(s.fib2(4),3);
}


int main(int argc, char **argv) {
    cout << "Problem: 02-FIBONACCI.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}