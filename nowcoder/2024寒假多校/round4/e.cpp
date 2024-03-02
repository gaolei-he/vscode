#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::set<int> S{0};
    i64 sm = 0;
    int ans = 0;
    while(n --) {
        int x;
        std::cin >> x;
        sm += x;
        if(S.count(sm % k)) {
            S.clear();
            S.insert(0);
            ans += 1;
            sm = 0;
        } else {
            S.insert(sm % k);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}