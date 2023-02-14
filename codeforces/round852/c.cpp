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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n; cin >> n;
    deque<int> q;
    rep(i, 1, n)
    {
        int x; cin >> x;
        a[i] = x;
        q.push_back(x);
    }
    deque<int> q1;
    rep(i, 1, n) q1.push_back(i);
    while(q.size())
    {
        int cnt = 0;
        int a = q1.front(), b = q1.back();
        if(q.front() == a) q.pop_front(), q1.pop_front();
        else if(q.front() == b) q.pop_front(), q1.pop_back();
        else cnt ++;
        if(q.empty()) break;
        a = q1.front(), b = q1.back();
        if(q.back() == a) q.pop_back(), q1.pop_front();
        else if(q.back() == b) q.pop_back(), q1.pop_back();
        else cnt ++;
        if(cnt == 2) break;
    }
    if(q.empty()) cout << -1 << endl;
    else
    {
        rep(i, 1, n) if(a[i] == q.front()) cout << i << ' ';
        rep(i, 1, n) if(a[i] == q.back()) cout << i << endl;
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