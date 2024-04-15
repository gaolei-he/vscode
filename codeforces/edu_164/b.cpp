#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n + 2);
    vec[0] = -1, vec[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> vec[i];
    }
    int mi = n + 1;
    std::vector<int> diff;
    for (int i = 0; i <= n + 1; i++) {
        if (vec[i] != vec[1]) {
            diff.emplace_back(i);
        }
    }
    for (int i = 0; i < diff.size() - 1; i++) {
        mi = std::min(mi, diff[i + 1] - diff[i] - 1);
    }
    if (mi >= n) {
        std::cout << -1 << "\n";
    } else {
        std::cout << mi << "\n";
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