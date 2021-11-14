# File Name: 0007-REVERSE.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 14 November 2021


function reverse(x::Int32)::Int32
    if x==0
        return 0
    end
    tmp::Int32 = 0
    while x != 0
        if tmp > div(typemax(Int32),10) || tmp < div(typemin(Int32),10)
            return 0
        else
            tmp = tmp * 10 + rem(x,10)
            x = div(x,10)
        end
    end
    return tmp
end

using Test
@testset begin
    @test reverse(Int32(123)) == Int32(321)
    @test reverse(Int32(-123)) == Int32(-321)
    @test reverse(Int32(120)) == Int32(21)
    @test reverse(Int32(0)) == Int32(0)
    @test reverse(Int32(-2147483412)) == Int32(-2143847412)
end