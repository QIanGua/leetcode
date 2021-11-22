# File Name: 0009-ISPALINDROM.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 22 November 2021


function ispalindrome(num::Integer)::Bool
    if num < 0 || (div(num,10) == 0 && num != 0)
        return false
    end

    revertedNum = 0;
    while num > revertedNum
        revertedNum = revertedNum *10 + mod(num,10)
        num = div(num,10)
    end

    return num == revertedNum || num == div(revertedNum,10)

end

using Test
@testset begin
    @test ispalindrome(121) == 1
    @test ispalindrome(-121) == 0
end