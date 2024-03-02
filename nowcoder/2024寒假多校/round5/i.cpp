#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, a, k;
    std::cin >> t >> a >> k;

    if (t <= a) {
        if (t >= 0) {
            std::cout << a + a - t << std::endl;
        } else if (t < 0) {
            if (a >= 0) {
                if (k >= a) {
                    std::cout << std::min(-t + 2ll * a, -2ll * t + a - t + a)
                              << std::endl;
                } else if (k < a) {
                    std::cout << -t * 2ll + a - t + a << std::endl;
                }
            } else if (a < 0) {
                std::cout << -t << std::endl;
            }
        }
    } else if (t > a) {
        if (a >= 0) {
            std::cout << t << std::endl;
        } else if (a < 0) {
            if (t <= 0) {
                std::cout << -a - a + t << std::endl;
            } else if (t > 0) {
                if (k >= -a) {
                    std::cout << std::min(t * 2ll - a - a + t, -2ll * a + t)
                              << std::endl;
                } else if (k < -a) {
                    std::cout << t * 2ll - a - a + t << std::endl;
                }
            }
        }
    }
    return 0;
}