#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &x : vec) std::cin >> x;

    int ans = 0;
    for (auto x : vec) {
        int val = std::stoi(std::to_string(x) + std::to_string(x));
        if (val % 36 == 0) ans--;
        for (auto y : vec) {
            int val = std::stoi(std::to_string(x) + std::to_string(y));
            if (val % 36 == 0) ans++;
        }
    }

    std::cout << ans << '\n';

    return 0;
}