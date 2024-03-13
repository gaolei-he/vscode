#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l = -1, r = -1;
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    std::set<int> d, f;
    for(auto &x : a) {
        std::cin >> x;
    }
    while(m --) {
        int x;
        std::cin >> x;
        d.insert(x);
    }
    while(k --) {
        int x;
        std::cin >> x;
        f.insert(x);
    }
    int idx = -1;
    for(int i=0;i<n-1;i++) {
        if(a[i + 1] - a[i] > r - l) {
            idx = i;
            r = a[i + 1];
            l = a[i];
        }
    }
    // std::cerr << r << " " << l << "\n";
    int tmp_l = l, tmp_r = r;
    for(auto x : d) {
        int a, b;
        if((r - l) % 2 == 0) {
            a = b = (r - l) / 2 + l;
        } else {
            a = (r - l) / 2 + l;
            b = a + 1;
        }
        int target = b - x;
        auto it = f.lower_bound(target);
        if(it != f.end()) {
            if(*it + x - l < tmp_r - tmp_l) {
                tmp_r = *it + x;
                tmp_l = l;
            }
        }
        target = a - x;
        it = f.upper_bound(target);
        if(it != f.begin()) {
            -- it;
            if(r - *it - x < tmp_r - tmp_l) {
                tmp_r = r;
                tmp_l = *it + x;
            }
        }

    }
    // std::cerr << tmp_r << " " << tmp_l << "\n";
    for(int i=0;i<n-1;i++) {
        if(i == idx) {
            continue;
        }
        if(a[i + 1] - a[i] > tmp_r - tmp_l) {
            tmp_r = a[i + 1];
            tmp_l = a[i];
        }
    }
    std::cout << tmp_r - tmp_l << "\n";
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