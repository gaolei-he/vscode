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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 3e3, mod = 1e9 + 7;
int n;
char str[N];
void solve()
{
    cin >> n;
    cin >> str + 1;
    int ans = 0;
    rep(i, 1, n)
    {
        int j = i + 1;
        if(str[i] == 'R')
        while(str[j] != 'L' && j <= n) j++;
        if(((j-i-1)&1) && str[j] == 'L') ans ++;
        if(j != i + 1) rep(k, i, j) str[k] = '#';
        if(j != i + 1) i = j;
    }
    rep(i, 1, n)
    {
        if(str[i] == 'R')
        {
            rep(j, i, n)
                if(str[j] == '.' || str[j] == 'R') str[j] = '#';
                else break;
        }
        else if (str[i] == 'L')
        {
            dec(j, i, 1)
                if(str[j] == '.' || str[j] == 'L') str[j] = '#';
                else break;
        }
        
    }
    rep(i, 1, n) if(str[i] == '.') ans ++;
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