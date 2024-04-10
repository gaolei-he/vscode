#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    k -= 1;
    std::vector<int> vec(n);
    for(auto &x : vec) {
        std::cin >> x;
    }
    auto f = [&](int idx) {
        int res = 0;
        for(int i = idx + 1;i<n;i++) {
            if(vec[i] < vec[idx]) {
                res += 1;
            } else {
                break;
            }
        }
        return res;
    };
    std::swap(vec[0], vec[k]);
    int ans = f(0);
    std::swap(vec[0], vec[k]);
    for(int i=0;i<k;i++) {
        if(vec[i] > vec[k]) {
            std::swap(vec[i], vec[k]);
            int v = f(i);
            if(i) {
                v += 1;
            }
            ans = std::max(ans, v);
            break;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}