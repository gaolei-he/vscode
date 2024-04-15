#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    if(m == 1) {
        std::cout << "NO\n";
    } else if(m == 2) {
        if(k >= n / 2) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    } else if(m > 2) {
        int val = n / m * (m - 1);
        if (n % m) {
            val += n % m - 1;
        }
        if(k >= val) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
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