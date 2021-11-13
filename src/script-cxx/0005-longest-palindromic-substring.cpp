// File Name: 0005-LONGEST-PALINDROMIC-SUBSTRING.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved. 
// Created:  8 November 2021 

#include "headers.h"
#include <gtest/gtest.h>

class Solution{
public:
    string longestPalindrome(string s){
        int  d =  s.size();
        if (d == 0) {
            return "";
        }

        int left = 0, right = 0, pl = 0, pr = 0;
        // while (left < d) {
        while (right < d) {
            // init case: left = right
            //if even case: center s[left]==s[right + 1]
            while (right + 1 < d and s[left] == s[right + 1]) {
                ++right;
            }
            // find the boundary
            while (left - 1 >=0 and right + 1 < d and s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            // compare length with previous max result
            if (right - left > pr - pl) {
                pl = left;
                pr = right;
            }
            // moving center to right
            left = (left + right)/2 + 1;
            right = left;
        }
        // substr(start_posi,length)
        return s.substr(pl,pr-pl+1);
    }
};

TEST(TTT, TTT1) {
    Solution s;
    string s1 = "babad";
    string expect = "bab";
    string actual = s.longestPalindrome(s1);
    EXPECT_TRUE(expect == actual);
}

TEST(TTT, TTT2) {
    Solution s;
    string s1 = "cbbd";
    string expect = "bb";
    string actual = s.longestPalindrome(s1);
    EXPECT_TRUE(expect == actual);
}

TEST(TTT, TTT3) {
    Solution s;
    string s1 = "a";
    string expect = "a";
    string actual = s.longestPalindrome(s1);
    EXPECT_TRUE(expect == actual);
}

TEST(TTT, TTT4) {
    Solution s;
    string s1 = "ac";
    string expect = "a";
    string actual = s.longestPalindrome(s1);
    EXPECT_TRUE(expect == actual);
}
int main(int argc, char **argv)
{
    cout << "Problem: 0005-LONGEST-PALINDROMIC-SUBSTRING.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}