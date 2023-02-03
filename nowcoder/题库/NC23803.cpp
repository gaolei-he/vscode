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
const int N = 10 + 2e4, mod = 1e9 + 7;
int a[N], p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    set<string> tmp1;
    vector<string> tmp2;
    rep(i, 1, n)
    {
        string tmp;
        cin >> tmp;
        if(tmp1.count(tmp)) continue;
        tmp1.insert(tmp);
        tmp2.push_back(tmp);
    }
    rep(i, 0, tmp2.size()-1) mp[tmp2[i]] = i + 1;
    n = mp.size();
    rep(i, 1, n) p[i] = i;
    rep(i, 1, m)
    {
        int op;
        string tmp1, tmp2;
        int a, b;
        cin >> op;
        cin >> tmp1 >> tmp2;
        a = mp[tmp1];
        b = mp[tmp2];
        if(op & 1) p[find(a)] = find(b);
        else
        {
            if(find(a) != find(b)) cout << "0" << endl;
            else cout << "1" << endl;
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