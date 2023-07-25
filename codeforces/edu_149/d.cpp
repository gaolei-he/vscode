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
using pci = pair<char, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    {
        stack<char> st;
        for(auto c : s)
            if(st.empty()) st.push(c);
            else if(st.top() == c) st.push(c);
            else if(st.top() == '(' and c == ')') st.pop();
            else st.push(c);
        if(st.empty())
        {
            cout << 1 << endl;
            rep(i, 1, n) cout << 1 << ' ';
            cout << endl;
            return;
        }
        reverse(s.begin(), s.end());
        while(st.size()) st.pop();
        for(auto c : s)
            if(st.empty()) st.push(c);
            else if(st.top() == c) st.push(c);
            else if(st.top() == '(' and c == ')') st.pop();
            else st.push(c);
        if(st.empty())
        {
            cout << 1 << endl;
            rep(i, 1, n) cout << 1 << ' ';
            cout << endl;
            return;
        }
        reverse(s.begin(), s.end());
    }
    set<int> st1, st2;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') st1.insert(i);
        else st2.insert(i);
    }
    map<int, int> mp;
    int cnt = 0;
    int res = 0;
    vector<int> tmp;
    for (auto &x : st1)
    {
        auto it = st2.lower_bound(x);
        if(it == st2.end()) break;
        cnt = 1;
        mp[x] = cnt;
        tmp.push_back(x);
        mp[*it] = cnt;
        st2.erase(it);
    }
    for(auto x : tmp) st1.erase(x);
    tmp.clear();
    res = max(res, cnt);
    for (auto &x : st2)
    {
        auto it = st1.lower_bound(x);
        if(it == st1.end()) break;
        mp[x] = cnt ? 2 : 1;
        tmp.push_back(x);
        res = max(res, mp[x]);
        mp[*it] = cnt ? 2 : 1;
        st1.erase(it);
    }
    for(auto x : tmp) st2.erase(x);
    if(st1.empty() and st2.empty())
    {
        cout << res << endl;
        rep(i, 0, n-1) cout << mp[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
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