#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, L;
    std::cin >> n >> m >> L;
    std::vector<int> h(L);
    for(int i=0;i<n*m;++i) {
        int x;
        std::cin >> x;
        h[x] += 1;
    }
    for(auto x : h) {
        std::cout << x << ' ';
    }

    return 0;
}