#!/bin/bash
trap "exit" SIGINT
g++ c.cpp -o my.out
g++ std.cpp -o std.out
while true; do
    python3 ./auto.py >data.in
    ./my.out <data.in >my.txt
    ./std.out <data.in >std.txt
    if diff my.txt std.txt; then
        echo "AC"
    else
        echo "WA"
        exit 0
    fi
done
