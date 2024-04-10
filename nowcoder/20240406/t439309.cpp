#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;
    std::vector<std::pair<int, int>> query(k);
    int v1 = 0, v2 = 0;
    for (auto &[x, y] : query) {
        std::cin >> x >> y;
        x -= y;
        std::swap(x, y);
        v1 = std::max(x, v1);
        v2 = std::max(v2, y);
    }
    std::string ans;
    for (int i = 0; i < v1; i++) {
        ans.push_back('1');
    }
    for (int i = 0; i < v2; i++) {
        ans.push_back('0');
    }
    std::cout << ans.size() << "\n" << ans << "\n";
    for(auto [x, y] : query) {
        std::cout << v1 - x << "\n";
    }


    return 0;
}