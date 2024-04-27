#!/bin/bash

g++ std.cpp
mkdir data
read n
for ((i=1; i<=n; i++)); do
    python3 data.py >data/$i.in
    ./a.out <data/$i.in >data/$i.out
    # python3 std.py <data/$i.in >data/$i.ans
    # if diff data/$i.out data/$i.ans; then
    #     echo "Test $i: AC"
    # else
    #     echo "Test $i: WA"
    #     break
    # fi
    # rm data/$i.ans
done
rm a.out