# File Name: 0003-LONGEST-SUBSTRING-WITHOUT-REPEATED-CHARACTERS.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  4 November 2021 
#  -*- coding: utf-8 -*-

class Solution:
    def lengthOfLongestSubstring(self, string: str) -> int:
        dic = {}
        for index,val in enumerate(string):
            if val not in dic:
                dic[val] = index
        return len(dic)

import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        s1 = "abcdee"
        sol = Solution()
        expect = 5
        actual = sol.lengthOfLongestSubstring(s1)
        self.assertEqual(expect,actual)
        
        
if __name__ == "__main__":
    unittest.main() 