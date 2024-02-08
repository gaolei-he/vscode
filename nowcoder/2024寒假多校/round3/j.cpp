#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> vec(k);
    for(auto &[x, y] : vec) {
        std::cin >> x >> y;
        x --, y --;
    }
    std::cout << "float\n";


    std::vector<std::vector<int>> g1(n), g2(m);
    for(auto [x, y] : vec) {
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    long double ans2 = 0;
    for(auto &v : g1) {
        long double val = 1;
        for(auto x : v) {
            val *= (long double)1 - (long double)1.0 / (int)g2[x].size();
        }
        ans2 += (long double)1 - val;
    }
    long double ans1 = 0;
    for(auto &v : g2) {
        long double val = 1;
        for(auto x : v) {
            val *= (long double)1 - (long double)1.0 / (int)g1[x].size();
        }
        ans1 += (long double)1 - val;
    }
    std::cout << std::fixed << std::setprecision(10) << ans2 << ' ' << ans1;

    return 0;
}