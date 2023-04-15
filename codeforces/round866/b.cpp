#include <iostream>
#include <cstring>
#include <algorithm>
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
const int N = 10 + 1e5, mod = 1e9 + 7;
int Get_Max(string& s)
{
    int t = 0;
    for(auto c:s) if(c == '0') t ++;
    if(!t) return SZ(s) / 2;
    int res = 0;
    while(s.size())
    {
        int tmp = 0;
        while(s.size() && s.back() == '1') s.pop_back(), tmp ++;
        if(tmp > res) res = tmp;
        while(s.size() && s.back() == '0') s.pop_back();
    }
    return res;
}
void solve()
{
    string s;
    cin >> s;
    s += s;
    int length = Get_Max(s);
    int size = SZ(s);
    if(length == size / 2) cout << size * size / 4 << endl;
    else cout << (length + 1) / 2 * ((length + 1) / 2 + (length + 1) % 2) << endl;
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