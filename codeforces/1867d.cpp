#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> g(n);
    std::vector<int> deg(n);
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::function<int(int)> find = [&](int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    bool special = false;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x -= 1;
        if(k == 1 and x != i) {
            special = true;
        }
        g[i].emplace_back(x);
        p[find(x)] = find(i);
        deg[x] += 1;
    }
    if(special) {
        std::cout << "NO\n";
        return;
    }
    std::map<int, int> mp;

    std::queue<int> q;
    for(int i=0;i<n;i++) {
        mp[find(i)] += 1;
        if(!deg[i]) {
            q.push(i);
        }
    }
    while(q.size()) {
        auto ver = q.front();
        mp[find(ver)] -= 1;
        q.pop();
        for(auto v : g[ver]) {
            deg[v] -= 1;
            if(!deg[v]) {
                q.push(v);
            }
        }
    }
    for(auto [t, v] : mp) {
        if(v != 0 and v != k) {
            std::cout << "NO\n";
            return;
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