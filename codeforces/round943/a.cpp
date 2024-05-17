#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x;
    std::cin >> x;
    int ans = 1, res = 1;
    int mx = 0;
    for(;ans < x;ans ++) {
        if(std::gcd(x, ans) + ans > mx) {
            mx = std::gcd(x, ans) + ans;
            res = ans;
        }
    }
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout << std::gcd(1000, 750) + 750 << " " << std::gcd(1000, 500) + 500;
    // exit(0);
    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}