#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        mp[x] += 1;
    }
    bool flag = false;
    for(int i=0;i<n;i++) {
        if(!mp.count(i) or mp[i] == 1 and flag) {
            std::cout << i << "\n";
            return;
        } else if(mp[i] == 1 and !flag) {
            flag = true;
        }
    }
    std::cout << n << "\n";
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