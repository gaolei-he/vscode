#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    std::vector<int> a, b;
    std::set<int> st;

    auto insert = [&](int val) {
        bool res = false;
        std::vector<int> tmp;
        for (int i = 2; i <= val / i; ++i) {
            if (val % i == 0 and st.count(i)) {
                res = true;
                tmp.emplace_back(i);
            } else if (val % i == 0) {
                tmp.emplace_back(i);
            }
            while (val % i == 0) {
                val /= i;
            }
        }
        if (val > 1 and st.count(val)) {
            res = true;
            tmp.emplace_back(val);
        } else if (val > 1) {
            tmp.emplace_back(val);
        }
        if (res) {
            for (auto x : tmp) {
                st.emplace(x);
            }
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (!i) {
            a.emplace_back(x);
            for (int i = 2; i <= x / i; ++i) {
                while (x % i == 0) {
                    x /= i;
                    st.insert(i);
                }
            }
            if (x > 1) {
                st.insert(x);
            }
        } else {
            mp[x] += 1;
        }
    }
    for (auto x : st) std::cerr << x << ' ';
    while (true) {
        bool flag = false;
        std::vector<int> tmp;
        for (auto& [k, v] : mp) {
            if (insert(k)) {
                while (v--) {
                    a.emplace_back(k);
                }
                flag = true;
                tmp.emplace_back(k);
            }
        }
        for (auto x : tmp) {
            mp.erase(x);
        }
        if (!flag) {
            break;
        }
    }
    for (auto [k, v] : mp) {
        while (v--) {
            b.emplace_back(k);
        }
    }
    if (b.size() and a.size()) {
        std::cout << a.size() << ' ' << b.size() << "\n";
        for (auto x : a) {
            std::cout << x << ' ';
        }
        std::cout << "\n";
        for (auto x : b) {
            std::cout << x << ' ';
        }
        std::cout << "\n";
    } else {
        std::cout << "-1 -1\n";
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