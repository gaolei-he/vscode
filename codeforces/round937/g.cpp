#include <bits/stdc++.h>

using i64 = long long;

int lowbit(int x) { return x & (-x); }

void solve() {
    int n;
    std::cin >> n;
    int ans = n;
    int id = 0;
    std::map<std::string, int> mp;
    std::vector<std::pair<int, int>> vec(n);
    for (auto &[x, y] : vec) {
        std::string a, b;
        std::cin >> a >> b;
        if (!mp.count(a)) {
            x = id;
            mp[a] = id++;
        } else {
            x = mp[a];
        }
        if (!mp.count(b)) {
            y = id;
            mp[b] = id++;
        } else {
            y = mp[b];
        }
    }
    std::vector<int> p(40);
    std::function<int(int)> find = [&](int x) {
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    std::vector<std::pair<int, int>> v;
    std::vector<bool> vis;

    std::function<bool(int, int, int)> dfs = [&](int cnt, int v1, int v2) {
        if(cnt == n) {
            return true;
        }
        bool res = false;
        for(int i=0;i<v.size();i++) {
            if(v1 == -1) {
                vis[i] = false;
                res = res or dfs(1, v[i].first, v[i].second);
                vis[i] = true;
            } else if(!vis[i] and (v[i].first == v1 or v[i].first == v2 or v[i].second == v1 or v[i].second == v2)) {
                res = res or dfs(1, v[i].first, v[i].second);
            }
        }
        return res;
    };

    auto check = [&](int op) {
        v.clear();
        for (int i = 0; i < n; i++) {
            if (!((op >> i) & 1)) {
                v.push_back(vec[i]);
            }
        }
        vis.assign(v.size(), false);
        return dfs(0, -1, -1);


    };

    for (int op = 0; op < (1 << n); op++) {
        if (check(op)) {
            int cnt = 0, tmp = op;
            while (tmp) {
                tmp -= lowbit(tmp);
                cnt += 1;
            }
            ans = std::min(ans, cnt);
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