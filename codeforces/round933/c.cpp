#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(s.substr(i, 3) == "pie") {
            ans += 1;
        } else if(s.substr(i, 5) == "mapie") {
            ans += 1;
            i += 3;
        } else if(s.substr(i, 3) == "map") {
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