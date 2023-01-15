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
#define ull unsigned long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i,a,n) for(int i = (a);i <= (n);i++)
#define dec(i,n,a) for(int i = (n);i >= (a);i--)
using namespace std;
using PII = pair<int,int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int N =10 + 1e6 ,mod=1e9 + 7;
const int P = 131;
char str[N];
int n, m;
ull p[N], h[N];
set<ull> lib;
void init()
{
    p[0] = 1;
    rep(i, 1, n) p[i] = p[i-1] * 131;
    rep(i, 1, n) h[i] = h[i-1] * P + str[i];
}
ull get(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}
void solve()
{
    
    cin >> n >> m;
    cin >> str + 1;
    init();
    rep(i, 1, n)
    {
        ull has = get(1, i);
        bool flag = true;
        if(n % i) continue;
        for(int j=i; j <= n; j += i)
        {
            if(get(j-i+1, j) == has) continue;
            else { flag = false; break;}
        }
        if(flag) lib.insert(has);
    }
    // for(auto i:lib) cout << i << ' ';
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        l ++;
        r ++;
        if(lib.find(h[r] - h[l-1] * p[r-l+1]) != lib.end()) cout << "YES\n";
        else cout << "NO" << endl;

    }
    
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();

    return 0;
}