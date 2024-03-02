#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, k;
    std::cin >> a >> b >> k;

    if (a >= b * k) {
        std::cout << "good\n";
    } else {
        std::cout << "bad\n";
    }

    return 0;
}