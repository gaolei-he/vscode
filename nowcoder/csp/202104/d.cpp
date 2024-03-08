#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 1000000007;
bool st[100010];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> dp(n + 1);
    std::vector<int> a(n + 1);
    for(int i=1;i<=n;i++) {
        std::cin >> a[i];
    }
    dp[1] = 1;
    std::vector<std::vector<int>> factors(100005);
    for(int i=2;i<=100000;i++) {
        int x = i;
        for(int j=1;j<=x/j;j++) {
            if(x % j == 0) {
                factors[i].emplace_back(j);
                if(x / j != j and x / j != x) {
                    factors[i].emplace_back(x / j);
                }
            }
        }
    }
    for(int i=2;i<=n;i++) {
        memset(st, 0, sizeof(st));
        for(int j=i-1;j>0;j--) {
            int k = a[i] - a[j];
            st[k] = true;
            int cnt = 0;
            for(auto x : factors[k]) {
                if(!st[x]) {
                    st[x] = true;
                    cnt += 1;
                }
            }
            dp[i] += dp[j] * cnt;
            dp[i] %= mod;
        }
    }
    std::cout << dp[n] << std::endl;

    return 0;
}