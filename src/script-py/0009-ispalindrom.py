# File Name: 0009-ISPALINDROM.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 23 November 2021
#  -*- coding: utf-8 -*-

class Solution:
    def ispalindrome(self,num : int) -> bool:
        if num < 0 or (num % 10 == 0 and num != 0):
            return False
        revertedNum = 0
        while num > revertedNum:
            revertedNum = revertedNum * 10 + revertedNum % 10
            num = num / 10

        return num == revertedNum or num == revertedNum/10



import unittest
class TestLeetcode(unittest.TestCase):
    def test1(self):
        num = 121
        sol = Solution()
        expect = True
        actual = sol.ispalindrome(num)
        print(actual)
        self.assertEqual(expect,actual)


if __name__ == "__main__":
    unittest.main()