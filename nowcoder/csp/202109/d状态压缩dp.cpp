#include <bits/stdc++.h>

using i64 = long long;
int n, k;
std::vector<double> vec;
double f[81][1 << 16];
double dfs(int depth, int coin, int status, int cnt) {
    if (f[coin][status]) {
        return f[coin][status];
    } else if (cnt * k <= coin) {
        return (double)depth;
    }
    double s = 0;
    for (int i = 0; i < n; ++i) {
        if ((status & (1 << i))) {
            s += vec[i] * dfs(depth + 1, coin + 1, status, cnt);
        } else {
            s += vec[i] * dfs(depth + 1, coin, status | (1 << i), cnt - 1);
        }
    }
    return f[coin][status] = s;
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    vec.resize(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
    std::cout << std::fixed << std::setprecision(8) << dfs(0, 0, 0, n);

    return 0;
}