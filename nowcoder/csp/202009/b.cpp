#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k, t, xl, yd, xr, yu;
    std::cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    int ans1 = 0, ans2 = 0;
    for(int i=0;i<n;i++) {
        std::vector<std::pair<int, int>> vec;
        for(int j=0;j<t;j++) {
            int x, y;
            std::cin >> x >> y;
            vec.emplace_back(x, y);
        }
        int lst = 0;
        bool flag1 = false, flag2 = false;
        for(auto &p : vec) {
            if(p.first >= xl and p.first <= xr and p.second >= yd and p.second <= yu) {
                flag1 = true;
                lst += 1;
            } else {
                lst = 0;
            }
            if(lst >= k) {
                flag2 = true;
            }
        }
        if(flag1) {
            ans1 += 1;
        }
        if(flag2) {
            ans2 += 1;
        }
    }
    std::cout << ans1 << "\n" << ans2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}