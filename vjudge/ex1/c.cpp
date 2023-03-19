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
const int N = 10 + 1e5, mod = 1e9 + 7;
int p[N][5];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n)
        rep(j, 1, 3)
            cin >> p[i][j];
    rep(i, 1, n)
        p[i][4] = p[i][1] + p[i][2] + p[i][3];
    vector<int> vec;
    rep(i, 1, n) vec.push_back(p[i][4]);
    sort(vec.begin(), vec.end());
    rep(i, 1, n)
    {
        int score = p[i][4] + 300;
        auto it = upper_bound(vec.begin(), vec.end(), score);
        if(vec.end() - it < k) cout << "Yes" << endl;
        else cout << "No" << endl;
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