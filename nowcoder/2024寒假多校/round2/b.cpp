#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::set<std::tuple<int, int, int>> S;
    while(k --) {
        int x, y;
        std::cin >> x >> y;
        S.emplace(x, y, 0);
        S.emplace(x + 1, y, 0);
        S.emplace(x, y, 1);
        S.emplace(x, y + 1, 1);
    }

    std::cout << S.size() << std::endl;


    return 0;
}