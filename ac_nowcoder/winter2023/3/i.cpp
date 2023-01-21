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
const int N = 10 + 1e6, mod = 1e9 + 7;
bool st[N];
void work()
{
    for(int i=2;i<N;i++)
        if(!st[i]) for(int j=i+i;j<N;j+=i) st[j] = true;
}
void solve()
{
/*
6 = 3 + 3
10 = 5 + 5 = 3 + 7
14 = 7 + 7 = 3 = 11
*/
    int x; cin >> x;
    if(x == 1) cout << 2 << endl;
    else if(x == 3) cout << 4 << endl;
    else if(x == 7) cout << 8 << endl;
    else if(x&1)
    {
        int p = -1, q = -1;
        rep(i, 2, x-3) if(!st[i] && !st[x-1-i]) {p = i, q = x - 1 - i; if(p != q) break;}
        if(p!=q) cout << p * q << endl;
        else cout << -1 << endl;
    }
    else
    {
        if(!st[x-1]) cout << (x - 1) * (x - 1) << endl;
        else if(!st[x-3]) cout << (x - 3) * 2 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    work();
    while(t--)
        solve();

    return 0;
}