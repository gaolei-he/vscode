#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::set<std::pair<int, int>> S;
    std::vector<int> colors;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int color;
        std::cin >> color;
        color -= 1;
        colors.push_back(color);
        g[color].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
            continue;
        }
        S.emplace(g[i].back(), i);
    }
    int ans = 0;
    int pos = n;
    while (!S.empty()) {
        auto p = *S.begin();
        S.erase(S.begin());

        for (int i = pos - 1; i >= p.first; --i) {
            int color = colors[i];
            g[color].pop_back();
            if (!g[color].empty()) S.emplace(g[color].back(), colors[i]);
        }
        ans += 1;
        pos = p.first;
        if (pos == 0) {
            break;
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