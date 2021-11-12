# File Name: 0006-ZIGZAG-CONVERT.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 12 November 2021
#  -*- coding: utf-8 -*-

class Solution:
    def convert(self,s:str,numRows:int) -> str:
        if numRows == 1:
            return s
        step = 2*numRows - 2
        d = len(s)
        ret = str()
        for i in range(0,numRows):
            idx = i
            add = 2*i
            while idx < d:
                ret += s[idx]
                add = step - add
                idx += step if i == 0 or i == numRows - 1  else add

        return ret


import unittest
class TestLeetcode(unittest.TestCase):
    def test1(self):
        s1 = "PAYPALISHIRING"
        numRows = 3
        expect = "PAHNAPLSIIGYIR"
        sol = Solution()
        actual = sol.convert(s1,numRows)
        self.assertEqual(expect,actual)

    def test2(self):
        s1 = "PAYPALISHIRING"
        numRows = 4
        expect = "PINALSIGYAHRPI"
        sol = Solution()
        actual = sol.convert(s1,numRows)
        self.assertEqual(expect,actual)

    def test3(self):
        s1 = "A"
        numRows = 1
        expect = "A"
        sol = Solution()
        actual = sol.convert(s1,numRows)
        self.assertEqual(expect,actual)


if __name__ == "__main__":
    unittest.main()