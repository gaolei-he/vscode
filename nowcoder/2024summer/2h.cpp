#include <bits/stdc++.h>
#define int long long
using ar2 = std::array<int, 2>;
using pii = std::pair<int, int>;
void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::string op;
    std::cin >> op;
    std::vector<ar2> sm(n + 1);
    std::map<pii, std::priority_queue<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (op[i - 1] == 'W') {
            sm[i][1] = 1;
        } else if (op[i - 1] == 'A') {
            sm[i][0] = -1;
        } else if (op[i - 1] == 'S') {
            sm[i][1] = -1;
        } else if (op[i - 1] == 'D') {
            sm[i][0] = 1;
        }
        sm[i][0] += sm[i - 1][0];
        sm[i][1] += sm[i - 1][1];
        mp[{sm[i][0], sm[i][1]}].push(n - i + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[{sm[i - 1][0] + x, sm[i - 1][1] + y}].size()) {
            ans += mp[{sm[i - 1][0] + x, sm[i - 1][1] + y}].top();
        }
        mp[{sm[i][0], sm[i][1]}].pop();
    }
    if (x == 0 and y == 0) {
        ans = n * (n + 1) / 2;
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}