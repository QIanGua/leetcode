#!/usr/local/bin/zsh

## define path variables
src="$(git root)/src/script-cxx"
build="$(git root)/build"
# echo "${build}"

## if $(build) doesn't exist, generate it.
if [ ! -d "${build}" ]; then
    echo "${build}doesn't exist, generate it"
    mkdir -p ${build}
fi

cd ${build}
cmake ${src} -D PROBLEM_NUMBER=$1
make
make run
# ./leetcode