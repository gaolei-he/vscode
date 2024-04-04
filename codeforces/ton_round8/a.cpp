#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(n == k) {
        for(int i=1;i<=n;i++) {
            std::cout << 1 << " \n"[i == n];
        }
    } else if(k == 1) {
        for(int i=1;i<=n;i++) {
            std::cout << i << " \n"[i == n];
        }
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}