#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
    std::sort(vec.begin(), vec.end());
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::min(vec[i], vec.front() * 2) * 2ll * ((n - i - 1));
    }
    std::cout << ans * 2 << "\n";
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