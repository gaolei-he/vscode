#include <bits/stdc++.h>

using i64 = long long;

int lowbit(int x) { return x & (-x); }

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> vec(n);
    for (auto &k : vec) {
        std::cin >> k;
    }
    int ans = -1;
    int tmp = x;
    int now = 0, cnt = 0;
    for (auto v : vec) {
        now ^= v;
        if ((now | tmp) <= tmp) {
            now = 0;
            cnt += 1;
        }
    }
    if (!now) {
        ans = std::max(ans, cnt);
    }
    while (x) {
        int val = lowbit(x);
        x -= lowbit(x);
        int tmp = x + (val - 1);
        int now = 0, cnt = 0;
        for (auto v : vec) {
            now ^= v;
            if ((now | tmp) < x + val) {
                now = 0;
                cnt += 1;
            }
        }
        if (!now) {
            ans = std::max(ans, cnt);
        }
    }
    std::cout << ans << "\n";
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

/*
01
10
11

*/