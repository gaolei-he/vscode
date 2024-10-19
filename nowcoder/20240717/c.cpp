#include <bits/stdc++.h>
#define int long long
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> match(n + 1);
    for(int i=1;i<=n;i++) {
        int k;
        std::cin >> k;
        while(k --) {
            int x;
            std::cin >> x;
            g[i].push_back(x);
        }
    }
    int res = 0;
    std::vector<bool> vis(n + 1, false);
    std::function<bool(int)> find = [&](int ver) {
        for(auto x : g[ver]) {
            if(!vis[x]) {
                vis[x] = true;
                if(match[x] == 0 || find(match[x])) {
                    match[x] = ver;
                    return true;
                }
            }
        }
        return false;
    };
    for(int i=1;i<=n;i++) {
        vis.assign(n + 1, false);
        if(find(i)) {
            res += 1;
        }
    }
    if(res == n) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n" << n - res << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}