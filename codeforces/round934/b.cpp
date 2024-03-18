#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> vec(n);
    for (int i = 0; i < n * 2; i++) {
        int x;
        std::cin >> x;
        x -= 1;
        if (vec[x].first) {
            vec[x].second = i + 1;
        } else {
            vec[x].first = i + 1;
        }
    }
    std::vector<int> v1, v2, v3, v4;
    for (int i = 0; i < n; i++) {
        if (vec[i].second <= n) {
            v1.emplace_back(i + 1);
        } else if (vec[i].first > n) {
            v3.emplace_back(i + 1);
        } else {
            v2.emplace_back(i + 1);
            v4.emplace_back(i + 1);
        }
    }
    int val1 = std::min(v1.size(), v3.size());
    val1 = std::min(val1, k);
    int val2 = 2 * k - val1 * 2;
    for (int i = 0; i < val1; i++) {
        std::cout << v1[i] << " " << v1[i] << " ";
    }
    for (int i = 0; i < val2; i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < val1; i++) {
        std::cout << v3[i] << " " << v3[i] << " ";
    }
    for (int i = 0; i < val2; i++) {
        std::cout << v4[i] << " ";
    }
    std::cout << "\n";
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