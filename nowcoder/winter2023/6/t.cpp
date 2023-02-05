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
const int N = 10 + 1e5, mod = 1e9 + 7;
int base = 1e4;
map<int, int> mp;
int dfs(int l, int x, int r)
{
    int key = l * base * base + x * base + r;
    if(mp.count(key)) return mp[key];
    if(x/2 >= l)
    {
        if(r == 1010) return mp[key] = 0;
        else if((r-x) % 2) return mp[key] = -1;
        else return mp[key] = 1;
    }
    int best = 1;
    if(x/2>0 && x/2<l)
        best = min(best, dfs(x/2, x/2, l));
    if(best!=-1&&x+1<r)
        best = min(best, dfs(l, x+1, r));
    return mp[key] = -best;

}
void solve()
{
    int x; cin >> x;
    int ans = dfs(x, x, 1010);
    switch (ans)
    {
    case -1: cout << "red\n"; break;
    case 0: cout << "draw\n"; break;
    case 1: cout << "ning\n"; break;
    default: break;
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