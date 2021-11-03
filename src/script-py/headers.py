# Hearders file for leetcode 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from collections import deque
from itertools import zip_longest, islice

class ListNode:
    def __init__(self, x=None):
        self.val = x
        self.next = None
        self.has_cycle = False

    def __iter__(self):
        p = self
        while p is not None:
            yield p.val
            p = p.next

    def __str__(self):
        if self.has_cycle:
            return "->".join([str(v) for v in islice(self, 5)]) + '...'
        else:
            return "->".join([str(v) for v in self])

    def __eq__(self, other):
        if self.has_cycle:
            raise TypeError('__eq__ is not supported for linked list who has cycle')
        if not isinstance(other, self.__class__):
            return False
        return all(x == y for x, y in zip_longest(self, other, fillvalue=None))

    @staticmethod
    def make_linked_list(data):
        """make a linked list from a list
        Examples:
        >>> ll = ListNode.make_linked_list([1, 2, 3, 4, 5])
        >>> print(ll)
        1->2->3->4->5
        Args:
            data: data source, an iterable object.
        Returns:
            the head of the linked list, class `LinkedLinkedListNode`.
        """
        data = list(data)
        if len(data) == 0:
            return None
        head = tail = ListNode(data[0])
        for item in data[1:]:
            node = ListNode(item)
            tail.next = node
            tail = node
        return head

    @staticmethod
    def make_cycle_list(data, n):
        """make a linked list (has a cycle) from a list
        Examples:
        >>> cl = ListNode.make_cycle_list([1, 2, 3], 0)
        >>> cl.next.val
        2
        >>> cl.next.next.next.val
        1
        Args:
            data: data source, an iterable object.
            n: link the tail to the nth node. if n < 0 or n > len(data),
               the returned linked list has no cycle.
        Returns:
            the head of the linked list, class `LinkedLinkedListNode`.
        """
        head = ListNode.make_linked_list(data)
        if head is None:
            return None

        if n < 0:
            return head

        # find the tail
        tail = head
        while tail.next:
            tail.has_cycle = True
            tail = tail.next
        tail.has_cycle = True
        # find nth node
        target, cnt = head, 0
        while target:
            if cnt == n:
                break
            cnt += 1
            target = target.next

        # link them
        tail.next = target
        return head

