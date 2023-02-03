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
char str[N];
int lud[N], rdu[N];
int lu[N], ru[N];
void solve()
{
    cin >> str + 1;
    int nu = 0;
    int n = strlen(str+1);
    rep(i, 1, n)
    {
        lud[i] = lud[i-1];
        lu[i] = nu;
        if(str[i-1] == 'd') lud[i] += nu;
        if(str[i] == 'u') nu ++;
    }
    nu = 0;
    dec(i, n, 1)
    {
        rdu[i] = rdu[i+1];
        ru[i] = nu;
        if(str[i+1] == 'd') rdu[i] += nu;
        if(str[i] == 'u') nu ++;
    }
    int pos = -1;
    int ma = 0;
    rep(i, 1, n)
    {
        if(str[i] == 'd')
        {
            if(lu[i] * ru[i] > ma)
            {
                ma = lu[i] * ru[i];
                pos = i;
            }
        }
        else if(str[i] == 'u')
        {
            if(lud[i] + rdu[i] > ma)
            {
                ma = lud[i] + rdu[i];
                pos = i;
            }
        }
    }
    str[pos] = 'v';
    cout << str + 1 << endl;

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