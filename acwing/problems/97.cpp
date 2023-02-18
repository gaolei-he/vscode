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
const int N = 10 + 1e5, mod = 9901;
int qp(int a, int b, int mod=mod)
{
    int res = 1 % mod;
    while(b)
    {
        if(b&1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
int inv(int x)
{
    return qp(x, mod-2, mod);
}
void solve()
{
    int a, b; cin >> a >> b;
    if(a == 0) { cout << 0 << endl; return;}
    else if(b == 0) { cout << 1 << endl; return;}
    unordered_map<int, int> pr;
    for(int i=2;i<=a/i;i++) while(a%i==0) a/=i, pr[i] ++;
    if(a > 1) pr[a] ++;
    for(auto& p:pr) p.second *= b;
    int ans = 1;
    for(auto p:pr)
    {
        if((p.first - 1) % mod)
        {
            ans = ans * (qp(p.first, p.second+1)-1+mod) % mod * inv(p.first - 1) % mod;
            continue;
        }
        int a = 1, t = p.second;
        while(t --) a = (a * p.first + 1) % mod;
        ans = ans * a % mod;
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