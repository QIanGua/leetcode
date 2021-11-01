#!/usr/local/bin/zsh
# author: Qiangua

cd ./build/

cmake ../src -D PROBLEM_NUMBER=$1

make

./leetcode