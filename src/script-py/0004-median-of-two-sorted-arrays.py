# File Name: 0004-MEDIAN-OF-TWO-SORTED-ARRAYS.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  7 November 2021 
#  -*- coding: utf-8 -*-

from typing import List
class Solution:
    def findMedianSortedArrays(self,nums1: List[int],nums2: List[int]) -> float:
        l1,l2 = len(nums1),len(nums2)
        start,end = 0,l1
        mid_posi = (l1 + l2 + 1)//2
        inf = 2**40
        if l1 > l2:
            return self.findMedianSortedArrays(nums2,nums1)
        mid_posi:int = (l1 + l2 + 1)//2
        while start <= end: 
            mid:int = (start + end)//2
            left1size:int = mid
            left2size:int = mid_posi - mid
            # print(mid,left1size,left2size)
            left1ele = nums1[left1size - 1] if left1size > 0 else -inf
            left2ele = nums2[left2size - 1] if left2size > 0 else -inf
            right1ele = nums1[left1size] if left1size < l1 else inf
            right2ele = nums2[left2size] if left2size < l2 else inf
            if left1ele <= right2ele and left2ele <= right1ele:
               if (l1 + l2) % 2 == 0:
                   return (max(left1ele,left2ele) + min(right1ele,right2ele))/2.0
               else:
                   return max(left1ele,left2ele)
            elif left1ele > right2ele:
                end = mid - 1
            else:
                start = mid + 1
    
 



    
import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        n1 = [1,2,3]
        n2 = [3]
        # n2 = [4,5,6]
        sol = Solution()
        actual = sol.findMedianSortedArrays(n1,n2)
        # expect = 3.5
        expect = 2.5
        self.assertEqual(expect,actual)

        
if __name__ == "__main__":
    unittest.main() 