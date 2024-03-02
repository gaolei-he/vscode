#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
    vec.push_back(0);

    std::sort(vec.begin(), vec.end());

    std::vector<i64> sm(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sm[i] += sm[i - 1] + vec[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sm[n] - vec[i];
        ans += vec[i] * 1ll * (n - 1);
        ans += sm[n] - sm[i];
        ans -= vec[i] * 1ll * (n - i);
        ans += vec[i] * 1ll * (i - 1);
        ans -= sm[i - 1];
    }

    std::cout << ans << "\n";
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