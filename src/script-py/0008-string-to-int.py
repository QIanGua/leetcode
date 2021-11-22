# File Name: 0008-STRING-TO-INT.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 20 November 2021
#  -*- coding: utf-8 -*-

class Solution:
    def myAtoi(self, s: str) ->int:
        return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)


import unittest
class TestLeetcode(unittest.TestCase):
    def test1(self):
        s1 = "+20210815abcd"
        sol = Solution()
        actual = sol.myAtoi(s1)
        expect = 20210815
        self.assertEqual(actual,expect)


if __name__ == "__main__":
    unittest.main()