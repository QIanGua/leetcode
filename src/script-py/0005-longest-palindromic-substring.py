# File Name: 0005-LONGEST-PALINDROMIC-SUBSTRING.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  8 November 2021 
#  -*- coding: utf-8 -*-

class Solution:
    def longestParlindrome(self, s:str) -> str:
        d = len(s)
        if d == 0:
            return ""
        left,right,pl,pr = 0,0,0,0
        while right < d:
            while right + 1 < d and s[left] == s[right + 1]:
                right += 1
                print("1: ",right)

            while left - 1 >= 0 and right + 1 < d and s[left - 1] == s[right + 1]:
                left -= 1
                right += 1

            if right - left > pr - pl:
               pl,pr = left,right

            left = int( (left + right)/2 + 1 )
            right = left

        return s[pl:(pr+1)]
                
    
import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        s1 = "babad"
        expect = "bab"
        sol = Solution()
        actual = sol.longestParlindrome(s1)
        self.assertEqual(expect,actual)

        
if __name__ == "__main__":
    unittest.main() 