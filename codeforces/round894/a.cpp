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
const int N = 10 + 20, mod = 1e9 + 7;
char str[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> str[i] + 1;
    string s = "vika";
    queue<char> q;
    for(auto c : s) q.push(c);
    rep(j, 1, m)
    {
        bool flag = false;
        if(q.empty()) break;
        rep(i, 1, n) if(str[i][j] == q.front()) flag = true;
        if(flag) q.pop();
    }
    if(q.empty()) cout << "YES" << endl;
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