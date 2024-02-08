#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 1'000'000'000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1, -inf);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    i64 mx = -1'000'000'000;
    for (int idx = 0; idx < n; ++idx) {
        if (idx) std::swap(a[idx], a[idx + 1]);

        std::vector<i64> dp(n + 1, -inf);
        for (int i = 1; i <= n; ++i) {
            dp[i] = std::max((i64)a[i], dp[i - 1] + a[i]);
            mx = std::max(mx, dp[i]);
        }

        if (idx) std::swap(a[idx], a[idx + 1]);
        if(k == 0) break;
    }
    std::cout << mx;
    return 0;
}