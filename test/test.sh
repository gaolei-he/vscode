#!/bin/bash

# clear executable files when Ctrl+C
trap "rm *.out; exit " SIGINT

# get source code and data generator
read -p "std source code: " src
read -p "your source code: " your
read -p "data generator: " data
g++ $src -o std.out
g++ $your -o your.out

counter=0
function output() {
    ((counter++))
    echo "Test case: $counter"
    cat input.txt
    printf "\n============\n"
    echo "Standard output:"
    cat std.txt
    printf "\n============\n"
    echo "Your output:"
    cat your.txt
    printf "\n============\n"
}

function check() {
    sleep 0.2
    if diff std.txt your.txt >/dev/null; then
        echo "AC"
        clear
    else
        echo "WA"
        exit
    fi
}
function run() {
    ./std.out <input.txt >std.txt
    ./your.out <input.txt >your.txt
}
function generate() {
    if [[ $data == *.py ]]; then
        python3 $data >input.txt
    elif [[ $data == *.cpp ]]; then
        g++ $data -o data.out
        ./data.out >input.txt
    fi
}
while true; do
    generate
    run
    output
    check
done

rm *.out
