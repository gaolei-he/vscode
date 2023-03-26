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
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
using Node = pair<pii, pii>;
map<string, int> mp = {{"DR", 0}, {"DL", 1}, {"UR", 2}, {"UL", 3}};
unordered_set<string> st;
void solve()
{
    st.clear();
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    int ans = 0;
    int tx = dx[mp[d]], ty = dy[mp[d]];
    if(i1 == i2 && j1 == j2);
    else if(i1 == 1 && j1 == 1 && d != "DR")
    {
        ans ++;
        if(d[0] == 'U') tx = -tx;
        if(d[1] == 'L') ty = -ty;
    }
    else if(i1 == 1 && j1 == m && d != "DL")
    {
        ans ++;
        if(d[0] == 'U') tx = -tx;
        if(d[1] == 'R') ty = -ty;
    }
    else if(i1 == n && j1 == 1 && d != "UR")
    {
        ans ++;
        if(d[0] == 'D') tx = -tx;
        if(d[1] == 'L') ty = -ty;
    }
    else if(i1 == n && j1 == m && d != "UL")
    {
        ans ++;
        if(d[0] == 'D') tx = -tx;
        if(d[1] == 'R') ty = -ty;
    }
    else if(i1 == 1)
    {
        if(d == "UL" || d == "UR") ans ++, tx = -tx;
    }
    else if(i1 == n)
    {
        if(d == "DL" || d == "DR") ans ++, tx = -tx;
    }
    else if(j1 == 1)
    {
        if(d == "DL" || d == "UL") ans++, ty = -ty;
    }
    else if(j1 == m)
    {
        if(d == "DR" || d == "UR") ans++, ty = -ty;
    }
    while(true)
    {
        if(i1 == i2 && j1 == j2)
        {
            cout << ans << endl;
            return;
        }
        else if(st.count(to_string(i1) + " " + to_string(j1) + " " + to_string(tx) + " " + to_string(ty)))
        {
            cout << -1 << endl;
            return;
        }
        st.insert(to_string(i1) + " " + to_string(j1) + " " + to_string(tx) + " " + to_string(ty));
        // cerr << i1 << ' ' << j1 << endl;
        i1 += tx;
        j1 += ty;
        if(i1 == i2 && j1 == j2) continue;
        else if(i1 == 1 && j1 == 1 || i1 == 1 && j1 == m || i1 == n && j1 == 1 || i1 == n && j1 == m)
            tx = -tx, ty = -ty, ans ++;
        else if(i1 == 1 || i1 == n)
            tx = -tx, ans ++;
        else if(j1 == 1 || j1 == m)
            ty = -ty, ans ++;
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