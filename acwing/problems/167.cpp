#include <bits/stdc++.h>

using i64 = long long;

void solve(int n) {
    std::vector<int> vec(n);
    int st = -1, ed = 0;
    for (auto &x : vec) {
        std::cin >> x;
        st = std::max(st, x);
        ed += x;
    }
    std::sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
    std::vector<bool> vis(n);
    std::function<bool(int, int, int, int)> dfs = [&](int len, int u, int s,
                                                      int idx) {
        if (s == len) u += 1, s = 0, idx = 0;
        if (u * len == ed) {
            return true;
        }

        int lst = -1;
        bool res = false;
        for (int i = idx; i < n; i++) {
            if (!vis[i] and vec[i] + s <= len) {
                if(vec[i] == lst) {
                    continue;
                }
                lst = vec[i];
                vis[i] = true;
                res = res or dfs(len, u, s + vec[i], i + 1);
                vis[i] = false;
                if (res) {
                    return res;
                } else if (s == 0) {
                    return false;
                } else if (s + vec[i] == len) {
                    return false;
                }
            }
        }
        return false;
    };

    for (int i = st; i <= ed; i++) {
        if (ed % i) {
            continue;
        }
        if (dfs(i, 0, 0, 0)) {
            std::cout << i << "\n";
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n) {
        if (!n) {
            break;
        }
        solve(n);
    }

    return 0;
}
