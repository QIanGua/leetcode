// File Name: 01-CQUEUE.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 26 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class CQueue {
private:  stack<int> stack1,stack2;

public:
    CQueue() {
        // clear up then get two empty stack
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

    }

    int deleteHead() {
        // assign stack2 as the reverse of stack1 and clear up stack1
        // if (stack2.empty()) {
        //     while (!stack1.empty()) {
        //         stack2.push(stack1.top());
        //         stack1.pop();
        //     }
        // }

        // // return out
        // if (stack2.empty()) {
        //     return -1;
        // }
        // else {
        //     int deleteItem = stack2.top();
        //     stack2.pop();
        //     return deleteItem;
        // }

        // if (stack1.empty() && stack2.empty()) {
        //     return -1;
        // }
        // else {
        //     if (stack2.empty()) {
        //         while (!stack1.empty()) {
        //             stack2.push(stack1.top());
        //             stack1.pop();
        //         }
        //     }
        //     int item = stack2.top();
        //     stack2.pop();
        //     return item;
        // }

        int num;
        if (!stack2.empty()) {
            num = stack2.top();
            stack2.pop();
            return num;
        }
        else if (!stack1.empty()) {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            num = stack2.top();
            stack2.pop();
            return num;
        }
        else {
            return -1;
        }
    }

};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
TEST(TTT, TTT) {
    CQueue* obj = new CQueue();
    // EXPECT_TRUE(obj != nullptr);
    // obj->appendTail(3);
    if (obj == nullptr) {
        cout << "obj is null" << endl;
    }
    obj->appendTail(3);
    EXPECT_EQ(obj->deleteHead(),3);
    EXPECT_EQ(obj->deleteHead(),-1);
}


int main(int argc, char **argv) {
    cout << "Problem: 01-CQUEUE.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}