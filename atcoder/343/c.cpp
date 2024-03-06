#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;
    i64 ans = 1, val = 2;
    auto check = [&](i64 val) {
        std::string s = std::to_string(val);
        std::string t = s;
        std::reverse(t.begin(), t.end());
        return t == s;
    };
    while (val * val * val <= n) {
        if (check(val * val * val)) {
            ans = val;
        }
        val += 1;
    }
    std::cout << ans * ans * ans << std::endl;

    return 0;
}