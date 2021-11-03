// File Name: 0002-ADD-TWO-NUMBERS.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved. 
// Created:  2 November 2021 

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carry = 0;
        ListNode* cur = dummy;
        while (l1 || l2 || carry) {
            int s = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
            carry = s/10;
            cur -> next = new ListNode(s % 10);
            cur = cur -> next;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        return dummy -> next;
    }
};

struct ListBuilder {
    int v;
    ListNode* p;
    ListBuilder(ListNode* p = nullptr): p(p) {}
    ListBuilder(int d, ListBuilder b = ListBuilder())
        : p(new ListNode(d, b.p)) {}
    operator ListNode* () const {
        return p;
    }
};

TEST(TTT, TTT1) {
    ListNode* l1 = ListBuilder {2, {4, {3}}};
    ListNode* l2 = ListBuilder {5, {6, {4}}};
    Solution s;
    ListNode* sol= s.addTwoNumbers(l1,l2);
    ListNode* result = ListBuilder {7, {0, {8}}};
    // EXPECT_EQ(result, s.addTwoNumbers(l1,l2));
    while (result != NULL && sol) {
        EXPECT_EQ( result -> val, sol -> val);
        result = result -> next;
        sol = sol -> next;
    }
}



TEST(TTT, TTT2) {
    ListNode* l1 = ListBuilder {0};
    ListNode* l2 = ListBuilder {0};
    Solution s;
    ListNode* sol= s.addTwoNumbers(l1,l2);
    ListNode* result = ListBuilder {0};
    // EXPECT_EQ(result, s.addTwoNumbers(l1,l2));
    while (result != NULL && sol) {
        EXPECT_EQ( result -> val, sol -> val);
        result = result -> next;
        sol = sol -> next;
    }
}

TEST(TTT, TTT3) {
    ListNode* l1 = ListBuilder {9,{9,{9,{9,{9,{9,{9}}}}}}};
    ListNode* l2 = ListBuilder {9,{9,{9,{9}}}};
    Solution s;
    ListNode* sol= s.addTwoNumbers(l1,l2);
    ListNode* result = ListBuilder {8,{9,{9,{9,{0,{0,{0,{1}}}}}}}};
    // EXPECT_EQ(result, s.addTwoNumbers(l1,l2));
    while (result != NULL && sol) {
        EXPECT_EQ( result -> val, sol -> val);
        result = result -> next;
        sol = sol -> next;
    }
}

int main(int argc, char **argv){
    cout << "Problem: 0002-ADD-TWO-NUMBERS.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}