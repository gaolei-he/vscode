#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> tr;
    auto add = [&](int x, int c) {
        for (int i = x; i <= n; i += (x & (-x))) {
            tr[i] += c;
        }
    };
    auto sum = [&](int x) {
        int res = 0;
        for (int i = x; i; i -= (x & (-x))) {
            res += tr[i];
        }
        return res;
    };
    auto check = [&](int k) -> bool {
        tr.assign(n + 10, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                add(i, 1);
                add(i + 1, -1);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (sum(i) % 2 != 1) {
                if (i > n - k + 1) {
                    return false;
                }
                add(i, 1);
                add(i + k, -1);
            }
        }
        return true;
    };

    for (int i = n; i; i--) {
        if (check(i)) {
            std::cout << i << "\n";
            return;
        }
    }
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