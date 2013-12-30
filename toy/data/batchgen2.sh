#! /usr/bin/env bash

set -eE
#set -x

name=toy

exec < conf
mkdir -p input output tmp
cp ../$name tmp
cp ../toy_safe tmp
cd tmp


declare -i cnt=0
while read dup param; do
    while ((dup--)); do
        cnt=cnt+1
        until
          echo trying "$cnt"
          ../gen3M.rb $param > $name.in
          ./toy_safe
        do :; done
        ../gen3Q.rb $param $(< toy.info) < $name.in > $name._in

        # debug
        tail -n +2 $name.in | head -n $(< toy.info) > $name.merges
        #grep M $name._in | diff - $name.merges
        grep M $name._in > $name.grep
        diff $name.grep $name.merges

        mv $name._in $name.in
        ./toy_safe
        cp $name.in  ../input/$name$cnt.in
        cp $name.out ../output/$name$cnt.out
    done
done
