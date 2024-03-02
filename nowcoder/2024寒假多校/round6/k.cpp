#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::string> str(n + 1, " ");
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        str[i] += s;
    }
    auto tmp = str;
    std::vector<std::vector<std::vector<int>>> sm(
        12, std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, 0)));

    std::vector<std::vector<std::string>> rec{
        {"red", "edr", "dre"}, {"edr", "dre", "red"}, {"dre", "red", "edr"},
        {"red", "dre", "edr"}, {"dre", "edr", "red"}, {"edr", "red", "dre"},
        {"der", "rde", "erd"}, {"rde", "erd", "der"}, {"erd", "der", "rde"},
        {"der", "erd", "rde"}, {"erd", "rde", "der"}, {"rde", "der", "erd"},
    };

    for (int idx = 0; idx < 12; ++idx) {
        for (int i = 1; i <= std::min(n, 3); ++i) {
            for (int j = 1; j <= std::min(m, 3); ++j) {
                tmp[i][j] = rec[idx][i - 1][j - 1];
            }
            for (int j = 4; j <= m; ++j) {
                tmp[i][j] = tmp[i][j - 3];
            }
        }
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                tmp[i][j] = tmp[i - 3][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sm[idx][i][j] = sm[idx][i - 1][j] + sm[idx][i][j - 1] -
                                sm[idx][i - 1][j - 1];
                if (tmp[i][j] != str[i][j]) {
                    sm[idx][i][j] += 1;
                }
            }
        }
        // for(int i=1;i<=6;i++) std::cout << tmp[i].substr(1) << std::endl;
        // std::cout << std::endl;
    }
    while (q--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int mi = 1'000'000;
        if (x2 - x1 == 1 and y2 - y1 == 1) {
            if (str[x1][y1] == str[x2][y2] and str[x2][y1] == str[x1][y2] and
                str[x1][y1] != str[x2][y1]) {
                    mi = 0;
            }
        }
        for (int idx = 0; idx < 12; ++idx) {
            mi =
                std::min(mi, sm[idx][x2][y2] - sm[idx][x2][y1 - 1] -
                                 sm[idx][x1 - 1][y2] + sm[idx][x1 - 1][y1 - 1]);
        }
        std::cout << mi << "\n";
    }

    return 0;
}