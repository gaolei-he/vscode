#!/bin/bash
g++ std.cpp -o std.out
n=1
while [ $n -le 21 ]; do
    ./std.out <$n.in >$n.out
    n=$((n+1))
done
rm std.out