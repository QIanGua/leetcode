# File Name: 01-TWO-STACKS-AS-QUEUE.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 26 November 2021
#  -*- coding: utf-8 -*-

class CQueue:
    def __init__(self):
        self.stackIn = []
        self.stackOut = []

    def appendTail(self, value: int) -> None:
        self.stackIn.append(value)

    def deleteHead(self) -> int:
        if self.stackOut:
           return self.stackOut.pop()
        elif self.stackIn:
            while self.stackIn:
                self.stackOut.append(self.stackIn.pop())
            return self.stackOut.pop()
        else:
            return -1


import unittest
class TestLeetcode(unittest.TestCase):
    def test1(self):
        obj = CQueue()
        obj.appendTail(3)
        self.assertEqual(obj.deleteHead(),3)
        self.assertEqual(obj.deleteHead(),-1)

if __name__ == "__main__":
    unittest.main()