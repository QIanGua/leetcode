# File Name: 0003-LONGEST-SUBSTRING-WITHOUT-REPEATED-CHARACTERS.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  4 November 2021 
#  -*- coding: utf-8 -*-
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_idx = {}
        max_len = 0
        d = len(s)
        start_idx = 0
        # range(0,d): loop in (0,1,2,d-1)
        for i in range(0,d):
            if s[i] in last_idx:
                start_idx = max(start_idx, last_idx[s[i]] + 1)
            max_len = max(max_len, i - start_idx + 1)
            last_idx[s[i]] = i
        return max_len

    
import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        # s1 = "abba"
        s1 = " "
        sol = Solution()
        # expect = 2
        expect = 1
        actual = sol.lengthOfLongestSubstring(s1)
        self.assertEqual(expect,actual)
        
        
if __name__ == "__main__":
    unittest.main() 