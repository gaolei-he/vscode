#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> vec[i];
    }
    std::vector<std::array<int, 3>> vec1;
    for (int i = 0; i < m; i++) {
        int d, s, t;
        std::cin >> d >> s >> t;
        vec1.push_back({d, s, t});
    }
    int l = 1, r = m + 1;
    auto check = [&](int mid) {
        std::vector<i64> vec_cha(n + 2);
        for (int i = 1; i <= n; i++) {
            vec_cha[i] += vec[i];
            vec_cha[i + 1] -= vec[i];
        }
        for (int i = 0; i < mid; ++i) {
            auto [d, s, t] = vec1[i];
            vec_cha[s] -= d;
            vec_cha[t + 1] += d;
        }
        for (int i = 1; i <= n; i++) {
            vec_cha[i] += vec_cha[i - 1];
            if (vec_cha[i] < 0) {
                return false;
            }
        }
        return true;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l == m + 1) {
        std::cout << 0 << "\n";
    } else {
        std::cout << "-1\n" << l << "\n";
    }

    return 0;
}