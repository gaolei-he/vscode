// ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n, m, dp[N][10];
string s, t;
int main() {
    ll i, j, k;
    cin >> n >> m >> s >> t;
    dp[0][0] = 1;
    for (i = 0; i < s.size(); i++) {
        for (j = 0; j <= t.size(); j++) {
            for (k = 0; k < t.size(); k++) {
                if (s[i] == t[k] && (k == j || k == 0 || j == t.size())) {
                    dp[i + 1][k + 1] |= dp[i][j];
                }
            }
        }
    }
    if (dp[s.size()][t.size()]) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}