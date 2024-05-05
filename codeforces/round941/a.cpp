#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    int cnt = 0;
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x] += 1;
    }
    for (auto [t, x] : mp) {
        cnt += x / k * (k - 1);
        // std::cerr << x << " ";
        pq.push(x % k);
    }
    // std::cerr << "\n";
    while (pq.size()) {
        auto x = pq.top();
        pq.pop();
        // std::cerr << x << " ";
        if (x + cnt >= k) {
            cnt += k - 1;
            cnt -= k - x;
        } else {
            pq.push(x);
            break;
        }
    }
    int ans = 0;
    while (pq.size()) {
        ans += pq.top();
        pq.pop();
    }
    cnt = std::min(cnt, k - 1);
    std::cout << cnt + ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}