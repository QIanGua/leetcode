#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    vector<int>  twoSums1(vector<int> nums, int target){
        int i,j;
        for (i = 0; i < nums.size(); ++i) {
            for (j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {}; 
    };

    vector<int> twoSums2(vector<int> nums, int target){
        unordered_map<int,int> hashtable;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];
            if (hashtable.find(num) != hashtable.end()) {
                return {hashtable[num],i};
            }
            else {
                hashtable[nums[i]] = i;
            }
        }
        return {};
    };

};


TEST(Case0001,solution){
    vector<int> nums = {2,7,11,15};
    vector<int> result = {0,1};
    int target = 9;
    Solution test;

    EXPECT_EQ(result, test.twoSums1(nums, target));
    EXPECT_EQ(result, test.twoSums2(nums, target));
}


int main(int argc, char *argv[]) {
    cout << "Problem: 0001-TWO-SUMS.CPP" << endl;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}