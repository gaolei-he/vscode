#!/bin/bash

g++ ./c2.cpp
g++ ./std.cpp -o std.out
while true; do
    python3 ./data1.py
    ./a.out <in1.txt >out1.txt
    ./std.out <in1.txt >out2.txt
    if diff out1.txt out2.txt; then
        echo "AC"
    else
        echo "WA"
        exit
    fi
done
