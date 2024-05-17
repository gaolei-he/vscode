#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int ans = 0;
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(b.begin(), b.end());
    for(auto c : a) {
        while(b.size() and b.back() != c) {
            b.pop_back();
        }
        if(b.size() and b.back() == c) {
            b.pop_back();
            ans += 1;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}