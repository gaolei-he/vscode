#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
void f() {
    for(int i=0;i<10;i++) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
int main() {
    std::vector<int> vec;
    std::lower_bound()
    return 0;
}