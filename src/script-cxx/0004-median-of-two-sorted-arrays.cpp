// File Name: 0004-MEDIAN-OF-TWO-SORTED-ARRAYS.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved. 
// Created:  6 November 2021 

#include "headers.h"
#include <gtest/gtest.h>

class Solution{
public: 
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
        {
            int n = A.size(), m = B.size();
            if (n > m) {
                return findMedianSortedArrays(B, A); // Swapping to make A smaller
            }
 
            int start = 0;
            int end = n;
            int mid_posi = (n + m + 1) / 2;
 
            while (start <= end) {
                int mid = (start + end) / 2;
                int leftAsize = mid;
                int leftBsize = mid_posi - mid;
                int leftA = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN; // checking overflow of indices
                int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
                int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
                int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;
                // if correct partition is done
                if (leftA <= rightB and leftB <= rightA) {
                    // switch ( (m + n) % 2) {
                    // case 0:
                    //     return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                    // case 1:
                    //     return max(leftA, leftB);
                    // }
                    if ((m + n) % 2 == 0){
                        return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                    }
                    else {
                        return max(leftA, leftB);
                    }
                }
                else if (leftA > rightB) {
                    end = mid - 1;
                }
                else
                start = mid + 1;
            }
            return 0.0;
        }
};

TEST(TTT, TTT) {
    Solution s;
    // vector<int> nums1 = { 1,2,3 },nums2 = { 4,5,6 };
    vector<int> nums1 = { 1,2,3 },nums2 = { 4,5,6 };
    double expect = 3.5;
    double actual;
    actual = s.findMedianSortedArrays(nums1,nums2);
    EXPECT_EQ(expect,actual);
}


int main(int argc, char **argv) {
    cout << "Problem: 0004-MEDIAN-OF-TWO-SORTED-ARRAYS.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
