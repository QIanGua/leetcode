#include "include/headers.h"

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


int main(int argc, char *argv[])
{
    vector<int> nums = {7,11,2,15};
    vector<int> a1,a2;
    // int i, target = 9;
    int i, target = 26;
    Solution1 test1;
    Solution2 test2;

    a1 = test1.twoSums(nums,target);
    a2 = test2.twoSums(nums,target);
    
    for (i = 0; i < a1.size(); ++i) {
        cout << a1[i] << endl;
    }

    for (i = 0; i < a2.size(); ++i) {
        cout << a2[i] << endl;
    }

    return 0;
}
