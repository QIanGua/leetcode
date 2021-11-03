# File Name: 0002-ADD-TWO-NUMBERS.PY
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  3 November 2021 

from headers import ListNode
from itertools import zip_longest

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        carry, cur = 0, dummy
        while l1 or l2 or carry:
            s = (0 if not l1 else l1.val) + (0 if not l2 else l2.val) + carry
            carry, val = divmod(s, 10)
            cur.next = ListNode(val)
            cur = cur.next
            l1 = None if not l1 else l1.next
            l2 = None if not l2 else l2.next
        return dummy.next

import unittest                
class TestLeetcode(unittest.TestCase):
    def test1(self):
        l1 = ListNode.make_linked_list([2,4,3])
        l2 = ListNode.make_linked_list([5,6,4])
        expect = ListNode.make_linked_list([7, 0, 8])
        sol = Solution()
        actual = sol.addTwoNumbers(l1,l2)
        for x,y in zip_longest(expect,actual):
            self.assertEqual(x,y)

if __name__ == "__main__":
    unittest.main() 