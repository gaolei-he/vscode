#include <bits/stdc++.h>
#define int long long

using i64 = long long;

constexpr int mod = 998'244'353;

int quick_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::map<int, int> mp;
    dp[1] = a[1];
    int evens = 0, odds = 0;
    if (a[1] & 1) {
        odds = 1;
    } else {
        evens = 1;
    }
    // mp[a[1]] += 1;
    for (int i = 2; i <= n; i++) {
        std::vector<std::pair<int, int>> vec;
        for (int j = 1; j < i; j++) {
            if (a[i] + a[j] <= 5'000) {
                vec.emplace_back(a[i] + a[j], 1);
            }
        }
        for (auto [k, v] : mp) {
            if (k + a[i] <= 5'000) {
                vec.emplace_back(k + a[i], v);
            }
        }
        if (a[i] & 1) {
            odds = (odds + evens + 1) % mod;
            evens = (odds + evens) % mod;
        } else {
            odds = odds * 2 % mod;
            evens = (evens * 2 + 1) % mod;
        }
        for (auto [x, y] : vec) {
            mp[x] = (mp[x] + y) % mod;
        }

        dp[i] = dp[i - 1] * 2 % mod;
        dp[i] = (dp[i] + (quick_pow(2, i - 1)) * (a[i] / 2) % mod) % mod;
        if (a[i] & 1) {
            dp[i] = (dp[i] + evens) % mod;
        }
        for (auto [k, v] : mp) {
            if (k >= a[i]) {
                break;
            }
            dp[i] = (dp[i] + (a[i] - (a[i] + k + 1) / 2)) % mod;
        }
        for (int j = 1; j < i; j++) {
            dp[i] =
                (dp[i] + (std::max(a[i], a[j]) - (a[i] + a[j] + 1) / 2)) % mod;
        }
        dp[i] = (dp[i] + a[i] - (a[i] + 1) / 2) % mod;
    }
    for (int i = 1; i <= n; i++) std::cerr << dp[i] << " ";
    // std::cout << dp[n] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}