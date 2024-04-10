#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998'244'353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(4));
    std::vector<std::vector<int>> tmp(n, std::vector<int>(6));

    if (vec[0] % 2 == 0 and vec[1] % 2 == 0) {
        tmp[1][4] = 2;
        tmp[1][0] = 1;
    } else if (vec[0] % 2 == 0 and vec[1] % 2 == 1) {
        tmp[1][4] = tmp[1][5] = 1;
        tmp[1][1] = 1;
    } else if (vec[0] % 2 == 1 and vec[1] % 2 == 0) {
        tmp[1][5] = tmp[1][4] = 1;
        tmp[1][2] = 1;
    } else if (vec[0] % 2 == 1 and vec[1] % 2 == 1) {
        tmp[1][5] = 2;
        tmp[1][3] = 1;
    }
    for (int i = 2; i < n; i++) {
        // std::cerr << i << ' ' << tmp[i][1] << std::endl;
        for (int j = 0; j < 6; j++) {
            if (j < 4) {
                dp[i][j] = dp[i - 1][j];
            }
            tmp[i][j] = tmp[i - 1][j];
        }
        if (vec[i] & 1) {
            dp[i][1] += (dp[i - 1][2] + tmp[i - 1][2]) % mod;
            dp[i][3] += (dp[i - 1][1] + tmp[i - 1][1]) % mod;
            tmp[i][1] += tmp[i - 1][4];
            tmp[i][3] += tmp[i - 1][5];
            tmp[i][5] += 1;
        } else {
            dp[i][0] += (dp[i - 1][0] + tmp[i - 1][0]) % mod;
            dp[i][2] += (dp[i - 1][3] + tmp[i - 1][3]) % mod;
            tmp[i][0] += tmp[i - 1][4];
            tmp[i][2] += tmp[i - 1][5];
            tmp[i][4] += 1;
        }
        for (int j = 0; j < 6; j++) {
            if (j < 4) {
                dp[i][j] %= mod;
            }
            tmp[i][j] %= mod;
        }
    }
    int ans = 0;
    for (int j = 0; j < 4; j++) {
        ans += dp[n - 1][j];
        ans %= mod;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}