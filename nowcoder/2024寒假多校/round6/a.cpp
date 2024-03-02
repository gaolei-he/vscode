#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, r;
    std::cin >> l >> r;
    std::unordered_map<int, int> mp;

    auto check = [&](int x) {
        mp.clear();
        for(int i=2;i<=x/i;++i) {
            while(x % i == 0) {
                mp[i] += 1;
                x /= i;
            }
        }
        if (x > 1) {
            mp[x] += 1;
        }
        bool res = true;
        if (mp.size() != 3) res = false;
        for (auto [k, v] : mp) {
            if(v != 1) {
                res = false;
            }
        }
        return res;
    };

    for (int i=l;i<=r;++i) {
        if(check(i)) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}