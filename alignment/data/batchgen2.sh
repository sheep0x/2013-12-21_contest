#! /usr/bin/env bash

set -eE

exec < conf2
mkdir -p input output tmp
cp ../alignment tmp
cd tmp


declare -i cnt=0
while read dup param; do
    while ((dup--)); do
        cnt=cnt+1
        ../gen2_fix.py $param > alignment.in
        ./alignment
        cp alignment.in  ../input/alignment$cnt.in
        cp alignment.out ../output/alignment$cnt.out
    done
done
