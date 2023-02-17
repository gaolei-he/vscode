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
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(min(c, d) < a and max(c, d) >= b)
    {
        cout << c << "-Y " << d << "-Y" << endl;
        int e, f;
        if(c > d) e = 1, f = 2;
        else e = 2, f = 1;
        cout << "qing " << e << " zhao gu hao " << f << endl;
    }
    else if(c >= a && d >= a)
    {
        cout << c << "-Y " << d << "-Y" << endl;
        cout << "huan ying ru guan" << endl;
    }
    else if(c < a && d < a)
    {
        cout << c << "-N " << d << "-N" << endl;
        cout << "zhang da zai lai ba" << endl;
    }
    else
    {
        cout << c;
        if(c < a) cout << "-N ";
        else cout << "-Y ";
        cout << d;
        if(d < a) cout << "-N" << endl;
        else cout << "-Y" << endl;
        if(c >= a) cout << 1;
        else cout << 2;
        cout << ": huan ying ru guan" << endl;
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