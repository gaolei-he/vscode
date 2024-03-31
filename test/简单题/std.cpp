/*
https://codeforces.com/contest/1949/problem/I
cf原，建无向图，对于任意两个相切的圆之间建一条边
形成n个连通块，对于每个连通块，保证其是二分图，并且染色之后，黑点数量和白点数量不同
简略说明：只有二分图，才可以保证改变圆半径后仍然保持相切，若黑白点数量相同，则半径之和不变
证明略
*/


#include <bits/stdc++.h>
using i64 = long long;
int total1, total2;
std::vector<std::vector<int>> g;
constexpr int N = 1e3+10;
int color[N];
bool dfs(int u, int c)
{
    if(c == 1) {
        total1 ++;
    } else {
        total2 ++;
    }
    color[u] = c;
    for(auto x : g[u])
    {
        int j = x;
        if(!color[j])
        {
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> vec(n);
    for (auto &arr : vec) {
        std::cin >> arr[0] >> arr[1] >> arr[2];
    }
    g.resize(n);
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::function<int(int)> find = [&](int x) {
        return (p[x] == x) ? x : (p[x] = find(p[x]));
    };
    auto check = [&](int i, int j) {
        auto [x1, y1, r1] = vec[i];
        auto [x2, y2, r2] = vec[j];
        return (r1 + r2) * 1ll * (r1 + r2) ==
               (x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2);
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(i, j)) {
                int a = find(i), b = find(j);
                g[i].push_back(j);
                g[j].push_back(i);
                if (a == b) {
                    continue;
                }
                p[b] = a;
            }
        }
    }

    std::unordered_set<int> st;
    for(int i=0;i<n;i++) {
        st.insert(find(i));
    }
    for(auto x : st) {
        total1 = total2 = 0;
        if (dfs(x, 1) and total1 != total2) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}