#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        int cnt = 0, idx = i;
        for (int j = 0; j < s.size() and idx < s.size();) {
            if (!(s[idx] == s[j] or s[idx] == '?' or s[j] == '?')) {
                idx++, j++;
                continue;
            }
            while (idx < s.size() and
                   (s[idx] == s[j] or s[idx] == '?' or s[j] == '?')) {
                idx++, j++;
                cnt += 1;
                if (cnt >= i) {
                    break;
                }
            }
            if (cnt == i) ans = std::max(ans, cnt);
            cnt = 0;
        }
    }
    std::cout << ans * 2 << "\n";
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