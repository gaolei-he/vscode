#include <bits/stdc++.h>
#define int long long
void solve() {
    int n, m;
    std::cin >> n >> m;
    if(n & 1) {
        std::cout << n / 2 * (n / 2 + 1) << "\n";
    } else {
        std::cout << n / 2 * n / 2 << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}