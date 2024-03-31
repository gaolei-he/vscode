#!/bin/bash

n=1
while [ $n -le 10 ]; do
    python3 std.py < $n.in > $n.out
    ./a.out < $n.in > $n.ans
    if diff $n.out $n.ans >/dev/null; then
        echo "Test case $n passed"
    else
        echo "Test case $n failed"
    fi
    n=$((n+1))
done