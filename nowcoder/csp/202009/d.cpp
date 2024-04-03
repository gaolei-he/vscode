#include <bits/stdc++.h>

using i64 = long long;
using f128 = long double;
f128 dist(int x1, int y1, int x2, int y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n, m, r;
    std::cin >> n >> m >> r;
    int x, y;
    std::cin >> x >> y;
    std::vector<std::pair<int, int>> vec(m);
    for(auto &p : vec) {
        std::cin >> p.first >> p.second;
    }
    auto calc = [&](auto a, auto b) {
        if(a == b) {
            return (f128)0.0;
        }
        int x1 = a.first, y1 = a.second;
        int x2 = b.first, y2 = b.second;
        f128 res = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        f128 A, B, C;
        if(x1 == x2) {
            B = 0, A = 1;
            C = -x1;
        } else {
            f128 k = (y1 - y2) * 1.0 / (x1 - x2);
            f128 b = y1 - k * x1;
            A = -k, B = 1, C = -b;
        }

        f128 len = std::fabs(A * x + B * y + C) / std::sqrt(A * A + B * B);
        if(len >= r) {
            return res;
        }
        res = 0;
        f128 l1 = dist(x, y, x1, y1);
        res += std::sqrt(l1 * l1 - r * r);
        f128 l2 = dist(x, y, x2, y2);
        res += std::sqrt(l2 * l2 - r * r);
        f128 theta = std::acos(len / l1) + std::acos(len / l2);
        theta -= std::acos(r / l1) + std::acos(r / l2);
        res += theta * r;
        return res;
    };
    for(auto &p : vec) {
        f128 ans = 0;
        for(auto &v : vec) {
            ans += calc(p, v);
        }
        std::cout << std::fixed << std::setprecision(13) << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}