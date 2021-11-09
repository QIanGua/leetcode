#!/usr/local/bin/julia
# File Name: 0005-LONGEST-PARLINDROMIC-SUBSTRING.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved. 
# Created:  9 November 2021 

function longestParlindrome(s::String)::AbstractString
    d = length(s)
    if d == 0
        return ""
    end

    left,right,pl,pr = 1,1,1,1
    while left <= d
        while right + 1 <= d && s[left] == s[right + 1]
            right += 1
        end

        while left - 1 >= 1 && right + 1  <= d && s[left - 1] == s[right + 1] 
            left -= 1
            right += 1
        end

        if right - left > pr - pl
            pl,pr = left,right
        end

        left = div(left + right,2) + 1 # left must be a integer
        right = left

    end
    return s[pl:pr]
end


# test
using Test
@testset begin
    @test  longestParlindrome("babad") == "bab"
    @test  longestParlindrome("cbbd") == "bb"
    @test  longestParlindrome("a") == "a"
    @test  longestParlindrome("ac") == "a"
end
    
