#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    for(auto &x : a) {
        std::cin >> x;
    }
    for(auto &x : b) {
        std::cin >> x;
    }
    i64 ans = 0;
    for(int i=m;i<n;i++) {
        ans += std::min(a[i], b[i]);
    }
    i64 val = 0, res = a[m - 1];
    for(int i=m-1;i>=0;i--) {
        if(val + a[i] < res) {
            res = val + a[i];
        }
        val += std::min(a[i], b[i]);
    }
    std::cout << ans + res << "\n";
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