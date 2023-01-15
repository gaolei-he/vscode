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
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[N], n;
bool check(int cnt)
{
    int sum = 0;
    rep(i, 1, n)
    {
        sum += a[i];
        if(sum == cnt) sum = 0;
        else if(sum > cnt) return false;
    }
    return true;
}
void solve()
{
    int sum = 0;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    dec(i, n, 1)
    {
        if(sum % i == 0 && check(sum / i))
        {
            cout << n - i << endl;
            break;
        }
    }
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