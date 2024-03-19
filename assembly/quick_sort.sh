#!/bin/bash
read n
read -a arr
function quick_sort {
    if [ $1 -ge $2 ]; then
        return
    fi
    local i=$(($1 - 1))
    local j=$(($2 + 1))
    local x=${arr[($1 + $2) / 2]}
    while [ $i -lt $j ]; do
        while [ ${arr[++i]} -lt $x ]; do :; done
        while [ ${arr[--j]} -gt $x ]; do :; done
        if [ $i -lt $j ]; then
            local t=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=$t
        fi
    done
    quick_sort $1 $j
    quick_sort $(($j + 1)) $2
}

quick_sort 0 $(($n - 1))
echo ${arr[@]}
