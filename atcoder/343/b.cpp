#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=1;j<=n;j++) {
            int x;
            std::cin >> x;
            if(x) {
                std::cout << j << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}