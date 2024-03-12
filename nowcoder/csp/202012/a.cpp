#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int sm = 0;
    while(n --) {
        int a, b;
        std::cin >> a >> b;
        sm += a * b;
    }
    std::cout << std::max(sm, 0) << "\n";

    return 0;
}