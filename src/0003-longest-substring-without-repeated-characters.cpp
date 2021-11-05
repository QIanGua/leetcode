// File Name: 0003-LONGEST-SUBSTRING-WITHOUT-REPEATED-CHARACTERS.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved. 
// Created:  4 November 2021 

#include "headers.h"
#include <gtest/gtest.h>
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> last_idx;
        int i, start_idx = 0, max_len = 0;
        for (i = 0; i < s.size(); ++i) {
            if(last_idx.find(s[i]) != last_idx.end()){
                start_idx = max(start_idx,last_idx[s[i]] + 1);
            }
            max_len = max(max_len, i - start_idx + 1);
            last_idx[s[i]] = i;
        }
        return max_len;
    };
};


TEST(TTT, TTT1) {
    Solution s;
    // string s1 = "abba";
    string s1 = " ";
    int expect = 1;
    int test = s.lengthOfLongestSubstring(s1);
    EXPECT_EQ(expect,test);
};

TEST(TTT, TTT2) {
    Solution s;
    string s1 = "";
    int expect = 0;
    int test = s.lengthOfLongestSubstring(s1);
    EXPECT_EQ(expect,test);
};

TEST(TTT, TTT3) {
    Solution s;
    string s1 = "d-x";
    int expect = 3;
    int test = s.lengthOfLongestSubstring(s1);
    EXPECT_EQ(expect,test);
};

int main(int argc, char **argv) {
    cout << "Problem: 0003-LONGEST-SUBSTRING-WITHOUT-REPEATED-CHARACTERS.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}