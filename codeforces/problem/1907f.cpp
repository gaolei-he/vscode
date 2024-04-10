#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    auto check = [&](int idx, int step) {
        int lst = vec[idx];
        int tmp = idx;
        do {
            if (vec[idx] < lst) {
                return false;
            }
            lst = vec[idx];
            idx += step + n;
            idx %= n;
        } while (idx != tmp);
        return true;
    };
    int mi = 1'000'000'010, idx = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        int x = vec[i];
        if (x < mi) {
            mi = x;
            idx = i;
        }
    }
    for (int i=0;i<n;i++) {
        if(vec[i] == mi and vec[(i-1+n)%n] > vec[i]) {
            idx = i;
        }
    }
    
    int ans = 1'000'000'010;
    if (check(idx, 1)) {
        ans = std::min(ans, (n - idx) % n);
        ans = std::min((n - (n - idx) % n) + 2, ans);
    }
    mi = 1'000'000'010, idx = -1;
    for (int i = 0; i < n; i++) {
        if (vec[i] <= mi) {
            mi = vec[i];
            idx = i;
        }
    }
    for(int i=0;i<n;i++) {
        if(vec[i] == mi and vec[(i+1)%n] > vec[i]) {
            idx = i;
        }
    }
    if (check(idx, -1)) {
        ans = std::min(ans, (n - idx));
        ans = std::min(ans, (n - (n - idx) + 2));
    }
    if(ans > 1'000'000'000) {
        ans = -1;
    }
    std::cout << ans << "\n";
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