#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
    for(int i=1;i<=n*2;++i) {
        if(i <= n) {
            std::cin >> a[i];
        } else {
            std::cin >> b[i-n];
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i=1;i<=n;++i) {
        a[i] = a[i] - b[i];
    }
    b.assign(n + 2, 0);
    for(int i=1;i<=n;++i) {
        b[i] += a[i];
        b[i+1] -= a[i];
        if(b[i] < 0) {
            ans1 += b[i];
        } else {
            ans2 += b[i];
        }
    }
    std::cout << std::max(-ans1, ans2) << std::endl;

    return 0;
}