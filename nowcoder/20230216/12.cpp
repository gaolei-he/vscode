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
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 5e2, mod = 1e9 + 7;
int d[N][N];
int n;
void floyd()
{
    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}
void solve()
{
    cin >> n;
    unordered_map<int, int> mp;
    memset(d, 0x3f, sizeof(d));
    rep(i, 1, n) d[i][i] = 0;
    rep(i, 1, n)
    {
        char op;
        int t;
        cin >> op >> t;
        if(op == 'F') mp[i] = 1;
        else mp[i] = 0;
        while(t--)
        {
            int a, b;
            cin >> a >> op >> b;
            d[i][a] = min(d[i][a], b);
        }
    }
    floyd();
    vector<pii> vec;
    rep(i, 1, n)
    {
        int mi = -1;
        rep(j, 1, n)
        {
            if(mp[i] == mp[j]) continue;
            mi = max(d[j][i], mi);
        }
        vec.push_back({mi, i});
    }
    sort(vec.begin(), vec.end());
    dec(op, 1, 0)
    {
        rep(i, 0, SZ(vec)-1)
        {
            if(mp[vec[i].second] == op)
            {
                cout << vec[i].second;
                rep(j, i+1, SZ(vec)-1) if(vec[j].first == vec[i].first && mp[vec[j].second] == op) cout << " " << vec[j].second;
                cout << endl;
                break;
            }
        }
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