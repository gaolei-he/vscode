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
const int N = 10 + 2e5, mod = 1e9 + 7;
void print(int l, int r)
{
    for(;l<r;l+=4)
    {
        cout << l+2 << ' ' << l + 3 << ' ' << l << ' ' << l + 1 << ' ';
    }
}
void solve()
{
    int n; cin >> n;
    set<int> st;
    rep(i, 1, 3) st.insert(i);
    st.insert(7);
    if(st.count(n))
    {
        cout << -1 << endl;
        return;
    }
    if(n % 4 == 0) print(1, n);
    else if(n % 2 == 0)
    {
        cout << "3 5 1 6 2 4 ";
        print(7, n);
    }
    else if(n % 4 == 1)
    {
        cout << "3 4 5 1 2 ";
        print(6, n);
    }
    else if(n % 4 == 3)
    {
        cout << "3 4 1 6 2 8 5 10 11 7 9 ";
        print(12, n);
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