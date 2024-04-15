#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "1 1\n1 1 1\n";
        return;
    }
    std::vector<std::vector<int>> vec(n + 1, std::vector<int>(n + 1));
    std::vector<std::pair<int, int>> ans;
    std::function<void(int, int)> add = [&](int type, int idx) -> void {
        if (type == 1) {
            for (int i = 1; i <= n; i++) {
                vec[idx][i] = n - i + 1;
            }
        } else if (type == 2) {
            for (int i = 1; i <= n; i++) {
                vec[i][idx] = n - i + 1;
            }
        }
    };
    for(int i=1;i<=n;i++) {
        ans.emplace_back(1, i);
        add(1, i);
        ans.emplace_back(2, i);
        add(2, i);
    }
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sm += vec[i][j];
            // std::cerr << vec[i][j] << " \n"[j == n];
        }
    }
    std::cout << sm << " " << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x << " " << y;
        for (int i = n; i; i--) {
            std::cout << " " << i;
        }
        std::cout << "\n";
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

/*

4 4 4 4
4 3 3 3
4 3 2 2
4 3 2 1
*/