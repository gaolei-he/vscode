#include <bits/stdc++.h>
#define int long long
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(n % 2 == 0) {
        int ans = k % n;
        if(ans == 0) {
            ans = n;
        }
        std::cout << ans << "\n";
    } else {
        int t = ((n - 1) + n / 2 * (n - 2));
        k %= t;
        if(k == 0) k = t;
        // std::cerr << k << " " << t << "\n";
        if(k < n) {
            if(k <= n / 2) {
                std::cout << k << "\n";
            } else {
                std::cout << k + 1 << "\n";
            }
        } else {
            k -= n - 1;
            int l = k / (n - 2);
            if(k % (n - 2)) {
                l += 1;
            }
            k %= n - 2;
            if(k % (n - 2) == 0) {
                k = n - 2;
            }
            int r = l + n / 2 + 1;
            // std::cerr << l << " " << r << " " << k << "\n";
            int ans = k;
            if(ans >= l) {
                ans += 1;
            }
            if(ans >= r) {
                ans += 1;
            }
            std::cout << ans << "\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int n;
    // std::cin >> n;
    // std::vector<int> v1(n), v2(n);
    // std::iota(v1.begin(), v1.end(), 1);
    // std::iota(v2.begin(), v2.end(), 1);
    // std::reverse(v1.begin(), v1.end());
    // int length = 40;
    // for(int i=0;i<=length;i++) {
    //     std::cout << v1[i % n] << " \n"[i == length];
    // }
    // int cnt = 0;
    // for(int i=0;cnt <= length;i++) {
    //     if(v2[i % n] == v1[cnt % n]) {
    //         i += 1;
    //     }
    //     std::cout << v2[i % n] << " \n"[cnt == length];
    //     cnt += 1;
    // }
    // exit(0);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*

3
1 4
2 5

4
1 5
2 6
3 7

5
1 6
2 7
3 8
4 9

*/