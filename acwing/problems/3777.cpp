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
const int N = 10 + 2e2, mod = 1e9 + 7;
char str[N], str1[N];
void solve()
{
    int n; cin >> n;
    vector<int> ans;
    int num = 0;
    cin >> str + 1;
    str[0] = 'B';
    memcpy(str1, str, sizeof(str));
    rep(i, 1, n)
    {
        if(str[i] == 'W' && str[i-1] == 'W') ans.push_back(i-1), num ++, str[i] = str[i-1] = 'B';
        else if(str[i] == 'B' && str[i-1] == 'W') ans.push_back(i-1), swap(str[i-1], str[i]), num ++;
    }
    
    if(str[n] == 'W')
    {
        memcpy(str, str1, sizeof(str1));
        num = 0;
        ans.clear();
        str[0] = 'W';
        rep(i, 1, n)
        {
            if(str[i] == 'B' && str[i-1] == 'B') ans.push_back(i-1), num ++, str[i] = str[i-1] = 'W';
            else if(str[i] == 'W' && str[i-1] == 'B') ans.push_back(i-1), swap(str[i-1], str[i]), num ++;
        }
        if(str[n] == 'B')
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << num << endl;
    for(auto i:ans) cout << i << ' ';
    if(ans.size()) cout << endl;
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