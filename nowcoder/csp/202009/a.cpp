#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<std::array<int, 3>> vec;
    for(int i=0;i<n;i++) {
        int v, t;
        std::cin >> v >> t;
        vec.push_back({i, v, t});
    }
    std::sort(vec.begin(), vec.end(), [&](auto a, auto b) {
        int v1 = (a[1] - x) * (a[1] - x) + (a[2] - y) * (a[2] - y);
        int v2 = (b[1] - x) * (b[1] - x) + (b[2] - y) * (b[2] - y);
        if(v1 == v2) {
            return a[0] < b[0];
        }
        return v1 < v2;
    });
    for(int i=0;i<3;i++) {
        std::cout << vec[i][0] + 1 << "\n";
        // std::cout << vec[i][1] << " " << vec[i][2] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}