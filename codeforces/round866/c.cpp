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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
bool sta[N];
int get_mex(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int mex = vec.size();
    for (int i = 0; i < vec.size(); i++)
        if(vec[i] != i)
            return i;
    return SZ(vec);
}
int get_max(vector<int>& vec)
{
    int mx = 0;
    for(auto x:vec) mx = max(mx, x);
    return mx;
}
bool check(vector<int>& vec, int mex)
{
    unordered_set<int> st;
    for(auto x:vec)
    {
        if(st.find(x) != st.end()) return true;
        else if(x > mex + 1) return true;
        else st.insert(x);
    }

    return false;
}
void solve()
{
    int n; cin >> n;
    rep(i, 0, n - 1) sta[i] = false;
    vector<int> vec(n);
    for(auto& x:vec) cin >> x;
    int mex = get_mex(vec);
    bool flag = true;
    rep(i, 0, n - 1) if(vec[i] == mex + 1) sta[i] = true, flag = false;
    if(flag)
    {
        if(check(vec, mex)) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    int l = 0, r = n - 1;
    rep(i, 0, n - 1) if(sta[i]) r = i;
    dec(i, n-1, 0) if(sta[i]) l = i;
    rep(i, l, r) vec[i] = mex;
    if(get_mex(vec) == mex + 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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