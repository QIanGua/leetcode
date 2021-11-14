# File Name: 0007-REVERSE.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 14 November 2021
#  -*- coding: utf-8 -*-

# import numpy # to use numpy.fmod for minus number

class Solution:
    def reverse(self,x: int) -> int:
        if x == 0:
            return 0
        tmp = 0
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1
        while x != 0:
            # if x > (pow(2,31) - 1)//10 or x < -(pow(2,31)//10):
            if tmp > INT_MAX//10 or tmp < -(abs(INT_MIN)//10):
                return 0
            else:
                # tmp = tmp * 10 + x % 10 # not applied to minus number
                # tmp = tmp * 10 + numpy.fmod(x,10)
                rem = x % 10 if x >=0 else -(abs(x) % 10)
                tmp = tmp * 10 + rem
                x = x//10 if x >= 0 else -(abs(x)//10)
        return tmp


import unittest
class TestLeetcode(unittest.TestCase):
    def test1(self):
        # n1 = 123
        n1 = -2147483412
        sol = Solution()
        actual = sol.reverse(n1)
        # expect = 321
        expect = -2143847412
        self.assertEqual(actual,expect)

    def test2(self):
        n1 = -123
        sol = Solution()
        actual = sol.reverse(n1)
        expect = -321
        self.assertEqual(actual,expect)

    def test3(self):
        n1 = 120
        sol = Solution()
        actual = sol.reverse(n1)
        expect = 21
        self.assertEqual(actual,expect)

    def test4(self):
        n1 = 0
        sol = Solution()
        actual = sol.reverse(n1)
        expect = 0
        self.assertEqual(actual,expect)

if __name__ == "__main__":
    unittest.main()