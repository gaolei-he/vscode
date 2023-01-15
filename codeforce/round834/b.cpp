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
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int m, s;
    cin >> m >> s;
    vector<int> a(m);
    rep(i, 0, m-1) cin >> a[i];
    sort(a.begin(), a.end());
    if(a.front() > 1) s -= a.front() * (a.front() - 1) / 2;
    if(s < 0) { cout << "NO" << endl; return;}
    rep(i, 0, m-2)
    {
        if(a[i+1]-a[i] != 1) rep(j, a[i]+1, a[i+1]-1) s -= j;
        // cout << s << endl;
    }
    if(s < 0){ cout << "NO" << endl; return;}
    else if(s == 0) {cout << "YES" << endl; return;}
    rep(i, a.back()+1, N)
    {
        s -= i;
        if(s < 0){ cout << "NO" << endl; return;}
        else if(s == 0) {cout << "YES" << endl; return;}
        // cout << s << endl;

    }
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