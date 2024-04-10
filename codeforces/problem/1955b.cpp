#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, c, d;
    std::cin >> n >> c >> d;
    std::map<int, int> mp;
    for (int i = 0; i < n * n; i++) {
        int key;
        std::cin >> key;
        mp[key] += 1;
    }
    auto st = mp.begin()->first;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int key = st + i * c + j * d;
            if (mp.count(key)) {
                mp[key] -= 1;
                if (mp[key] == 0) {
                    mp.erase(key);
                }
            } else {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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