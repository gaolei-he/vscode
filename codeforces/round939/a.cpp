#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int k, q;
    std::cin >> k >> q;
    std::vector<int> vec(k);
    for(auto &x : vec) {
        std::cin >> x;
    }
    while(q --) {
        int x;
        std::cin >> x;
        if(x < vec.front()) {
            std::cout << x << " ";
        } else {
            std::cout << vec.front() - 1 << " ";
        }
    }
    std::cout << "\n";
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