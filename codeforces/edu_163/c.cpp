#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char a[3][N];
bool vis[3][N];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            vis[i][j] = false;
        }
    }
    std::function<void(int, int)> dfs = [&](int x, int y) {
        // std::cerr << x << " " << y << "\n";
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 1 and tx <= 2 and ty >= 1 and ty <= n) {
                if (a[tx][ty] == '>') {
                    ty++;
                } else {
                    ty--;
                }
                if (!vis[tx][ty]) {
                    dfs(tx, ty);
                }
            }
        }
    };
    dfs(1, 1);
    if (vis[2][n]) {
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