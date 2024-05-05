#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    i64 ans = 0;
    int cnt = 0;
    for (auto x : s) {
        if (x == '1') {
            cnt += 1;
        } else {
            if (cnt) {
                ans += cnt + 1;
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}