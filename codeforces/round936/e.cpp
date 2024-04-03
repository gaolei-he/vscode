#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9+7;
constexpr int N = 2e5 + 10;

i64 fact[N], infact[N];

i64 quick_pow(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for(int i=1;i<N;i++) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * quick_pow(i, mod - 2) % mod;
    }
}

i64 C(int n, int k) {
    return fact[n] * infact[k] % mod * infact[n - k] % mod;
}

void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    std::vector<int> vec1(m1), vec2(m2);
    for (auto &x : vec1) {
        std::cin >> x;
        x -= 1;
    }
    for (auto &x : vec2) {
        std::cin >> x;
        x -= 1;
        x = n - 1 - x;
    }
    std::reverse(vec2.begin(), vec2.end());
    // for(auto x : vec1) std::cerr << x << ' ';
    // std::cerr << "\n";
    // for(auto x : vec2) std::cerr << x << ' ';
    // std::cerr << "\n";
    if(vec1.front() != 0 or vec2.front() != 0 or vec1.back() + vec2.back() != n - 1) {
        std::cout << "0\n";
        return;
    }
    i64 ans = 1;
    for(int i=0;i<m1-1;i++) {
        int val = vec1[i + 1] - vec1[i] - 1;
        ans = ans * fact[val] % mod;
        ans = ans * C(vec1[i + 1] - 1, val) % mod;
    }
    for(int i=0;i<m2-1;i++) {
        int val = vec2[i + 1] - vec2[i] - 1;
        ans = ans * fact[val] % mod;
        ans = ans * C(vec2[i + 1] - 1, val) % mod;
    }
    std::cout << ans * C(n - 1, vec1.back()) % mod << "\n";

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}