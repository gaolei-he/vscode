#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<int> sm(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            sm[i] = 1;
        }
        sm[i] += sm[i - 1];
    }
    std::vector<int> ans;
    for (int i = 0; i <= n; i++) {
        int val1 = i, val2 = n - i;
        if (i - sm[i] >= (i + 1) / 2 and
            (sm[n] - sm[i] >= (n - i + 1) / 2)) {
            ans.emplace_back(i);
        }
    }
    int val = -1;
    int res = -1;
    for(auto x : ans) {
        if(std::min(x, n - x) > val) {
            val = std::min(x, n - x);
            res = x;
        }
    }
    std::cout << res << "\n";
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