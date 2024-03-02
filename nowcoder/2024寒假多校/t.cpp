#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec(4, 2);
    vec.assign(3, 1);
    for(auto x : vec) std::cout << x << ' ';

    return 0;
}