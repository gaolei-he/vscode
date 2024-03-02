#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec1(n), vec2(n);
    for (auto &x : vec1) {
        std::cin >> x;
    }
    for (auto &x : vec2) {
        std::cin >> x;
    }

    for (int i = 1; i < n - 1; i++) {
        if (vec1[i] == vec2[i + 1] or vec1[i] == vec2[i] or
            vec1[i] == vec2[i - 1]) {
            std::cout << 1 << std::endl;
            return;
        }
    }

    if (n > 1 and vec1[0] == vec2[1] or vec1[n - 1] == vec2[n - 2]) {
        std::cout << 1 << std::endl;
    } else if (n > 2) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}