#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<random>
#include<cassert>
#include<functional>
#include<iomanip>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i,a,n) for(int i = (a);i <= (n);i++)
#define dec(i,n,a) for(int i = (n);i >= (a);i--)
using namespace std;
using PII = pair<int,int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int N =10 + 2e5 ,mod=1e9 + 7;
int fact[N], infact[N], n;
int quick_pow(int a, int k, int p)
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}
void init()
{
    fact[0] = infact[0] = 1; 
    rep(i, 1, 1e5+10)
    {
        fact[i] = fact[i-1] * i % mod;
        infact[i] = infact[i - 1] * quick_pow(i, mod-2, mod) % mod;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << fact[n + 1] * infact[4] % mod * infact[n - 3] % mod * fact[m + 1] % mod * infact[4] % mod * infact[m-3] % mod << endl;
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int t; cin >> t;
    while (t --)
        solve();

    return 0;
}