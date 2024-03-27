#!/bin/bash
n=1
while [ $n -le 10 ]; do
    python3 data.py >$n.in
    if [ $? != 0 ]; then
        continue
    fi

    python3 std.py <$n.in >$n.out
    n=$((n+1))
done