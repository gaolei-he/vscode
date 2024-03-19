#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    int ans = a + b / 3;
    b %= 3;
    if((3 - b) % 3 > c) {
        std::cout << -1 << "\n";
        return;
    }
    ans += (c + b) / 3;
    if((c + b) % 3) ans ++;
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