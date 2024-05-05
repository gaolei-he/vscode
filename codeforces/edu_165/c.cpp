#include <bits/stdc++.h>
#define int long long
using i64 = long long;
// class Node {
//    private:
//     i64 bonus;
//     int t;

//    public:
//     Node(i64 bonus, int t) {
//         this->bonus = bonus;
//         this->t = t;
//     }
//     bool operator<(const Node& node) {
//         this->bonus * node.t < node.bonus * this->t;
//     }
// };

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> vec(n + 1);
    i64 sm = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> vec[i];
        sm += vec[i];
    }
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1));
    for (int i = 0; i <= k; i++) dp[1][i] = vec[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int mi = vec[i];
            dp[i][j] = dp[i - 1][j] + vec[i];
            // if (i - j > 0) mi = std::min(mi, vec[i - j]);
            for (int l = 1; l <= j and i - 1 - l >= 0; l++) {
                mi = std::min(mi, vec[i - l]);
                dp[i][j] =
                    std::min(dp[i][j], mi * (l + 1) + dp[i - 1 - l][j - l]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         std::cerr << dp[i][j] << " ";
    //     }
    //     std::cerr << "\n";
    // }
    std::cout << dp[n][k] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}