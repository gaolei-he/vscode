#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> b(n), c(m);
    for(auto &x : b) {
        std::cin >> x;
    }
    for(auto &x : c) {
        std::cin >> x;
    }
    int ans = 0;
    for(auto x : b) {
        for(auto y : c) {
            if(x + y <= k) {
                ans += 1;
            }
        }
    }
    std::cout << ans << "\n";
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