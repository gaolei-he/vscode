#include <iostream>

int main() {
    unsigned long long val = 1e9;
    for(int i=1;i<=10;i++) {
    val += 1000000000;
    std::cout << val << std::endl;
    }
    return 0;
}