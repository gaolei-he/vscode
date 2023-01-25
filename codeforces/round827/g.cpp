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
set<int> lib;
bool cmp(int x, int tmp)
{
    rep(i, 0, 29) if(((x>>i)&1) == 0 && ((tmp>>i)&1) == 1) return true;
    return false;
}
int cov(int a, int b)
{
    int res = 0;
    rep(i, 0, 29)
    {
        if(((b >> i) & 1) == 0 && ((a >> i) & 1) == 1)
            res += (1 << i);
    }
    return res;
}
void finds(vector<int> &a, int &ma)
{
    if(a.empty()) return;
    int res = 0;
    int ins = 0;
    for(auto i:a)
    {
        int tmp = cov(i, ma);
        if(tmp > res) res = tmp, ins = i;
    }
    cout << ins << ' ';
    lib.insert(ins);
    ma = ma | res;
}
void solve()
{
    int n;
    cin >> n;
    lib.clear();
    vector<int> a(n);
    int ma = 0;
    rep(i, 0, n-1)
    {
        cin >> a[i];
        ma = max(a[i], ma);
    }
    vector<int> c = a;
    vector<int> b;
    cout << ma << ' ';
    lib.insert(ma);
    do
    {
        b.clear();
        for(auto i:a) if(cmp(ma, i)) b.push_back(i);
        finds(b, ma);
        a = b;
        
    } while (b.size());
    
    for(auto i:c)
    {
        if(lib.find(i) != lib.end()) lib.erase(i);
        else cout << i << ' ';
    }
    cout << endl;

}
signed main()
{
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}