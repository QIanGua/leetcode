from typing import List
class Solution:
    def twoSums(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for index, num in enumerate(nums):
            pair = target - num
            if pair in dic:
                return [dic[pair], index]
            else:
                dic[num] = index


import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        nums = [2, 7, 11, 15]
        target = 9
        expect = [0, 1]
        sol = Solution()
        acutal = sol.twoSums(nums,target)
        self.assertEqual(acutal,expect)

    def test2(self):
        nums = [3,2,4]
        target = 6
        expect = [1, 2]
        sol = Solution()
        acutal = sol.twoSums(nums,target)
        self.assertEqual(acutal,expect)

    def test3(self):
        nums = [3,3]
        target = 6
        expect = [0, 1]
        sol = Solution()
        acutal = sol.twoSums(nums,target)
        self.assertEqual(acutal,expect)

if __name__ == "__main__":
    unittest.main() 