// https://www.cnblogs.com/onlyblues/p/18017370
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 mod = 998'244'353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(3));
    std::function<void(int)> dfs = [&](int ver) {
        dp[ver][0] = dp[ver][1] = 1;
        for (auto x : g[ver]) {
            if (!dp[x][0]) {
                dfs(x);
                dp[ver][1] = dp[ver][1] * (dp[x][1] + 1) % mod;
                dp[ver][2] = (dp[ver][2] + dp[x][1]) % mod;
                dp[ver][2] = (dp[ver][2] + dp[x][2]) % mod;
            }
        }
    };
    dfs(0);
    std::cout << (dp[0][0] + dp[0][1] + dp[0][2]) % mod << "\n";
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