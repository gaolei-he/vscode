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
#include <unordered_map>
#include <map>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void sp(map<int, int> &mp, int x)
{
    for(int i=2;i<=x/i;i++)
    {
        while(x%i==0)
        {
            mp[i] ++;
            x /= i;
        }
    }
    if(x > 1) mp[x] ++;
}
void solve()
{
    
    int x;
    cin >> x;
    int ans = x;
    map<int, int> pr;
    sp(pr, x);
    bool flag = true;
    for(auto i:pr) if(i.second > 1) flag = false;
    int tmpl = ans, tmpr = ans;
    if(flag) cout << ans << endl;
    else
    {
        bool st = true;
        while(st)
        {
            int l = tmpl - 1, r = tmpr + 1;
            pr.clear();
            sp(pr, l);
            flag = true;
            for(auto i:pr) if(i.second > 1) flag = false;
            if(flag) {cout << l << endl; st = false;}
            
            pr.clear();
            sp(pr, r);
            flag = true;
            for(auto i:pr) if(i.second > 1) flag = false;
            if(flag) {cout << r << endl; st = false;}

            tmpl = l, tmpr = r;
        }
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}