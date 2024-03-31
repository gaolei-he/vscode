#include <bits/stdc++.h>

using i64 = long long;
std::vector<int> vec;

void solve() {
    int n;
    std::cin >> n;
    bool ans = false;
    std::function<void(int)> dfs = [&](int val) {
        if(val == n) {
            ans = true;
        }
        if(ans) {
            return;
        }
        for(auto x : vec) {
            if(x * val > n) {
                break;
            }
            dfs(x * val);
        }
    };
    dfs(1);
    if(ans) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int op = 2; op <= (1 << 5); op++) {
        int x = 0, tmp = op;
        for (int j = 5; j >= 0; j--) {
            x *= 10;
            x += ((op >> j) & 1);
        }
        vec.push_back(x);
    }

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}