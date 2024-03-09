#include <bits/stdc++.h>

using i64 = long long;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &x : a) {
        std::cin >> x;
    }
    for (auto &x : b) {
        std::cin >> x;
    }
    std::map<int, std::set<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].insert(i);
    }
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(27));
    auto g = f;
    for (int i = 1; i <= n; i++) {
        f[i][0] = b[i - 1];
        g[i][0] = a[i - 1];
    }
    for (int j = 1; j <= 26; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = std::min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = std::max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto lowbit = [](int x) { return x & (-x); };
    std::vector<int> lg(n + 10);
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i <= n; i++) {
        if (lowbit(i) == i) {
            lg[i] = lg[i - 1] + 1;
        } else {
            lg[i] = lg[i - 1];
        }
    }
    auto check = [&](int l, int r, int x) {
        l += 1, r += 1;
        int s = lg[r - l + 1];
        int val1 = std::min(f[l][s], f[r - (1 << s) + 1][s]);
        int val2 = std::max(g[l][s], g[r - (1 << s) + 1][s]);
        if(val2 > x or val1 < x) {
            return false;
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        } else if (a[i] > b[i]) {
            std::cout << "NO\n";
            return;
        } else {
            auto it = mp[b[i]].lower_bound(i);

            if (it != mp[b[i]].end() and mp[b[i]].size()) {
                if (check(i, *it, b[i])) {
                    continue;
                }
            }
            if (it != mp[b[i]].begin() and mp[b[i]].size()) {
                --it;
                // std::cerr << b[i] << " " << *mp[2].begin();
                if (check(*it, i, b[i])) {
                    continue;
                }
            }
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}