#include <bits/stdc++.h>
using ar3 = std::array<int, 3>;
void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    a = " " + a;
    b = " " + b;
    std::vector<ar3> dp(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 'R' and b[i] == 'R') {
            dp[i][0] = std::max(dp[i - 1][1] + 2, dp[i - 1][0] + 1);
            dp[i][1] = std::max(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
        } else if(a[i] == 'R') {
            dp[i][0] = dp[i-1][0] + 1;
        } else if(b[i] == 'R') {
            dp[i][1] = dp[i-1][1] + 1;
        }
        ans = std::max(ans, dp[i][0]);
        ans = std::max(ans, dp[i][1]);
    }
    if(ans) {
        ans --;
    }
    std::cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}