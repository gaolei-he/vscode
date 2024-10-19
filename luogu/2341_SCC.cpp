#include <bits/stdc++.h>

std::vector<int> dfn, low, id, sz;// id 节点i所在SCC编号
std::vector<std::vector<int>> g;
std::stack<int> stk;
std::vector<bool> in_stk;
int timestamp = 0, scc_cnt = 0;
void tarjan(int u) {
    dfn[u] = low[u] = ++ timestamp;
    stk.push(u), in_stk[u] = true;
    for(auto x : g[u]) {
        if(!dfn[x]) {
            tarjan(x);
            low[u] = std::min(low[u], low[x]);
        } else if(in_stk[x]) {
            low[u] = std::min(low[u], dfn[x]);
        }
    }

    if(dfn[u] == low[u]) {
        int y;
        ++ scc_cnt;
        do {
            y = stk.top();
            stk.pop();
            in_stk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt] ++;
        } while(y != u);
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    dfn.resize(n + 1);
    low.resize(n + 1);
    id.resize(n + 1);
    sz.resize(n + 1);
    g.resize(n + 1);
    in_stk.resize(n + 1);

    for(int i=0;i<m;i++) {
        int a, b;
        std::cin >> a >> b;
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(!id[i]) {
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++) {
        // std::cerr << id[i] << " ";
    }
    std::vector<int> deg(scc_cnt + 1);
    for(int i = 1;i<=n;i++) {
        for(auto j : g[i]) {
            if(id[i] != id[j]) {
                deg[id[j]] += 1;
            }
        }
    }
    int val = -1;
    for(int i=1;i<=scc_cnt;i++) {
        if(!deg[i] and val != -1) {
            std::cout << 0 << "\n";
            return;
        } else if(!deg[i]) {
            val = sz[i];
        }
    }
    std::cout << val << "\n";

}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}