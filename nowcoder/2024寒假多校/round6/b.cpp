#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::map<int, int> mp1;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp1[x] += 1;
    }

    std::vector<std::pair<int, int>> vec;
    int mi = 2'000'000'009;
    int val = -1;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        vec.emplace_back(x, -1);
        auto it = mp1.lower_bound(x);
        if (it != mp1.end()) {
            if (std::abs(it->first - x) < mi) {
                mi = std::abs(it->first - x);
                val = it->first;
                tmp = x;
            }
        }
        if (it != mp1.begin()) {
            --it;
            if (std::abs(it->first - x) < mi) {
                mi = std::abs(it->first - x);
                val = it->first;
                tmp = x;
            }
        }
    }

    mp1[val] -= 1;

    for (auto &[x, y] : vec) {
        if (x == tmp) {
            y = val;
            break;
        }
    }
    for (auto &[x, y] : vec) {
        if (y == -1) {
            while (mp1.begin()->second == 0) {
                mp1.erase(mp1.begin());
            }
            y = mp1.begin()->first;
            mp1.begin()->second -= 1;
        }
        std::cout << y << ' ';
    }
    return 0;
}