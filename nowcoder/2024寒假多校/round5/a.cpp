#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec;
    while(n --) {
        int x;
        std::cin >> x;
        if(x != 1) {
            vec.push_back(x);
        }
    }
    std::cout << vec.size() << std::endl;
    return 0;
}