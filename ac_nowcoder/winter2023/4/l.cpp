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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    vector<int> v(3);
    for(auto& x:v) cin >> x;
    int length = v[0] + v[1] + v[2];
    if(length & 1)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> p = {0, 1, 2};
    function<bool(int, int, int)> check = [](int a, int b, int c) {
        vector<int> tmp = {a, b, c};
        sort(tmp.begin(), tmp.end());
        if(tmp.front() + tmp[1] > tmp.back()) return true;
        return false;
    };
    length >>= 1;
    do
    {
        int va = v[p[0]], vb = v[p[1]], vc = v[p[2]];
        int la = length - va;
        int lb = vc - la;
        int lc = vb - la;
        if(check(la, lb, lc))
        {
            cout << "YES\n";
            cout << la << ' ' << lb << ' ' << lc << endl;
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << "NO" << endl;
    
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