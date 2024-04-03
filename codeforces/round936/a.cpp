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
    int idx = (n + 1) / 2;
    int ans = 1;
    for (int i = idx; i < n; i++) {
        if (vec[i] == vec[i - 1]) {
            ans += 1;
        } else {
            break;
        }
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