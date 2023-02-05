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
    string ans;
    cin >> ans;
    if(ans.back() == 'a' && ans.front() == 'a')
    {
        cout << "a ";
        rep(i, 1, SZ(ans)-2) cout << ans[i];
        cout << " a";
    }
    else if(ans.back() == 'b' && ans.front() == 'b')
    {
        cout << "b ";
        rep(i, 1, SZ(ans)-2) cout << ans[i];
        cout << " b";
    }
    else if(ans.front() == 'a' && ans.back() == 'b')
    {
        int pos = 0;
        rep(i, 1, SZ(ans)-2) if(ans[i] == 'b') {pos = i; break;}
        if(pos)
        {
            rep(i, 0, pos-1) cout << ans[i];
            cout << ' ';
            rep(i, pos, SZ(ans)-2) cout << ans[i];
            cout << " b";
        }
        else
        {
            rep(i, 0, SZ(ans)-3) cout << 'a';
            cout << " a b";
        }
    }
    else
    {
        int pos = 0;
        rep(i, 1, SZ(ans)-2) if(ans[i] == 'a') {pos = i; break;}
        if(pos)
        {
            rep(i, 0, pos-1) cout << ans[i];
            cout << " a ";
            rep(i, pos+1, SZ(ans)-1) cout << ans[i];
        }
        else
        {
            cout << "b ";
            rep(i, 1, SZ(ans)-2) cout << ans[i];
            cout << " a";
        }
    }
    cout << endl;
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