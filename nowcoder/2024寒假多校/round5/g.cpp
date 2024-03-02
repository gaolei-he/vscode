#include <bits/stdc++.h>

using i64 = long long;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(i + j + 2)) {
                g[i].emplace_back(j);
            }
        }
    }
    // for (auto &vec : g) {
        // for (auto &x : vec) std::cout << x + 1 << ' ';
        // std::cout << std::endl;
    // }
    std::vector<int> match(n, -1);
    std::vector<bool> st(n, false);
    std::function<bool(int)> find = [&](int x) {
        for (auto j : g[x]) {
            if (!st[j]) {
                st[j] = true;
                if (match[j] == -1 or find(match[j])) {
                    match[j] = x;
                    return true;
                }
            }
        }
        return false;
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
        st.assign(n, false);
        if (find(i)) {
            res += 1;
        }
    }
    // for(auto x : match) std::cerr << x << ' ';
    // std::cerr << res << ' ' << n << std::endl;
    if (res != n) {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (auto x : match) {
        std::cout << x + 1 << " \n"[x == match.back() ? 1 : 0];
    }
    return 0;
}
// 11 * 12 
/*
1 2 3 4 5 6 7 8 9 10 11
10 9 8 7 
*/