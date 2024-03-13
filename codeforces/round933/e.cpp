#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k, d;
    std::cin >> n >> m >> k >> d;
    std::vector<std::vector<int>> vec(n, std::vector<int>(m));
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(m));
    for (auto &v : vec) {
        for (auto &x : v) {
            std::cin >> x;
        }
    }
    std::vector<i64> ans{0};
    for (int i = 0; i < n; i++) {
        std::map<i64, int> mp;
        mp[1] = 1;
        dp[i][0] = 1;
        for (int j = 1; j < m; j++) {
            dp[i][j] = mp.begin()->first + vec[i][j] + 1;
            if (j - d - 1 >= 0) {
                mp[dp[i][j - d - 1]] -= 1;
                if (mp[dp[i][j - d - 1]] == 0) {
                    mp.erase(dp[i][j - d - 1]);
                }
            }
            mp[dp[i][j]] += 1;
        }
        ans.push_back(dp[i].back());
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
    }
    i64 res = 1'000'000'000'000'000;
    for (int i = 1; i <= n - k + 1; i++) {
        res = std::min(res, ans[i + k - 1] - ans[i - 1]);
    }
    std::cout << res << "\n";
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