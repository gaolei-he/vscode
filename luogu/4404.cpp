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
int n, m, num = N, ans = 0;
int a[N];
map<int, queue<int>> mp1;
set<int> st;
map<int, int> mp2;
int f(int k, int i)
{
    auto& tmp = mp1[k];
    while(tmp.size() && tmp.front() <= i) tmp.pop();
    int key;
    if(tmp.size()) key = tmp.front();
    else key = num ++;
    return key;
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        mp1[a[i]].push(i);
    }
    rep(i, 1, n)
    {
        if(st.count(a[i])) continue;
        int key;
        while(mp2.size() && mp2.begin()->first <= i)
        {
            key = f(mp2.begin()->second, i);
            mp2[key] = mp2.begin()->second;
            mp2.erase(mp2.begin()->first);
        }
        key = f(a[i], i);
        if(mp2.size() < m)
        {
            mp2[key] = a[i];
            st.insert(a[i]);
        }
        else
        {
            st.erase(mp2.rbegin()->second);
            mp2.erase(mp2.rbegin()->first);
            mp2[key] = a[i];
            st.insert(a[i]);
        }
        ans ++;
    }
    cout << ans << endl;
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