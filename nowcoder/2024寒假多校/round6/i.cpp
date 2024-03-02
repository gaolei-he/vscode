#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> vn(n + 1), vm(m + 1);
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> vn[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> vm[i];
    }
    int vmax = -1'000'000'100, vmin = 1'000'000'100;
    int tmax = -1'000'000'100, tmin = 1'000'000'100;
    dp.assign(n + 1, vmax);
    for (int i = 1; i <= n; ++i) {
        dp[i] = std::max(vn[i], dp[i - 1] + vn[i]);
        vmax = std::max(dp[i], vmax);
    }
    dp.assign(n + 1, vmin);
    for (int i = 1; i <= n; ++i) {
        dp[i] = std::min(vn[i], dp[i - 1] + vn[i]);
        vmin = std::min(dp[i], vmin);
    }
    dp.assign(m + 1, tmax);
    for (int i = 1; i <= m; ++i) {
        dp[i] = std::max(vm[i], dp[i - 1] + vm[i]);
        tmax = std::max(tmax, dp[i]);
    }
    dp.assign(m + 1, tmin);
    for (int i = 1; i <= m; ++i) {
        dp[i] = std::min(vm[i], dp[i - 1] + vm[i]);
        tmin = std::min(tmin, dp[i]);
    }
    std::cout << std::max(std::max(tmax * 1ll * vmax, tmin * 1ll * vmax),
                          std::max(vmin * 1ll * tmax, vmin * 1ll * tmin));
    return 0;
}