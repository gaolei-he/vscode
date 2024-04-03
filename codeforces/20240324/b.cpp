#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &x : a) {
        std::cin >> x;
    }
    for (auto &x : b) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mi = std::abs(a.front() - b[i]);
        for (int j = i; j - i < n; j++) {
            mi = std::min(std::abs(a[j - i] - b[j % n]), mi);
        }
        ans = std::max(ans, mi);
    }
    std::cout << ans << "\n";
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