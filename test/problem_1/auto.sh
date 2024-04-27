#!/bin/bash

# test

read n
g++ std.cpp
for ((i=0; i<n; i++)); do
    python3 data.py >in.txt
    ./a.out <in.txt >cpp.out
    python3 std.py <in.txt >py.out
    if diff cpp.out py.out; then
        echo "Test $i: Passed"
    else
        echo "Test $i: Failed!!!"
        break
    fi
done
rm a.out

if false; then
# generate data
read n
mkdir data
for ((i=1; i<=n; i++)); do
    python3 data.py >data/$i.in
    python3 std.py <data/$i.in >data/$i.out
done
fi