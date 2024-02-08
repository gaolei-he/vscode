#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    if (s.front() >= 'a') s.front() -= 'a' - 'A';
    if (t.front() >= 'a') t.front() -= 'a' - 'A';

    std::cout << (s.front() == t.front() ? "Yes\n" : "No\n");
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