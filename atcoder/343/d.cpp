#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;
    std::vector<std::pair<int, int>> vec(t);
    for (auto &[x, y] : vec) {
        std::cin >> x >> y;
    }
    std::map<i64, int> mp;
    mp[0] = n;
    std::vector<i64> scores(n);
    for (auto [x, y] : vec) {
        x -= 1;
        mp[scores[x]] -= 1;
        if (mp[scores[x]] == 0) {
            mp.erase(scores[x]);
        }
        scores[x] += y;
        mp[scores[x]] += 1;
        std::cout << mp.size() << std::endl;
    }

    return 0;
}