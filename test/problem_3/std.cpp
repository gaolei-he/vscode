#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    int b;
    std::cin >> s >> b;
    i64 a = 0;
    for(auto c : s) {
        a *= 10;
        a += c - '0';
        a %= b;
    }
    std::cout << std::gcd(a, b) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}