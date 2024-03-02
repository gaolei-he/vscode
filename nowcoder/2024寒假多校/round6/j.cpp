#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::unordered_set<int>> g1(n + 1), g2(n + 1);
    for (int i = 1; i < n; ++i) {
        int x;
        std::cin >> x;
        g1[x].emplace(i + 1);
    }
    g1[0].emplace(1);
    std::function<void(int, int)> dfs1 = [&](int fa, int ver) {
        if (g1[ver].empty() and s[ver - 1] == 'R') {
            std::cout << -1 << std::endl;
            exit(0);
        }
        for (auto v : g1[ver]) {
            if (s[v - 1] == 'R' and s[ver - 1] == 'R') {
                std::cout << -1 << std::endl;
                exit(0);
            }
            if (s[v - 1] == 'R') {
                g2[fa].emplace(v);
                dfs1(v, v);
            } else {
                dfs1(fa, v);
            }
        }
    };
    dfs1(0, 0);
    std::vector<int> ans(n + 1);
    std::vector<int> points;
    std::function<void(int)> dfs3 = [&](int ver) {
        points.emplace_back(ver);
        for (auto v : g1[ver]) {
            if (s[v - 1] != 'R') {
                dfs3(v);
            }
        }
    };
    auto work = [&](int ver) {
        points.clear();
        dfs3(ver);
        // std::cerr << points.size() << ' ' << ver << "\n";
        std::vector<int> vals;
        if (points.size() % 3 == 0) {
            vals.assign(points.size(), 1);
        } else if (points.size() % 3 == 1) {
            vals.assign(points.size() - 4, 1);
            vals.emplace_back(1);
            vals.emplace_back(1);
            vals.emplace_back(2);
            vals.emplace_back(2);
        } else if (points.size() % 3 == 2) {
            vals.assign(points.size() - 2, 1);
            vals.emplace_back(1);
            vals.emplace_back(2);
        }

        for (auto x : points) {
            ans[x] = vals.back();
            vals.pop_back();
        }
    };
    std::function<void(int)> dfs2 = [&](int ver) {
        for (auto v : g2[ver]) {
            dfs2(v);
            work(v);
        }
    };
    // for(int i=0;i<=n;i++) {
    //     std::cerr << i << " ";
    //     for(auto x : g2[i]) std::cerr << x << ' ';
    //     std::cerr << "\n";
    // }
    dfs2(0);

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0) {
            ans[i] = 1;
        }
        std::cout << ans[i];
    }

    return 0;
}