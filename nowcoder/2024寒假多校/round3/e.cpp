#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    i64 ans = -inf;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        ans = std::max(ans, (i64)a[i]);
    }
    if (ans < 0) {
        std::cout << ans << std::endl;
        return 0;
    }

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(n, i + k); j >= std::max(1, i - k); --j) {
            int x = std::abs(i - j);
            for (int m = x; m <= k; ++m) {
                dp[j][m] =
                    std::max(dp[j][m], a[i] + std::max(0ll, dp[j - 1][m - x]));
                ans = std::max(ans, dp[j][m]);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}