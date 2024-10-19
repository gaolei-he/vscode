#include <bits/stdc++.h>
#define int long long
void solve() {
    int n, R;
    std::cin >> n >> R;
    double ans = n * std::sin(2 * M_PI / n) / 2 * R * R ;
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
