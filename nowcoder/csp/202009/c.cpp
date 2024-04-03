#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::string> func;
    std::vector<int> deg(N + M); // 拓扑排序判环用
    // [0, M)为信号，[M, N)为逻辑门
    std::vector<std::vector<int>> g(N + M);
    for(int i=0;i<N;i++) {
        std::string s;
        int k;
        std::cin >> s >> k;
        func.emplace_back(s);
        for(int j=0;j<k;j++) {
            std::cin >> s;
            int ver = std::stoi(s.substr(1)) - 1;
            if(s[0] == 'I') {
                g[i + M].push_back(ver);
                deg[ver] += 1;
            } else {
                g[i + M].push_back(ver + M);
                deg[ver + M] += 1;
            }
        }
    }

    int S;
    std::cin >> S;
    std::vector<std::vector<int>> query;
    for(int i=0;i<S;i++) {
        query.push_back({});
        for(int j=0;j<M;j++) {
            int x;
            std::cin >> x;
            query.back().push_back(x);
        }
    }
    for(int i=0;i<S;i++) {
        query.push_back({});
        int cnt;
        std::cin >> cnt;
        for(int j=0;j<cnt;j++) {
            int idx;
            std::cin >> idx;
            idx = idx - 1 + M;
            query.back().push_back(idx);
        }
    }
    auto top_sort = [&]() {
        std::queue<int> q;
        for(int i=0;i<M+N;i++) {
            if(!deg[i]) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(q.size()) {
            auto t = q.front();
            cnt += 1;
            q.pop();
            for(auto x : g[t]) {
                deg[x] -= 1;
                if(!deg[x]) {
                    q.push(x);
                }
            }
        }
        return cnt != N + M;
    };
    if(top_sort()) {
        std::cout << "LOOP\n";
        return;
    }


    std::vector<int> ans(M + N, -1);
    std::function<int(int)> dfs = [&](int ver) {
        if(ans[ver] != -1) {
            return ans[ver];
        }
        if(func[ver - M] == "NOT") {
            dfs(g[ver].front());
            if(ans[g[ver].front()] == 0) {
                return ans[ver] = 1;
            } else {
                return ans[ver] = 0;
            }
        } else if(func[ver - M] == "AND") {
            for(auto x : g[ver]) {
                int tmp = dfs(x);
                if(tmp == 0) {
                    return ans[ver] = 0;
                }
            }
            return ans[ver] = 1;
        } else if(func[ver - M] == "OR") {
            for(auto x : g[ver]) {
                int tmp = dfs(x);
                if(tmp == 1) {
                    return ans[ver] = 1;
                }
            }
            return ans[ver] = 0;
        } else if(func[ver - M] == "XOR") {
            int res = 0;
            for(auto x : g[ver]) {
                res ^= dfs(x);
            }
            return ans[ver] = res;
        } else if(func[ver - M] == "NAND") {
            for(auto x : g[ver]) {
                int tmp = dfs(x);
                if(tmp == 0) {
                    return ans[ver] = 1;
                }
            }
            return ans[ver] = 0;
        } else if(func[ver - M] == "NOR") {
            for(auto x : g[ver]) {
                int tmp = dfs(x);
                if(tmp == 1) {
                    return ans[ver] = 0;
                }
            }
            return ans[ver] = 1;
        }
        return 0;
    };

    for(int i=0;i<S;i++) {
        ans.assign(M + N, -1);
        for(int j=0;j<M;j++) {
            ans[j] = query[i][j];
        }
        for(auto x : query[i + S]) {
            if(ans[x] == -1) {
                ans[x] = dfs(x);
            }
        }
        for(auto x : query[i + S]) {
            std::cout << ans[x] << " \n"[x == query[i + S].back()];
        }
    }
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