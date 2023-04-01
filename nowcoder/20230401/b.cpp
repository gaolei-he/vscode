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
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};
void solve()
{
    int n;
    cin >> n;
    if(n < 3 || n == 5)
    {
        cout << -1 << endl;
        return;
    }
    if(n % 3 == 0)
    {
        rep(i, 1, n / 3)
        {
            rep(j, 1, 3) cout << i << " " << i << endl;
        }
    }
    else if(n % 3 == 1)
    {
        rep(i, 1, n / 3 - 1)
        {
            rep(j, 1, 3) cout << i << " " << i << endl;
        }
        rep(i, 0, 3)
        {
            cout << n / 3 + dx[i] << ' ' << n / 3 + dy[i] << endl;
        }
    }
    else if(n % 3 == 2)
    {
        for(int j=1;j < 4;j+=2)
        rep(i, 0, 3)
        {
            cout << j + dx[i] << ' ' << j + dy[i] << endl;
        }
        n -= 8;
        rep(i, 5, n / 3 + 4)
        {
            rep(j, 1, 3) cout << i << " " << i << endl;
        }
        
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