#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> vec(6);
    for(auto &x : vec) {
        std::cin >> x;
    }
    int op = 0;
    for(;op < (1 << 6); op++) {
        i64 v1 = 0, v2 = 0;
        for(int i=0;i<6;i++) {
            if((op >> i) & 1) {
                v1 += vec[i];
            } else {
                v2 += vec[i];
            }
        }
        if(v1 == v2) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}