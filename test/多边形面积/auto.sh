#!/bin/bash

g++ std.cpp

for i in {1..10}; do
    python3 generate.py >./data/$i.in
    ./a.out <./data/$i.in >./data/$i.out
done

rm a.out