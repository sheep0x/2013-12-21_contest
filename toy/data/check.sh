#! /usr/bin/env bash

set -eE
#set -x

name=toy

mkdir -p input output tmp
gcc -o tmp/toy_safe toy_safe.c -O2 -Wall
cd tmp


for cnt in {1..20}; do
    cp ../input/$name$cnt.in   $name.in
    cp ../output/$name$cnt.out $name.out
    time ./toy_safe
    wc -l toy.in
    cat toy.info
    echo
done
