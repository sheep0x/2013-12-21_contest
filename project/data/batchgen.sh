#! /usr/bin/env bash

set -eE

name=project

exec < conf
mkdir -p input output tmp
cp ../$name tmp
cd tmp


declare -i cnt=0
while read dup param; do
    while ((dup--)); do
        cnt=cnt+1
        ../gen.py $param > $name.in
        ./$name
        cp $name.in  ../input/$name$cnt.in
        cp $name.out ../output/$name$cnt.out
    done
done
