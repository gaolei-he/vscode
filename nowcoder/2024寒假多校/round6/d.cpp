#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double p;
    std::cin >> p;
    std::cout << std::fixed << std::setprecision(8)
              << pow(p, 2) * pow((1 - p), 3) + pow(p, 3) * pow((1 - p), 2)
              << std::endl;
    return 0;
}