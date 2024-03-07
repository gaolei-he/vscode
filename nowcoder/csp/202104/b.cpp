#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, L, r, t;
    std::cin >> n >> L >> r >> t;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    auto sm = a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            sm[i][j] = a[i][j];
            sm[i][j] += sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x1 = std::max(1, i - r), y1 = std::max(1, j - r);
            int x2 = std::min(n, i + r), y2 = std::min(n, j + r);
            int tmp = sm[x2][y2] - sm[x1 - 1][y2] - sm[x2][y1 - 1] +
                      sm[x1 - 1][y1 - 1];
            // std::cerr << tmp << "\n";
            if(tmp <= t * (y2 - y1 + 1) * (x2 - x1 + 1)) {
                ans += 1;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}