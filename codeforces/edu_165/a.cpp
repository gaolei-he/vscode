#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n + 1);
    for(int i=1;i<=n;i++) {
        std::cin >> vec[i];
    }
    int ans = 3;
    for(int i=1;i<=n;i++) {
        if(vec[vec[i]] == i) {
            ans = 2;
            break;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}