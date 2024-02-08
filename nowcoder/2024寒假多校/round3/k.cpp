#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    int ca = 1, cb = 0;
    int ver = 1;
    std::queue<int> black, white;
    black.push(1);
    std::map<int, std::vector<int>> ans;
    while ((ca < a and white.size()) or (cb < b and black.size())) {
        while (ca < a and white.size()) {
            ca += 2;
            int v = white.front();
            white.pop();
            ans[v].push_back(++ver);
            black.push(ver);
            ans[v].push_back(++ver);
            black.push(ver);
        }
        while (cb < b and black.size()) {
            cb += 2;
            int v = black.front();
            black.pop();
            ans[v].push_back(++ver);
            white.push(ver);
            ans[v].push_back(++ver);
            white.push(ver);
        }
    }

    if (ca == a and cb == b and ver == a + b) {
        std::cout << "Yes\n";
        for (int i = 1; i <= a + b; i++) {
            if (ans.count(i)) {
                for (auto x : ans[i]) {
                    std::cout << x << ' ';
                }
                std::cout << "\n";
            } else {
                std::cout << "-1 -1\n";
            }
        }
    } else {
        std::cout << "No\n";
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