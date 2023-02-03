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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n, m, k;
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    cin >> n >> m >> k;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, min(k, n)) pq1.push(a[i]);
    rep(i, min(k+1, n+1), n) pq2.push(a[i]);
    rep(i, 1, m)
    {
        int op; cin >> op;
        if(op & 1)
        {
            int x; cin >> x;
            if(pq1.size() < k) pq1.push(x);
            else
            {
                if(pq1.top() <= x) pq2.push(x);
                else
                {
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(x);
                }
            }
        }
        else
        {
            if(pq1.size() < k) cout << -1 << endl;
            else cout << pq1.top() << endl;
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