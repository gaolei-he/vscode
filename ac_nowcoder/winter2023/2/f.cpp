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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 5e5, mod = 1e9 + 7;
bool a[N][4];
int solve()
{
    int n, k;
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    rep(i, 1, k)
    {
        int x, y; cin >> x >> y;
        if(a[x][y]) a[x][y] = false;
        else a[x][y] = true;
    }
    int ml = 1e9, mr = 0;
    rep(i, 1, n)
        if(a[i][1])
        {
            ml = i;
            break;
        }
    
    dec(i, n, 1)
        if(a[i][3])
        {
            mr = i;
            break;
        }
    int ans = 0;
    if(ml && mr && ml < mr)
    {
        rep(i, ml, mr) if(a[i][2]) return 1;
        ans += ml - 1;
        ans += n - mr;
        rep(i, mr, n)
        {
            if(a[i][2]) break;
            ans ++;
        }
        dec(i, ml, 1)
        {
            if(a[i][2]) break;
            ans ++;
        }
        return ans;
    }
    else if(ml && mr && ml == mr)
    {
        if(a[ml][2] || a[ml+1][2] || a[ml-1][2]) return 1;
        ans += ml - 1;
        ans += n - mr;
        rep(i, ml, n)
            if(!a[i][2]) ans ++;
            else break;
        dec(i, ml, 1)
            if(!a[i][2]) ans ++;
            else break;
        return ans;
    }
    else if(ml && mr && ml > mr)
    {
        bool ok = true;
        rep(i, mr+1, ml-1) if(!a[i][2]) ok = false, ans ++;
        if(ok && a[mr][2]) return 1;
        if(!a[ml-1][2] && a[ml][2]) ans ++;
        if(!a[mr+1][2] && a[mr][2]) ans ++;
        dec(i, ml-1, 1) if(!a[i][2]) {ans += i; break; }
        rep(i, mr+1, n) if(!a[i][2]) {ans += n - i; break;}
        return ans;

    }
    else if(ml)
    {
        rep(i, 1, n)
            if(!a[i][2] && i >= ml) return 1;
            else if(!a[i][2]) { ans += n - i + 1; break; }//r
        dec(i, ml-1, 1) if(!a[i][2]) {ans += i; break; }// l
        rep(i, 1, ml - 1) if(!a[i][2]) ans ++;// m u
        rep(i, ml, n)
            if(!a[i][2]) ans ++;//m d
            else break;
    }
    else if(mr)
    {
        dec(i, n, 1)
            if(!a[i][2] && i > mr) {ans += i; break; } // l
            else if(!a[i][2] && i <= mr) return 1;
        
        rep(i, mr+1, n)
            if(!a[i][2]) {ans += n - i + 1; break;} // r
        
        rep(i, mr+1, n) if(!a[i][2]) ans ++; //m d;
        if(a[mr+1][2]) return ans;
        dec(i, mr, 1)
            if(!a[i][2]) ans ++;
            else break;
        return ans;
    }
    else
    {
        rep(i, 1, n) if(!a[i][2]) {ans += n - i + 1; break; }// r
        dec(i, n, 1) if(!a[i][2]) {ans += i; break;} // l
        if(ans == 0) return 1;
        rep(i, 1, n) if(!a[i][2]) ans ++;
        return ans;
    }
    return 1;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() - 1 << endl;

    return 0;
}