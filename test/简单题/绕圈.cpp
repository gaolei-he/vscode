#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(n & 1) {
        k %= n - 1;
        if(k > n / 2) {
            k += 1;
        } else if(k == 0) {
            k = n;
        }
        std::cout << k << "\n";
        return;
    }
    k %= n;
    if(k == 0) {
        k = n;
    }
    std::cout << k << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int n;
    // std::cin >> n;
    // std::vector<int> v1(n), v2(n);
    // std::iota(v1.begin(), v1.end(), 1);
    // std::iota(v2.begin(), v2.end(), 1);
    // std::reverse(v1.begin(), v1.end());
    // for(int i=0;i<=100;i++) {
    //     std::cout << v1[i % n] << " \n"[i == 100];
    // }
    // int cnt = 0;
    // for(int i=0;cnt <= 100;i++) {
    //     if(v2[i % n] == v1[i % n]) {
    //         i += 1;
    //     }
    //     cnt += 1;
    //     std::cout << v2[i % n] << " \n"[cnt == 100];
    // }
    // exit(0);


    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

/*


*/