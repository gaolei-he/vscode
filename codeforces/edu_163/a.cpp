#include <bits/stdc++.h>

using i64 = long long;
std::string data = "AB";
void solve() {
    int n;
    std::cin >> n;
    if(n & 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        int op = 0;
        while (n) {
            n -= 2;
            std::cout << data[op] << data[op];
            op = op ? 0 : 1;
        }
        std::cout << "\n";
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