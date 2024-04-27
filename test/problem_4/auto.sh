#!/bin/bash

g++ std.cpp
read n
mkdir data
for ((i=1; i<=n; i++)); do
    python3 data.py >data/$i.in
    ./a.out <data/$i.in >data/$i.out
done