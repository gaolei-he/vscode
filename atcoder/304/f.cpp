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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 998244353;
char str[N];
int quick_pow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n; cin >> n;
    cin >> str + 1;
    vector<int> days;
    rep(i, 1, n) if(str[i] == '.') days.push_back(i);
    vector<int> dividers;
    rep(i, 1, n-1) if(n % i == 0) dividers.push_back(i);
    map<int, int> A, M;
    int ans = 0;
    for(auto x:dividers)
    {
        unordered_set<int> st;
        for(auto y:days) st.insert(y % x);
        A[x] = quick_pow(2, x - SZ(st));
        int val = A[x];
        for(auto&[k, v]:M) if(x % k == 0) val -= v;
        M[x] = val;
        ans += val;
    }
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