#!/bin/bash
trap "exit" SIGINT
n=1
g++ std.cpp -o std.out
g++ d.cpp -o d.out
while true; do
    echo "Running test $n"
    n=$((n + 1))
    python3 data.py >data.in
    ./std.out <data.in >std.txt
    ./d.out <data.in >d.txt
    if diff std.txt d.txt; then
        echo "AC"
    else
        echo "WA"
        exit 0
    fi
done
