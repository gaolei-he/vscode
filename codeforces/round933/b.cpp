#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for(auto &x : vec) {
        std::cin >> x;
    }
    for(int i=0;i<n-2;i++) {
        if(vec[i] < 0) {
            std::cout << "NO\n";
            return;
        }
        vec[i + 1] -= vec[i] * 2;
        vec[i + 2] -= vec[i];
        vec[i] -= vec[i];
    }
    if(vec[n - 2] != 0 or vec[n-1] != 0) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}