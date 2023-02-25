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
int a[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    deque<int> q;
    for(int i=1, j=1;i<=n;i++)
    {
        j = max(1ll, i - k + 1);
        while(q.size() && q.front() < j) q.pop_front();
        while(q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if(i >= k) cout << a[q.front()] << ' ';
    }
    cout << endl;
    q.clear();
    for(int i=1, j=1;i<=n;i++)
    {
        j = max(1ll, i - k + 1);
        while(q.size() && q.front() < j) q.pop_front();
        while(q.size() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        if(i >= k) cout << a[q.front()] << ' ';
    }
    cout << endl;
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