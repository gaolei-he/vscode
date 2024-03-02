#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::string> str(n);
    for (auto& s : str) {
        std::cin >> s;
    }

    auto move = [&](int op, int z) {
        z -= 1;
        if (op == 1) {
            str[z] = str[z].back() + str[z];
            str[z].pop_back();
        } else if (op == 2) {
            char op = str[n - 1][z];
            for (int i = n - 2; i >= 0; --i) {
                str[i + 1][z] = str[i][z];
            }
            str[0][z] = op;
        }
    };

    int p, q;
    std::cin >> p >> q;
    std::vector<std::pair<int, int>> vec(q);
    for (auto& [x, y] : vec) {
        std::cin >> x >> y;
    }
    while (p--) {
        for (auto& [op, z] : vec) {
            move(op, z);
            // for (auto& s : str) {
            //     std::cerr << s << std::endl;
            // }
            // std::cerr << std::endl;
        }
    }
    std::cout << str[x - 1][y - 1] << '\n';

    return 0;
}