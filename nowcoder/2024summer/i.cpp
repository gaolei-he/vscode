#include <bits/stdc++.h>
#define int long long
using ar5 = std::array<int, 5>;
using ar3 = std::array<int, 3>;
// 0 1 2 3 above below left right
const int above = 0, below = 1, left = 2, right = 3;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> str(n);
    for (auto &s : str) {
        std::cin >> s;
    }
    std::vector<std::vector<ar5>> ans(n, std::vector<ar5>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = {-1, -1, -1, -1};
        }
    }
    bool flag = false;
    std::vector<ar3> vec;
    std::unordered_set<std::string> st;
    std::function<int(int, int, int)> dfs = [&](int x, int y, int idx) -> int {
        // std::cerr << x << " " << y << " " << idx << "\n";
        if (x < 0 or x >= n or y < 0 or y >= m) {
            return 0ll;
        }
        if (ans[x][y][idx] != -1) {
            return ans[x][y][idx];
        }
        if (vec.size() and vec.front() == (ar3){x, y, idx}) {
            flag = true;
            return (int)vec.size();
        }
        vec.push_back({x, y, idx});

        int tx, ty, tidx;
        if (str[x][y] == '/') {
            if (idx == 0) {
                tx = x, ty = y - 1, tidx = 3;
            } else if (idx == 1) {
                tx = x, ty = y + 1, tidx = 2;
            } else if (idx == 2) {
                tx = x - 1, ty = y, tidx = 1;
            } else if (idx == 3) {
                tx = x + 1, ty = y, tidx = 0;
            }
        } else if (str[x][y] == '\\') {
            if (idx == 0) {
                tx = x, ty = y + 1, tidx = 2;
            } else if (idx == 1) {
                tx = x, ty = y - 1, tidx = 3;
            } else if (idx == 2) {
                tx = x + 1, ty = y, tidx = 0;
            } else if (idx == 3) {
                tx = x - 1, ty = y, tidx = 1;
            }
        } else if (str[x][y] == '|') {
            if (idx == 0) {
                tx = x + 1, ty = y, tidx = idx;
            } else if (idx == 1) {
                tx = x - 1, ty = y, tidx = idx;
            } else if (idx == 2) {
                tx = x, ty = y - 1, tidx = 3;
            } else if (idx == 3) {
                tx = x, ty = y + 1, tidx = 2;
            }
        } else if (str[x][y] == '-') {
            if (idx == 0) {
                tx = x - 1, ty = y, tidx = 1;
            } else if (idx == 1) {
                tx = x + 1, ty = y, tidx = 0;
            } else if (idx == 2) {
                tx = x, ty = y + 1, tidx = idx;
            } else if (idx == 3) {
                tx = x, ty = y - 1, tidx = idx;
            }
        }
        ans[x][y][idx] = dfs(tx, ty, tidx);
        if (!flag) {
            st.insert({std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(idx)});
            ans[x][y][idx] += 1;
        }
        return ans[x][y][idx];
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                flag = false;
                vec.clear();
                dfs(i, j, k);
                // std::cerr << "\n";
            }
        }
    }
    // std::cout << ans[0][0][3] << "#\n";
    int q;
    std::cin >> q;
    std::map<std::string, int> dict = {
        {"above", above}, {"below", below}, {"right", right}, {"left", left}};
    
    std::cout << ans[1][1][1] << "\n";
    while (q--) {
        int u, v;
        std::string dir;
        std::cin >> u >> v >> dir;
        u --, v --;
        int val = ans[u][v][dict[dir]];
        std::string key = std::to_string(u) + " " + std::to_string(v) + " " + std::to_string(dict[dir]);
        
        // std::cout << val << "\n";
        // std::cout << ans[0][1][2] << "\n";
        int tu, tv;
        if(dir == "below") {
            tv = v;
            tu = u + 1;
            val = dfs(tu, tv, 0);
        } else if(dir == "above") {
            tu = u - 1;
            tv = v;
            val = dfs(tu, tv, 1);
        } else if(dir == "left") {
            tv = v - 1;
            tu = u;
            val = dfs(tu, tv, 3);
        } else if(dir == "right") {
            tv = v + 1;
            tu = u;
            val = dfs(tu, tv, 2);
        }
        if(st.count(key)) {
            val -= 1;
        }
        std::cout << val << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}