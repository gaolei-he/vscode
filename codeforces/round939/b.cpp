#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n + 1);
    for(int i=1;i<=n;i++) {
        int x;
        std::cin >> x;
        vec[x] += 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(vec[i] == 2) {
            ans += 1;
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