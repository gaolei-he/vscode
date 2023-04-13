#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
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
using pii = pair<int, int>;
using ar3 = array<int, 3>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e4, mod = 1e9 + 7;
char str[N];
ar3 s[N];
void solve()
{
    cin >> str + 1;
    int r = 1;
    int length = strlen(str + 1);
    ar3 t = {0, 0, 0};
    rep(i, 1, length)
    {
        switch (str[i])
        {
        case 'X':t[0] ++; break;
        case 'T':t[1] ++; break;
        case 'U':t[2] ++; break;
        default: break;
        }
        s[i] = t;
    }
    map<ar3, int> mp;
    rep(i, 0, length)
    {
        ar3 t = {0, s[i][1] - s[i][0], s[i][2] - s[i][1]};
        mp[t] ++;
    }

    int ans = 0;
    rep(i, 0, length)
    {
        ar3 t = {0, s[i][1] - s[i][0], s[i][2] - s[i][1]};
        mp[t] --;
        ans += mp[t];
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}