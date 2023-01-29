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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N], b[N];
int n, m;
bool check(int mid)
{
    int cnt = 0;
    rep(i, 1, n)
    {
        if(a[i] < mid) continue;
        cnt += (a[i] - mid) / b[i] + 1;
    }
    if(cnt < m) return false;
    return true;
}
void solve()
{
    
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i] >> b[i];
    int l = 0, r = N;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    int ans = 0, cnt = 0;
    rep(i, 1, n)
    {
        if(a[i] <= l) continue;
        int k = (a[i] - l) / b[i] + 1;
        if((a[i] - l) % b[i] == 0) k --;
        int a1 = a[i] - (k-1) * b[i];
        ans += (a1 + a[i]) * k / 2;
        cnt += k;
    }
    if(cnt < m) ans += l * (m-cnt);
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