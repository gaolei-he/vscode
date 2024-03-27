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
        // 奇数，并且不存在奇数环
        total1 = total2 = 0;
        if (dfs(x, 1) and total1 != total2) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}