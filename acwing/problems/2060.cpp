#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> vec1, vec2;
    std::vector<std::string> mps(n);
    for (auto& s : mps) {
        std::cin >> s;
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    std::function<void(int, int, int)> dfs = [&](int x, int y, int op) {
        if (op == 0) {
            vec1.emplace_back(x, y);
        } else if (op == 1) {
            vec2.emplace_back(x, y);
        }
        mps[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 and tx < n and ty >= 0 and ty < m and
                mps[tx][ty] == 'X') {
                dfs(tx, ty, op);
            }
        }
    };
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mps[i][j] == 'X' and flag) {
                dfs(i, j, 0);
                flag = false;
            } else if(mps[i][j] == 'X' and !flag) {
                dfs(i, j, 1);
            }
        }
    }

    int ans = 1'000'000'000;
    for (auto [x1, y1] : vec1) {
        for (auto [x2, y2] : vec2) {
            ans = std::min(ans, std::abs(x1 - x2) + std::abs(y1 - y2));
        }
    }
    std::cout << ans - 1 << "\n";

    return 0;
}