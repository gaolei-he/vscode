#include <iostream>

int main() {
    // 使用 new 分配一个整数数组
    int* arr = new int[5];

    // 获取数组元素的个数（通常存储在数组的前几个字节中）
    std::size_t size = *reinterpret_cast<std::size_t*>(arr - 1);

    std::cout << "Array size: " << size << std::endl;

    // 使用 delete 释放内存
    delete[] arr;

    return 0;
}