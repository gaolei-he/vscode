#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    std::vector<i64> dp(n + 1, -1e9-10);
    for(int i=1;i<=n;i++) {
        std::cin >> a[i];
        dp[i] = std::max((i64)a[i], dp[i-1] + a[i]);
    }
    while(q--) {
        int x;
        std::cin >> x;
        std::cout << dp[x] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}