#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), c(n), deg(n), ans;
    std::queue<int> q;
    std::vector<bool> vis(n);
    for (auto &x : a) {
        std::cin >> x;
        x -= 1;
        deg[x] += 1;
    }
    for (auto &x : c) {
        std::cin >> x;
    }
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        auto ver = q.front();
        q.pop();
        deg[a[ver]] -= 1;
        ans.push_back(ver);
        vis[ver] = true;
        if (deg[a[ver]] == 0) {
            q.push(a[ver]);
        }
    }
    for (int i = 0; i < n; i++) {
        auto ver = i;
        std::vector<int> tmp;
        if (vis[ver]) {
            continue;
        }
        for (bool flag = vis[ver]; !flag;) {
            tmp.emplace_back(ver);
            vis[ver] = true;
            ver = a[ver];
            flag = vis[ver];
        }
        int p = std::min_element(tmp.begin(), tmp.end(),
                                 [&](int a, int b) { return c[a] < c[b]; }) -
                tmp.begin();
        for (int i = 0; i < tmp.size(); i++) {
            ans.push_back(tmp[(i + p + 1) % tmp.size()]);
        }
    }
    for (auto x : ans) {
        std::cout << x + 1 << " \n"[x == ans.back()];
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
