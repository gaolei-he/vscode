#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> app(1);
    std::vector<int> mul{1};
    std::vector<i64> len{0};
    while (n--) {
        int b, x;
        std::cin >> b >> x;
        if (b == 1) {
            app.back().push_back(x);
        } else {
            if (len.back() < inf) {
                len.push_back((inf / mul.back() >= len.back())
                                  ? mul.back() * len.back() + app.back().size()
                                  : inf);
                mul.push_back(x + 1);
                app.push_back({});
            }
        }
    }

    while (q--) {
        i64 k;
        std::cin >> k;
        k -= 1;

        for (int i = app.size() - 1; i >= 0; i--) {
            if (k / mul[i] >= len[i]) {
                std::cout << app[i][k - mul[i] * len[i]] << " \n"[q == 0];
                break;
            } else {
                k %= len[i];
            }
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