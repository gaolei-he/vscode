#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> B(n);
    i64 smax = 0, smin = 0;
    for (auto &x : B) {
        std::cin >> x;
        smax += x;
    }
    std::sort(B.begin(), B.end());
    B.erase(std::unique(B.begin(), B.end()), B.end());
    for (auto x : B) {
        smin += x;
    }
    std::cout << smax << "\n" << smin << "\n";

    return 0;
}