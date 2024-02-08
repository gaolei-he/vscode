#include <bits/stdc++.h>

using i64 = long long;
using ar3 = std::array<int, 3>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<ar3> vec(n);
    std::set<std::string> S;
    for (auto &[x, y, z] : vec) {
        std::cin >> x >> y >> z;
        S.insert(std::to_string(x) + std::to_string(y) + std::to_string(z));
    }

    for (auto [x, y, z] : vec) {
        if (z == 1 and S.count(std::to_string(y * 100 + x * 10 + z)) or
            z == 0 and S.count(std::to_string(x * 100 + y * 10 + 1))) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
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