#include <bits/stdc++.h>
#define int long long
const int mod = 1000000007;
void solve() {
    int q;
    std::cin >> q;
    int sm = 0, cnt = 0;
    std::vector<int> vec;
    while(q --) {
        int t, v;
        std::cin >> t >> v;
        while(t --) {
            sm -= cnt * vec.back() % mod;
            sm += mod;
            sm %= mod;
            cnt -= 1;
            vec.pop_back();
        }
        vec.push_back(v);
        cnt += 1;
        sm += v * cnt % mod;
        sm %= mod;
        std::cout << sm << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}