#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (auto &x : a) {
        std::cin >> x;
    }
    for (int i = 0; i < m; i++) {
        int key;
        std::cin >> key;
        mp[key] += 1;
    }
    std::map<int, int> rec;
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        rec[a[i]] += 1;
    }
    for(auto [k, v] : mp) {
        if(rec.count(k)) {
            cnt += std::min(rec[k], v);
        }
    }
    if(cnt >= k) {
        ans += 1;
    }
    for (int i=m;i<n;i++) {
        rec[a[i-m]] -= 1;
        if(mp.count(a[i-m]) and rec[a[i-m]] < mp[a[i-m]]) {
            cnt -= 1;
        }
        rec[a[i]] += 1;
        if(mp.count(a[i]) and rec[a[i]] <= mp[a[i]]) {
            cnt += 1;
        }
        if(cnt >= k) {
            ans += 1;
        }

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