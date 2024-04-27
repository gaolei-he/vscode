#include <functional>
#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = std::max(dp[i], dp[i - 1] + a[i]);
        for (int j = i; j <= n; j++) {
            dp[j] = std::max(dp[j], dp[i - 1] + (j - i + 1) * (j - i + 1));
        }
    }
    std::vector<std::pair<int, int>> ans;
    for (int i = n; i > 0;) {
        if (dp[i] == dp[i - 1] + a[i]) {
            i--;
        } else {
            int r = i, l;
            for (int j = i; j; j--) {
                if (dp[i] == dp[j - 1] + (i - j + 1) * (i - j + 1)) {
                    l = j;
                    i = j - 1;
                    break;
                }
            }
            int cnt = 0;
            for (int j = l; j <= r; j++) {
                if (a[j]) {
                    cnt++;
                }
            }
            // std::cerr << l << " " << r << " " << cnt << "\n";
            if (cnt != r - l + 1 and cnt) {
                ans.emplace_back(l, r);
                ans.emplace_back(l, r);
            } else if (cnt == r - l + 1) {
                ans.emplace_back(l, r);
            }
            std::vector<int> vec(20);
            std::function<void(int, int)> dfs = [&](int l, int r) {
                // std::cerr << l << " " << r << "\n";
                if (l >= r and vec[l] != 0) {
                    ans.emplace_back(l, l);
                } else if (l >= r and vec[l] == 0) {
                    return;
                } else {
                    dfs(l, r - 1);
                    ans.emplace_back(l, r);
                    for (int j = l; j <= r; j++) vec[j] = 1;
                    dfs(l, r - 1);
                }
            };
            dfs(l, r);
            ans.emplace_back(l, r);
        }
    }
    std::cout << dp[n] << " " << ans.size() << "\n";
    for (auto [l, r] : ans) {
        std::cout << l << " " << r << "\n";
    }
}

int main() {
    solve();
    return 0;
}
