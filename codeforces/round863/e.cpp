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
int mypow(int x)
{
    int res = 1;
    while(x--) res *= 10;
    return res;
}
bool check(int mid, int k)
{
    int ans = 0;
    string s = to_string(mid);
    // reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '4')
        {
            int v = 1;
            if(i) v = stoll(s.substr(0, i));
            ans += max(v, 1ll) * (mypow(SZ(s) - i - 1));
        }
        else
        {
            
            if(i) ans += (max(stoll(s.substr(0, i)), 1ll) - 1)* (mypow(SZ(s) - i - 1));
            if(i != s.size() - 1) ans += stoll(s.substr(i+1));
        }
    }
    return (mid - k) <= ans;
}
void solve()
{
    int ans = 0;
    int k; cin >> k;
    int l = 0, r = mod * 100000;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid, k)) r = mid - 1;
        else l = mid;
    }
    cout << l << endl;
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