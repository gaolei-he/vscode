#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;
    if(!a and !b) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 0 << "\n";
    }

    return 0;
}