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
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 4e6, mod = 1e9 + 7;
int p[N];
bool st[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
struct Point
{
    int x, y;
    int num;
}point[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    function<void(void)> init = [&](){rep(i, 1, N-5) p[i] = i;};
    init();
    function<void(int&, int&)> convert = [=](int &a, int &b){
        if(a == 1 || b == m) return;
        else if(a == n) b = m + (m - b);
        else
        {
            b = 2 * m - 1;
            a = n + (n - a);
        }
        return;
    };
    rep(i, 1, m)
    {
        int x2, y2;
        int x1 = 1, y1 = i;
        convert(x1, y1);
        if(i < n)
            y2 = 1, x2 = i;
        else
            x2 = n, y2 = i - (n - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
        if(m - i > n - 1)
            x2 = n, y2 = i + (n - 1);
        else
            y2 = m, x2 = 1 + m - i;
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
    }
    rep(i, 2, n)
    {
        int x1 = i, y1 = m;
        int x2, y2;
        convert(x1, y1);
        if(i - 1 < m - 1)
            x2 = 1, y2 = m - (i - 1);
        else
            y2 = 1, x2 = i - (m - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
        
        if(n - i < m - 1)
            x2 = n, y2 = m - (n - i);
        else
            y2 = 1, x2 = i + (m - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
    }
    dec(i, m-1, 1)
    {
        int x1 = n, y1 = i;
        convert(x1, y1);
        int x2, y2;
        if(i - 1 < n - 1)
            y2 = 1, x2 = n - (i - 1);
        else
            x2 = 1, y2 = i - (n - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);

        if(m - i < n - 1)
            y2 = m, x2 = n - (m - i);
        else
            x2 = 1, y2 = i + (n - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
    }
    dec(i, n-1, 2)
    {
        int x1 = i, y1 = 1;
        convert(x1, y1);
        int x2, y2;
        if(i - 1 < m - 1)
            x2 = 1, y2 = 1 + (i - 1);
        else
            y2 = m, x2 = i - (m - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);

        if(n - i < m - 1)
            x2 = n, y2 = 1 + (n - i);
        else
            y2 = m, x2 = i + (m - 1);
        convert(x2, y2);
        p[find(x1+y1)] = find(x2 + y2);
    }
    // set<int> lib;
    // rep(i, 1, 2*(n + m) - 4) lib.insert(find(i));
    // cout << lib.size() - 1;
    rep(i, 1, 2*(n+m)-4) st[p[i]] = true;
    int ans = 0;
    rep(i, 1, 2*(n+m)-4) if(st[i]) ans ++;
    cout << ans - 1 << endl;

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