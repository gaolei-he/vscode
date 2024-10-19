#include <iostream>

int main() {

    int n;
    std::cin >> n;
    int sm = 0;
    for(int i=0;i<n;i++) {
        int tmp;
        std::cin >> tmp;
        sm += tmp;
    }

    std::cout << sm;
    return 0;
}