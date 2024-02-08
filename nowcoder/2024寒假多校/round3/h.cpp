#include <bits/stdc++.h>

using i64 = long long;
using ar3 = std::array<int, 3>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<ar3> vec(n);
    for (auto &[x, y, z] : vec) {
        std::cin >> x >> y >> z;
    }

    std::vector<ar3> tries = {{1, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0},
                              {2, 1, 1}, {1, 2, 1}, {1, 1, 2}, {1, 2, 3},
                              {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2},
                              {3, 2, 1}};

    for (auto &arr : tries) {
        bool flag = true;
        for (auto [x, y, z] : vec) {
            if (z == 1 and arr[x - 1] >= arr[y - 1]) flag = false;
            if (z == 0 and arr[x - 1] < arr[y - 1]) flag = false;
        }
        if (flag) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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