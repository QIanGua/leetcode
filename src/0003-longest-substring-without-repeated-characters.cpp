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
        unordered_map<int,int> subset;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if(subset.find(s[i]) == subset.end()){
                subset[s[i]] = i;
            }
        }
        return subset.size();
    };
};

// int main(int argc, char *argv[])
// {
//     // unordered_map<int,int> map;
//     // map.insert(make_pair(1,2));
//     // map.insert(make_pair(2,4));
//     // cout << map[1] << endl;
//     // cout << map.size() << endl;
//     Solution s;
//     string s1 = "abcddee";
//     cout << s.lengthOfLongestSubstring(s1) << endl;
//     return 0;
// }

TEST(TTT, TTT) {
    Solution s;
    string s1 = "abcdeeff";
    int expect = 6;
    int test = s.lengthOfLongestSubstring(s1);
    EXPECT_EQ(expect,test);
};


int main(int argc, char **argv) {
    cout << "Problem: 0003-LONGEST-SUBSTRING-WITHOUT-REPEATED-CHARACTERS.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}