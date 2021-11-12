# File Name: 0001-TWO-SUMS.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 12 November 2021


function twoSums(nums::Tuple,target::Integer)::Tuple
    dic = Dict{Integer,Integer}()
    for (index,value) in enumerate(nums)
        pair = target - value
        if haskey(dic,pair)
            return(dic[pair],index)
        else
            dic[value] = index
        end
    end
end


using Test
@testset begin
    @test twoSums((2,7,11,15),9) == (1,2)
    @test twoSums((3,2,4),6) == (2,3)
    @test twoSums((3,3),6) == (1,2)
end
