#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    while (n--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int ans = 0;
        ans += (a - 100) / 50;
        if (b == 45) {
            ans += 2;
        } else if (b >= 34) {
            ans += 1;
        }

        if (c == 45) {
            ans += 2;
        } else if (c >= 34) {
            ans += 1;
        }
        std::cout << ans << "\n";
    }

    return 0;
}