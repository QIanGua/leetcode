# File Name: 0006-ZIGZAG-CONVERSION.JL
# Author: Qiangua
# Email: caicailiushui@protonmail.com
# Copyright © 2021, Qiangua, all rights reserved.
# Created: 10 November 2021


function zigconvert(s::String,numRows::Integer)::String
    if numRows == 1
        return s;
    end

    d = length(s)
    step = 2*numRows - 2
    ret = string()
    for i in 1:numRows
        idx = i
        add = 2*(i-1)
        while idx <= d
            ret *= s[idx]
            add = step - add
            idx += (i == 1 || i == numRows ? step : add)
        end
    end
    return ret
end

using Test
@testset begin
    @test  zigconvert("PAYPALISHIRING",3) == "PAHNAPLSIIGYIR"
    @test  zigconvert("PAYPALISHIRING",4) == "PINALSIGYAHRPI"
    @test  zigconvert("A",1) == "A"
end
