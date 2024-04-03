#include <bits/stdc++.h>

using i64 = long long;

int lowbit(int x) {
    return x & (-x);
}

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a + 1 != c) {
        std::cout << -1 << "\n";
        return;
    }
    int idx = 0;
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    int ans = 0;
    while(a) {
        auto v = q.front();
        q.pop();
        idx += 1;
        q.push({idx, v.second + 1});
        idx += 1;
        q.push({idx, v.second + 1});
        a -= 1;
        ans = v.second + 1;
    }
    while(b) {
        auto v = q.front();
        q.pop();
        idx += 1;
        q.push({idx, v.second + 1});
        b -= 1;
        ans = v.second + 1;
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