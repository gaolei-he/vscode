#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> vec(n + 1);
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        std::cin >> vec[i];
        if(vec[i] == x) {
            idx = i;
        }
    }
    int l = 1, r = n + 1;
    std::unordered_set<int> record;
    while (true) {
        if (r - l == 1) break;
        int m = r + l >> 1;
        record.emplace(m);
        if (vec[m] <= x)
            l = m;
        else
            r = m;
    }
    if(vec[l] == x) {
        std::cout << 0 << "\n";
        return;
    } else if(!record.count(idx) or vec[l] <= idx) {
        std::cout << 1 << "\n";
        std::cout << l << " " << idx << "\n";
    } else {
        std::cout << 2 << "\n";
        std::cout << l << " " << idx << "\n";
        for(int i=1;i<=n;i++) {
            if(vec[i] < x and !record.count(i)) {
                std::cout << i << " " << idx << "\n";
                break;
            }
        }
    }

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