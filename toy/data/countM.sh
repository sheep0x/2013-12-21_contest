#! /usr/bin/env bash

set -eE
#set -x

cd input

for i in {1..20}; do
    grep M toy$i.in | wc -l
done
