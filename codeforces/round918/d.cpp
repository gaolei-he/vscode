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
    set<char> C = {'b', 'c', 'd'};
    set<char> V = {'a', 'e'};
    int n; cin >> n;
    string s; cin >> s;
    vector<string> vec;
    reverse(s.begin(), s.end());
    deque<char> q;
    for(auto c : s) q.push_back(c);
    while(q.size())
    {
        char a = ' ', b = ' ';
        if(q.size()) a = q.back(), q.pop_back();
        if(q.size()) b = q.back(), q.pop_back();
        if(C.count(a) and V.count(b))
        {
            string tmp;
            tmp.push_back(a);
            tmp.push_back(b);
            vec.push_back(tmp);
        }
        else if(C.count(a) and C.count(b) or C.count(a) and b == ' ')
        {
            vec.back().push_back(a);
            if(b != ' ') q.push_back(b);
        }
    }
    s = vec.back();
    vec.pop_back();
    for(auto c : vec) cout << c << ".";
    cout << s << endl;
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