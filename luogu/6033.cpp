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
int a[N];
int read()
{
    char c;
    int res = 0;
    while((c = getchar()) != EOF)
    {
        if(res && (c < '0' || c > '9')) return res;
        else if(c < '0' || c > '9') continue;
        res *= 10;
        res += c - '0';
    }
    return res;
}
void solve()
{
    int n; 
    n = read();
    rep(i, 1, n) a[read()] ++;
    queue<int> q1, q2;
    rep(i, 1, N - 4) while(a[i] --) q1.push(i);
    int ans = 0;
    int mi[3];
    while(1)
    {
        rep(i, 1, 2)
        {
            if(q1.size() && q2.size() && q1.front() < q2.front() || q1.size() && !q2.size())
                mi[i] = q1.front(), q1.pop();
            else mi[i] = q2.front(), q2.pop();
        }
        ans += mi[1] + mi[2];
        q2.push(mi[1] + mi[2]);
        if(q1.size() + q2.size() == 1) break;
    }
    cout << ans << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}