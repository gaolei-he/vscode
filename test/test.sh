#!/bin/bash

# 声明一个关联数组
declare -A my_array
my_array["key1"]="value1"
my_array["key2"]="value2"
my_array["key3"]="value3"

# 修改关联数组的值
my_array["key1"]="new_value1"
my_array["key2"]="new_value2"
my_array["key3"]="new_value3"

# 输出修改后的关联数组
for key in "${!my_array[@]}"; do
    echo "$key: ${my_array[$key]}"
done
