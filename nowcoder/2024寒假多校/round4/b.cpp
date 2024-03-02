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
        sm += x - 1;
    }
    if (sm & 1) {
        std::cout << "gui\n";
    } else {
        std::cout << "sweet\n";
    }

    return 0;
}