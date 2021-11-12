# File Name: 0002-ADD-TWO-NUMBERS.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 12 November 2021


# ---
# title: 2. Add Two Numbers
# id: problem2
# author: Tian Jun
# date: 2020-10-31
# difficulty: Medium
# categories: Linked List, Math
# link: <https://leetcode.com/problems/add-two-numbers/description/>
# hidden: true
# ---
#
# You are given two **non-empty** linked lists representing two non-negative
# integers. The digits are stored in **reverse order** , and each of their nodes
# contains a single digit. Add the two numbers and return the sum as a linked
# list.
#
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
#
#
#
# **Example 1:**
#
# ![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
#
#
#
#     Input: l1 = [2,4,3], l2 = [5,6,4]
#     Output: [7,0,8]
#     Explanation: 342 + 465 = 807.
#
#
# **Example 2:**
#
#
#
#     Input: l1 = [0], l2 = [0]
#     Output: [0]
#
#
# **Example 3:**
#
#
#
#     Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
#     Output: [8,9,9,9,0,0,0,1]
#
#
#
#
# **Constraints:**
#
#   * The number of nodes in each linked list is in the range `[1, 100]`.
#   * `0 <= Node.val <= 9`
#   * It is guaranteed that the list represents a number that does not have leading zeros.
#
#
#####
# ListNode
#####
using LinearAlgebra
Base.@kwdef mutable struct ListNode{V}
    val::V = 0
    next::Union{Nothing,ListNode{V}} = nothing
end

ListNode(x) = ListNode(x, nothing)

function ListNode{V}(x::Vector{V}) where {V}
    head = cur = ListNode(x[1])
    for i in 2:length(x)
        cur.next = ListNode(x[i])
        cur = cur.next
    end
    return head
end

val(x::ListNode) = x.val
val!(x::ListNode, y) = x.val = y
next(x::ListNode) = x.next
next!(x::ListNode, y) = x.next = y

Base.:(==)(x::ListNode, y::ListNode) = x.val == y.val && x.next == y.next

function add_two_numbers(l1::ListNode, l2::ListNode)::ListNode
        carry = 0
        fake_head = cur = ListNode()

        while !isnothing(l1) || !isnothing(l2) || !iszero(carry)
            v1, v2 = 0, 0

            if !isnothing(l1)
                v1 = val(l1)
                l1 = next(l1)
            end

            if !isnothing(l2)
                v2 = val(l2)
                l2 = next(l2)
            end

            carry, v = divrem(v1 + v2 + carry, 10)
            next!(cur, ListNode(v))
            cur = next(cur)
            val!(cur, v)
        end
        return next(fake_head)
end


using Test
@testset begin
    a1 = ListNode{Int}([2, 4, 3])
    b1 = ListNode{Int}([5, 6, 4])
    c1 = ListNode{Int}([7, 0, 8])

    a2 = ListNode{Int}([0])
    b2 = ListNode{Int}([0])
    c2 = ListNode{Int}([0])

    a3 = ListNode{Int}([9,9,9,9,9,9,9])
    b3 = ListNode{Int}([9,9,9,9])
    c3 = ListNode{Int}([8,9,9,9,0,0,0,1])

    @test c1 == add_two_numbers(a1, b1)
    @test c2 == add_two_numbers(a2, b2)
    @test c3 == add_two_numbers(a3, b3)
    # @test add_two_numbers(ListNode{Int}([0]), ListNode{Int}([0])) == ListNode{Int}([0])
    # @test add_two_numbers(ListNode{Int}([9, 9, 9, 9, 9, 9, 9]), ListNode{Int}([9, 9, 9, 9])) == ListNode{Int}([8, 9, 9, 9, 0, 0, 0, 1])
end