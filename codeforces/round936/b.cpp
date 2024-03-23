#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 mod = 1e9+7;

i64 quick_pow(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while(b) {
        if(b&1) {
            res = res * a % p;
        }
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    i64 sm = 0;
    std::vector<int> a(n + 1);
    std::vector<i64> dp(n + 1);
    dp[0] = -1e9-7;
    i64 mx = dp[0];
    for(int i=1;i<=n;i++) {
        std::cin >> a[i];
        sm += a[i];
        dp[i] = std::max((i64)a[i], dp[i-1] + a[i]);
        mx = std::max(mx, dp[i]);
    }
    if(mx < 0) {
        std::cout << (sm % mod + mod) % mod << "\n";
        return;
    }
    sm -= mx;
    mx %= mod;
    std::cout << ((sm + quick_pow(2, k, mod) * mx % mod) % mod + mod) % mod << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}