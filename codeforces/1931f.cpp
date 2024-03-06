#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> g(n);
    std::vector<int> deg(n);
    for (int i = 0; i < k; ++i) {
        int x, lst = -1;
        std::cin >> x;
        for (int j = 1; j < n; ++j) {
            std::cin >> x;
            x -= 1;
            if (lst == -1) {
                lst = x;
            } else {
                g[lst].push_back(x);
                lst = x;
                deg[x] += 1;
            }
        }
    }

    auto top_sort = [&]() {
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int ver = q.front();
            q.pop();
            cnt += 1;
            for (auto x : g[ver]) {
                deg[x] -= 1;
                if (deg[x] == 0) {
                    q.push(x);
                }
            }
        }
        return cnt == n;
    };
    if (top_sort()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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