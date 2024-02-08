#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> vec(n);
    for (auto &x : vec) std::cin >> x;

    std::map<int, int> mp;
    int c4 = 0, c8 = 0;
    int c2 = 0, c6 = 0;
    for (auto x : vec) {
        if (x == 4) c4++;
        if (x == 8) c8++;
        if (x == 2) c2++;
        if (x == 6) c6++;
        int val = 0;
        while (x) {
            val += x % 10;
            x /= 10;
        }
        x = val % 9;
        mp[x]++;
    }

    i64 ans = 0;
    for (auto x : vec) {
        if (x % 4 == 0 and x > 10) {
            int val = 0;
            while (x) {
                val += x % 10;
                x /= 10;
            }
            x = val % 9;
            ans += mp[9 - x];
            if (!x) ans += mp[0] - 1;
        }
    }

    for (auto x : vec) {
        i64 tmp = x;
        for (int d = 2; d <= 8; d += 2) {
            // std::cerr << x << ' ' << d << std::endl;
            x = tmp;
            int val = d;
            if ((x % 10 * 10 + d) % 4 != 0) continue;
            while (x) {
                val += x % 10;
                x /= 10;
            }
            if (val % 9 != 0) continue;
            if (d == 2) ans += c2;
            if (d == 4) ans += c4;
            if (d == 6) ans += c6;
            if (d == 8) ans += c8;
        }
    }

    std::cout << ans;

    return 0;
}