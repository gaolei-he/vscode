#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, m;
    std::cin >> a >> b >> m;
    m += 1;
    i64 ans = 0;
    ans += m / a + m / b;
    if(m % a) ans ++;
    if(m % b) ans ++;
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