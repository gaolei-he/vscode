#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int n, m;
ar2 a[N];
int solve()
{
    cin >> n >> m;
    rep(i, 1, m) cin >> a[i][0] >> a[i][1];
    sort(a + 1, a + m + 1, [](ar2 a, ar2 b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    int ans = 0;
    int l = 0, r = 0, k = 1;
    while(1)
    {
        int tr = r;
        for(int tk=k;k <= m;k ++)
        {
            if(a[k][0] <= tr + 1) r = max(r, a[k][1]);
            else if(tk == k) return -1;
            else break;
        }
        ans ++;
        if(k > m || r >= n) break;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
    cout << solve();

    return 0;
}