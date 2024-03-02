#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, S, k;
    std::cin >> n >> S >> k;
    std::vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.emplace_back(2);
        ans.emplace_back(1);
        S -= 3;
    }
    if (k) {
        ans.emplace_back(2);
        S -= 2;
    }
    int cnt = n - ans.size();
    for (int i = 0; i < cnt; i++) {
        ans.emplace_back(1);
        S -= 1;
    }
    if (ans.size() != n or S < 0) {
        std::cout << "-1\n";
        return;
    }
    if (k * 2 + 1 < n) {
        for (int i = n - 1; i >= 0; --i) {
            if (i == 0) {
                ans[i] += S;
                S = 0;
                break;
            } else if (ans[i - 1] == 2) {
                ans[i] += S;
                S = 0;
                break;
            }
        }
    } else if (k and k * 2 + 1 == n) {
        int val = S / (k + 1);
        S -= val * (k + 1);
        if (S / k <= val) {
            for (auto &x : ans) {
                if (x == 2) {
                    x += val;
                } else {
                    x += std::min(val, S);
                    S -= std::min(val, S);
                }
            }
        } else {
            std::cout << "-1\n";
            return;
        }
    } else if (k == 0) {
        ans.front() += S;
        S -= S;
    }
    if (S) {
        std::cout << "-1\n";
        return;
    }

    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}