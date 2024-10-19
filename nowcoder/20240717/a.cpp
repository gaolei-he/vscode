#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int ans = -1;
    int len = std::__lg(n);
    if (n == 0) {
        ans = 0;
    } else if (n == 1) {
        ans = 1;
    } else {
        ans = len - 1;
        while (n) {
            if (n & 1) {
                ans += 1;
            }
            n >>= 1;
        }
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