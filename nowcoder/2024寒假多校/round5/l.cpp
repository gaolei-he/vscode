#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    if ((n - x) & 1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << (n - x) / 2 + x << ' ' << (n - x) / 2 << std::endl;
    }
    return 0;
}