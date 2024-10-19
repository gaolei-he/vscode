#include <bits/stdc++.h>
#define int long long
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g(n + 1);
    std::set<int> st;
    for(int i=1;i<=n;i++) {
        st.insert(i);
    }
    for(int i=1;i<=n;i++) {
        int x;
        std::cin >> x;
        g[i] = x;
    }
    std::vector<int> dp(n + 1, 0);
    std::vector<bool> vis(n + 1, false);
    int idx = 0;
    std::map<int, int> mp;
    bool flag = false;
    int tag = -1, val = -1;
    std::function<int(int)> dfs = [&](int ver) {
        if(mp.count(ver)) {
            flag = true;
            tag = ver;
            val = idx - mp[ver] + 1;
        } else {
            mp[ver] = ++idx;
        }
        if(vis[ver]) {
            return dp[ver];
        }

        vis[ver] = true;
        dfs(g[ver]);
        if(flag) {
            dp[ver] = val;
        } else {
            dp[ver] = dp[g[ver]] + 1;
        }
        idx --;
        mp.erase(ver);
        if(!mp.count(tag)) {
            flag = false;
            tag = val = -1;
        }
        return dp[ver];
    };
    for(int i=1;i<=n;i++) {
        mp.clear();
        flag = false;
        dfs(i);
    }
    // for(auto x : dp) {std::cerr << x << " ";}
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}