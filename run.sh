#!/usr/local/bin/zsh

cd ./build/

cmake ../src -D PROBLEM_NUMBER=$1

make

./leetcode