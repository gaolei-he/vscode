#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (auto& s : mp) {
        std::cin >> s;
    }
    std::vector<std::vector<int>> sm(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i or !j) {
                if (mp[i][j] == '*') {
                    sm[i][j] = 1;
                }
            } else {
                sm[i][j] = sm[i][j - 1];
                if (mp[i][j] == '*') {
                    sm[i][j] += 1;
                }
            }
        }
    }

    auto calc = [&](int x, int y) {
        if (mp[x][y] != '*') {
            return 0;
        }
        int res = 0;
        bool flag = true;
        // bool debug = false;
        // if(x == 0 and y == 2) debug = true;
        x += 1;
        for (int ly = y - 1, ry = y + 1; x < n and ly >= 0 and ry < m;
             x++, ly--, ry++) {
            if (mp[x][ly] != '*' or mp[x][ry] != '*') {
                flag = false;
            }
            // if(debug) std::cerr << ry - ly << ' ' << sm[x][ry] - sm[x][ly] <<
            // ' ' << x << ' ' << ly << ' ' << ry << std::endl;
            if (mp[x][ly] == '*' and mp[x][ry] == '*' and
                sm[x][ry] - sm[x][ly] == ry - ly and flag) {
                // std::cerr << x << ' ' << ly << ' ' << ry << std::endl;
                res += 1;
            }
        }
        return res;
    };
    int ans = 0;
    for (int i = 0; i < mp.size(); i++) {
        for (int j = 0; j < mp[i].size(); j++) {
            ans += calc(i, j);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}