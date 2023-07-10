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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e3, mod = 1e9 + 7;
int a[N][N];
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) a[n + 1][i] = 0;
    rep(i, 1, m) a[i][m + 1] = 0;
    int x0, y0, x1, y1;
    rep(i, 1, n)
        rep(j, 1, m)
            if(a[i][j] == 0)
                x0 = i, y0 = j;
            else if(a[i][j] == 1)
                x1 = i, y1 = j;
    while(x0 != x1 || y0 != y1)
    {
        int v1 = x0 - x1;
        int v2 = y0 - y1;
        if(v1)
        {
            if(v1 > 0) cout << "S", swap(a[x0][y0], a[x0-1][y0]), x0 --;
            else cout << "W", swap(a[x0+1][y0], a[x0][y0]), x0 ++;
        }
        else
        {
            if(v2 > 0) cout << "D", swap(a[x0][y0-1], a[x0][y0]), y0 --;
            else cout << "A", swap(a[x0][y0], a[x0][y0+1]), y0 ++;
        }
    }
    if(a[x1 + 1][y1] == 1 and x1 < n)
    {
        if(y1 == 1 and x1 == 1)
        {
            cout << "W" << endl;
            return;
        }
        else if(y1 == 1)
        {
            cout << "WA";
            x1 --;
        }
        else cout << "WDSAW", y1 --;
    } 
    else if(a[x1 - 1][y1] == 1 and x1 > 1)
    {
        if(y1 == 1 and x1 == 2)
        {
            cout << endl;
            return;
        }
        else if(y1 == 1)
        {
            cout << "A";
            x1 --;
        }
        else cout << "DSAW", x1 --, y1--;
    } 
    else if(a[x1][y1 + 1] == 1 and y1 < m)
    {
        if(x1 == 1 and y1 == 1)
        {
            cout << "A" << endl;
            return;
        }
        else if(x1 == 1)
        {
            cout << "AW";
            y1 --;
        }
        else cout << "ASDWA", x1 --;
    }
    else if(a[x1][y1 - 1] == 1 and y1 > 1)
    {
        if(x1 == 1 and y1 == 2)
        {
            cout << endl;
            return;
        }
        else if(x1 == 1)
        {
            cout << "W";
            y1 --;
        }
        else cout << "SDWA", x1 --, y1 --;
    } 
    x0 = x1 + 1, y0 = y1 + 1;
    // if(x1 < 1 or y1 < 1)
    // {
    //     cout << endl;
    //     return;
    // }
    while(x1 != 1 and y1 != 1)
    {
        cout << "SSDWDSAW";
        x1 --, y1 --;
    }
    while(x1 != 1)
    {
        cout << "SSDWA";
        x1 --;
    }
    while(y1 != 1)
    {
        cout << "DDSAW";
        y1 --;
    }
    cout << endl;
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