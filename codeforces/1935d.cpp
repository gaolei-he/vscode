#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> vec(n);
    i64 ans = (n + 1) * (2ll + n) / 2;
    for(auto &x : vec) {
        std::cin >> x;
        ans -= x / 2;
        ans -= c - x + 1;
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