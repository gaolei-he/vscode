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
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[N], s[N];
PII d[N];
void solve()
{
    int n, m;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        s[i] = a[i] + s[i-1];
        d[i].second = i;
    }
    cin >> m;
    int sm1 = 0;
    vector<pair<int, int>> tmp;
    rep(i, 1, m)
    {
        int l, r;
        cin >> l >> r;
        tmp.push_back({l, r});
        sm1 += s[r] - s[l-1];
        d[l].first ++;
        d[r+1].first --;
    }
    rep(i, 1, n) d[i].first += d[i-1].first;
    sort(a + 1, a + n + 1);
    sort(d + 1, d + n + 1, [](PII a, PII b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    // rep(i, 1, n) cerr << d[i].first << ' ' << d[i].second << endl;
    int sm2 = 0;
    rep(i, 1, n) d[i].first = a[i];
    rep(i, 1, n) a[d[i].second] = d[i].first;
    rep(i, 1, n) s[i] = a[i] + s[i-1];
    for(auto i:tmp) sm2 += s[i.second] - s[i.first - 1];
    cout << sm2 - sm1 << endl;


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