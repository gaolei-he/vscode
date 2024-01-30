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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<set<char>> vec;
    string output;
    for(auto c : s)
    {
        if(vec.empty()) vec.push_back({c});
        else if(vec.back().size() < k) vec.back().insert(c);
        else vec.push_back({c});
        if(vec.back().size() == k) output.push_back(c);
    }
    int cnt = vec.size();
    if(vec.back().size() < k) cnt --;
    if(cnt >= n) cout << "YES\n";
    else
    {
        cout << "NO\n";
        for(char c='a' ;c < 'a' + k; c ++)
            if(!vec.back().count(c))
            {
                while(output.size() < n) output.push_back(c);
                cout << output << endl;
                return;
            }
        while(output.size() < n) output.push_back('a');
        cout << output << endl;
    }
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