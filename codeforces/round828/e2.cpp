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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> factorsa, factorsb;
    for(int i = 1;i*i<=a;i++)
        if(a % i == 0)
        {
            factorsa.push_back(i);
            if(i*i != a) factorsa.push_back(a/i);
        }
    for(int i = 1;i*i<=b;i++)
        if(b % i == 0)
        {
            factorsb.push_back(i);
            if(i*i != b) factorsb.push_back(b/i);
        }
    for(auto x : factorsa)
    {
        for(auto y : factorsb)
        {
            int l = x * y;
            int r = a * b / l;
            l *= c / l;
            r *= d / r;
            if(l > a and l <= c and r > b and r <= d)
            {
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << "-1 -1\n";
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