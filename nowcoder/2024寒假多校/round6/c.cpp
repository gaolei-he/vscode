#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;
    std::vector<int> numbers{0, 1};
    while (numbers.back() < 1'000'000'000) {
        numbers.emplace_back(numbers.back() + numbers[numbers.size() - 2]);
    }
    std::map<i64, std::pair<int, int>> mp;
    for (auto x : numbers) {
        for (auto y : numbers) {
            mp[x + 0ll + y] = {x, y};
        }
    }
    auto solve = [&] {
        i64 n;
        std::cin >> n;
        for (auto x : numbers) {
            if (mp.count(n - x)) {
                std::cout << x << ' ' << mp[n - x].first << ' '
                          << mp[n - x].second << std::endl;
                return;
            }
        }
        std::cout << "-1\n";
    };
    while (q--) {
        solve();
    }
    return 0;
}