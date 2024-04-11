#!/bin/bash

read -p "input the directory: " directory
declare -A hash_files
calc_hash() {
    sha256sum $1 | awk '{print $1}'
}


# https://unix.stackexchange.com/questions/143958/in-bash-read-after-a-pipe-is-not-setting-values
# 通过管道find，其右侧命令会在子shell中运行，无法修改主脚本的变量
# IFS= 表示设定read的分隔符为空，以便读取文件名中的空格
# -r表示禁用反斜杠转义，以便读取文件的特殊字符
while IFS= read -r file; do
    hash_value=$(calc_hash $file)
    hash_files["$hash_value"]+="$file "
done < <(find "$directory" -type f)


for key in "${!hash_files[@]}"; do
    read -r -a value <<< "${hash_files[$key]}"
    length=${#value[@]}
    for ((i=1;i<length;i++)); do
        echo "Removing ${value[$i]}"
        rm "${value[$i]}"
    done
done
