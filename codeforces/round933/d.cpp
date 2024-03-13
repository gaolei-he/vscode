#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<std::pair<int, int>> vec(m);
    for (auto& [x, y] : vec) {
        char op;
        std::cin >> x >> op;
        if(op == '?') {
            y = 1;
        } else if(op == '0') {
            y = 2;
        } else {
            y = 3;
        }
    }
    std::vector<int> ans;
    std::unordered_map<i64, bool> mp;
    std::function<void(int, int)> dfs = [&](int idx, int who) {
        if(idx == m) {
            ans.push_back(who);
            return;
        }
        if(mp.count(idx * 10ll + who * 100000 + vec[idx].second)) {
            return;
        }
        if(vec[idx].second == 1) {
            dfs(idx + 1, (who + vec[idx].first) % n);
            dfs(idx + 1, (who - vec[idx].first + n) % n);
        } else if(vec[idx].second == 2) {
            dfs(idx + 1, (who + vec[idx].first) % n);
        } else if(vec[idx].second == 3) {
            dfs(idx + 1, (who - vec[idx].first + n) % n);
        }
        mp[idx * 10ll + who * 100000 + vec[idx].second] = true;
    };
    x = (x - 1 + n) % n;
    dfs(0, x);
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    std::cout << ans.size() << "\n";
    for(auto x : ans) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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