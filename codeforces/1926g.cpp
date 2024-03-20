#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    std::vector<bool> vis(n);
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        x -= 1;
        g[i].emplace_back(x);
        g[x].emplace_back(i);
    }
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> dp(n, std::vector<int>(4, n));
    std::function<void(int)> dfs = [&](int ver) {
        vis[ver] = true;
        std::vector<int> vec;
        for (auto x : g[ver]) {
            if (!vis[x]) {
                dfs(x);
                vec.emplace_back(x);
            }
        }

        int val = 0;
        if (s[ver] == 'P') {
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0] + 1, dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3]));
            }
            dp[ver][3] = val;
        } else if (s[ver] == 'S') {
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0], dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3] + 1));
            }
            dp[ver][0] = val;
        } else if (s[ver] == 'C') {
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0], dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3] + 1));
            }
            dp[ver][0] = val;
            val = 0;
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0] + 1, dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3] + 1));
            }
            dp[ver][1] = val;
            val = 0;
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0] + 1, dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3]));
            }
            dp[ver][2] = val;
            val = 0;
            for (auto x : vec) {
                val += std::min(std::min(dp[x][0] + 1, dp[x][1]),
                                std::min(dp[x][2] + 1, dp[x][3]));
            }
            dp[ver][3] = val;
        }
    };
    dfs(0);
    // for(int i=0;i<4;i++)std::cerr << dp[0][i] << " ";
    if (s[0] == 'P') {
        std::cout << std::min(dp[0][2], dp[0][3]) << "\n";
    } else if (s[0] == 'S') {
        std::cout << std::min(dp[0][1], dp[0][0]) << "\n";
    } else {
        std::cout << std::min(std::min(dp[0][1], dp[0][0]), std::min(dp[0][2], dp[0][3])) << "\n";
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