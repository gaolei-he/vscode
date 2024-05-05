#include <bits/stdc++.h>
#define int long long
using i64 = long long;

void solve() {
    i64 n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    std::vector<int> sm(n + 2);
    for (int i = 1; i <= n; i++) {
        i64 x;
        std::cin >> x;
        a[i] = x;
    }
    std::vector<std::vector<int>> rec(n + 2);
    while (q--) {
        i64 op, l, r, x;
        std::cin >> op >> l >> r >> x;
        if (op == 2) {
            op = -1;
        }
        rec[l].emplace_back(op * x);
        rec[r + 1].emplace_back(-op * x);
    }
    a[0] = 1;
    int factor = 1;
    auto f = a;
    for (int i = 1; i <= n; i++) {
        factor *= f[i];
        factor /= f[i - 1];
        for (auto x : rec[i]) {
            if (x > 0) {
                factor *= x;
            } else {
                factor /= -x;
            }
        }

        a[i] = factor;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << (i64)a[i] << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}