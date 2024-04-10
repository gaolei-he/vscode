#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> vec(n);
    std::vector<int> rec(n);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    for(int i=0;i<n;i++) {
        std::cin >> vec[i];
        pq.push({vec[i], -i});
    }
    while(k) {
        auto p = pq.top();
        pq.pop();
        // std::cout << p.first << " " << p.second << "\n";
        rec[-p.second]= std::min(k, m);
        k -= rec[-p.second];
    }
    i64 ans = 0, money = 0;
    for(int i=0;i<n;i++) {
        ans += rec[i] * (vec[i] + money);
        money += rec[i];
    }
    std::cout << ans << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}