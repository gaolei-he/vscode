#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (auto &x : c) {
        std::cin >> x;
    }
    int k;
    std::cin >> k;
    std::map<int, int> mp;
    std::map<int, int> tmp;
    std::deque<std::pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        tmp[c[i]] = i;
    }
    for (auto [k, v] : tmp) {
        while (q.size() and q.back().first > k) {
            q.pop_back();
        }
        if (q.size() and q.back().second > v) {
            continue;
        }
        q.emplace_back(k, v);
    }
    int val = k / tmp.begin()->first;
    k -= val * tmp.begin()->first;
    if (val) {
        mp[tmp.begin()->first] = val;
    }
    auto it = mp.begin();
    while (it != mp.end() and mp.size()) {
        while (q.size() and it->first >= q.front().first) {
            q.pop_front();
        }
        if (q.empty()) {
            break;
        }
        val = it->first;
        int val1 = q.front().first;
        if (k + val >= val1) {
            k = k + val - val1;
            mp[val] -= 1;
            mp[val1] += 1;
            if (mp[val] == 0) {
                ++it;
            }
        } else {
            ++it;
        }
    }
    std::vector<int> ans(n);
    for (auto [k, v] : mp) {
        int idx = tmp[k];
        ans[idx] += v;
    }
    for (int i = n - 2; i >= 0; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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