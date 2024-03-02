#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i128> vec(n);
    std::vector<int> sm(n);
    for (auto &x : vec) {
        i64 tmp;
        std::cin >> tmp;
        x = tmp;
    }

    if (n == 1) {
        std::cout << "YES\n";
        return;
    }

    if (n & 1) {
        for (int i = 0; i < n - 2; i++) {
            if (vec[i] > vec[i + 1]) {
                i128 tmp = vec[i] - vec[i + 1];
                vec[i + 1] += (i + 2) * tmp;
            }
        }
        if (vec.back() >= vec[n - 2]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        std::cout << "YES\n";
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