#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dp(n + 2), record(n + 2, n + 2);
    auto cnt = dp;

    while (m--) {
        int l, r;
        std::cin >> l >> r;
        record[r] = std::min(record[r], l);
        cnt[l] += 1, cnt[r + 1] -= 1;
    }
    for (int i = n - 1; i; i--) {
        record[i] = std::min(record[i], record[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i] = std::max(dp[i], cnt[i] + dp[std::max(0, record[i] - 1)]);
    }
    std::cout << dp[n] << "\n";
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