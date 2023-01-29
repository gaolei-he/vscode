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
const int N = 10 + 2e6, mod = 1e9 + 7;
int n, m, tmp;
ar2 a[N];
void insert()
{
    m -= n;
    rep(i, 0, tmp + 1)
    {
        if(!m) return;
        if(i % 2 == 0)
        {
            m --;
            a[i][1] ++;
            if(!m) return;
            if(a[i][1] < 2) m --, a[i][1] ++;
        }
    }
}
void print()
{
    a[0][0] = 1;
    rep(i, 0, N)
    {
        if(a[i][1]) rep(j, 1, a[i][1]) cout << a[i][0];
        else if(i == 0) continue;
        else break;
    }
}
void solve()
{
    cin >> n >> m;
    tmp = min(n, m) * 2;
    rep(i, 1, min(n, m) * 2)
    {
        if(i & 1) a[i][0] = 0, a[i][1] = 1;
        else a[i][0] = 1, a[i][1] = 1;
    }
    if(min(n, m) == m)
    {
        if(n - m > 1) cout << -1 << endl;
        else print();
        if(n - m == 1) cout << 0 << endl;
    }
    else if (min(n, m) == n)
    {
        insert();
        if(m) cout << -1 << endl;
        else print();

    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}