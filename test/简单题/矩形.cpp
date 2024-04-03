#include <bits/stdc++.h>
using i64 = long long;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, d;
    std::cin >> n >> d;
    double k1 = -1, k2 = -1;
    double b1 = d, b2 = 2*n-d;
    double k3 = -1 / k1, k4 = k3;
    double b3 = d, b4 = -d * k4;
    int k;
    std::cin >> k;
    while(k --) {
        int x, y;
        std::cin >> x >> y;
        if (y >= x * k1 + b1 and y <= x * k2 + b2 and y >= x * k4 + b4 and y <= x * k3 + b3) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}