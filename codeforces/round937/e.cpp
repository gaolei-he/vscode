#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int k = 1; k <= n; k++) {
        if(n % k) {
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++) {
            if(s[i] != s[i % k]) {
                cnt1 ++;
            }
        }
        if(n >= k * 2) {
            for(int i=0;i<n;i++) {
                if(s[i] != s[i % k + k]) {
                    cnt2 ++;
                }
            }
            cnt1 = std::min(cnt1, cnt2);
        }
        if(cnt1 < 2) {
            std::cout << k << "\n";
            return;
        }
    }
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