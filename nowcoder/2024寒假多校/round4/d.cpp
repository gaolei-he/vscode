#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    i64 sm = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        sm += x;
    }
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    int ans = 0;

    for (int i = 1; sm / i >= n; i++) {
        if (sm % i == 0) {
            ans += 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}