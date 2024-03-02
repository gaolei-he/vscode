#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<std::vector<int>> count(10001);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        count[vec[i]].emplace_back(i);
    }

    int mx = 0, p = 1;
    for (int i = 0; i < n;) {
        while (i < n and !vec[i]) {
            i += 1;
        }
        bool flag = false;
        while (i < n and vec[i]) {
            i += 1;
            flag = true;
        }
        if (flag) {
            mx += 1;
        }
    }
    int lst = mx;
    for (int i = 1; i <= 10000; ++i) {
        int tmp = lst;
        for (auto x : count[i]) {
            vec[x] = 0;
            if (x > 0 and x < n - 1) {
                if (vec[x - 1] and vec[x + 1]) {
                    tmp += 1;
                } else if (!vec[x - 1] and !vec[x + 1]) {
                    tmp -= 1;
                }
            } else if (x == 0) {
                if (!vec[x + 1]) {
                    tmp -= 1;
                }
            } else if (x == n - 1) {
                if (!vec[x - 1]) {
                    tmp -= 1;
                }
            }
        }
        lst = tmp;
        // std::cerr << tmp << std::endl;
        if (tmp > mx) {
            mx = tmp;
            p = i + 1;
        }
    }

    std::cout << mx << std::endl;

    return 0;
}