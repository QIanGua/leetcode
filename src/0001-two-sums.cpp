#include "headers.h"
#include <gtest/gtest.h>

class Solution1 {
public:
    vector<int>  twoSums( vector<int> nums, int target){
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
};

class Solution2{
public:
    vector<int> twoSums(vector<int> nums, int target){
        unordered_map<int,int> hashtable;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it -> second,i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    };
};

TEST(Case0001,sol1){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int> result;
    result.push_back(0);
    result.push_back(1);

    int target = 9;
    Solution1 test1;

    EXPECT_EQ(result, test1.twoSums(nums, target));
}


TEST(Case0001,sol2){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int> result;
    result.push_back(0);
    result.push_back(1);

    int target = 9;
    Solution2 test2;

    EXPECT_EQ(result, test2.twoSums(nums, target));
}

int main(int argc, char *argv[])
{
    // vector<int> nums = {2,7,11,15};
    // vector<int> a1;
    // // int i, target = 9;
    // int i, target = 26;
    // Solution1 test1;

    // a1 = test1.twoSums(nums,target);
    
    // for (i = 0; i < a1.size(); ++i) {
    //     cout << a1[i] << endl;
    // }

    cout << "Problem: 0001-two-sums" << endl;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}