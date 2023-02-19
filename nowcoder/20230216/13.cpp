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
int deg[N];
void solve()
{
    int n; cin >> n;
    unordered_map<string, int> mp;
    vector<string> a, b;
    unordered_set<string> total;
    int cnt = 0;
    vector<vector<int>> g(n+1);
    rep(i, 1, n)
    {
        // for(auto s:a) cerr << s << '.';
        // cerr << endl;
        // for(auto s:b) cerr << s << '.';
        // cerr << endl;
        a.clear();
        for(auto s:b) a.push_back(s);
        b.clear();
        string s; cin >> s;
        string t;
        for(auto c:s)
        {
            if(c == '.') b.push_back(t), t = "";
            else t = t + c;
        }
        b.push_back(t);
        for(auto s:a) total.insert(s);
        for(auto s:b) total.insert(s);
        if(a.size() != b.size()) continue;
        for (int i = 0; i < a.size(); i++)
        {
            if(a[i] == b[i]) continue;
            int x, y;
            if(mp.count(a[i])) x = mp[a[i]];
            else mp[a[i]] = ++ cnt, x = cnt;
            if(mp.count(b[i])) y = mp[b[i]];
            else mp[b[i]] = ++ cnt, y = cnt;
            g[x].push_back(y);
            deg[y] ++;
            break;
        }
    }
    unordered_map<int, string> dic;
    for(auto p:mp) dic[p.second] = p.first;
    priority_queue<string, vector<string>, greater<string>> pq;
    rep(i, 1, cnt) if(deg[i] == 0) pq.push(dic[i]);
    vector<string> ans;
    while(pq.size())
    {
        string str = pq.top();
        pq.pop();
        ans.push_back(str);
        int st = mp[str];
        for(auto i:g[st])
        {
            deg[i] --;
            if(deg[i] == 0) pq.push(dic[i]);
        }
    }
    for(auto s:ans) total.erase(s);
    vector<string> rem;
    for(auto s:total) rem.push_back(s);
    sort(rem.begin(), rem.end());
    queue<string> q;
    for(auto s:rem) q.push(s);
    bool flag = false;
    for (int i = 0; i < ans.size(); i++)
    {
        while(q.size() && q.front() < ans[i])
        {
            if(flag) {cout << '.';}
            else flag = true;
            cout << q.front();
            q.pop();
        }
        if(flag) cout << '.';
        else flag = true;
        cout << ans[i];
    }
    while(q.size())
    {
        if(flag) cout << '.';
        else flag = true;
        cout << q.front();
        q.pop();
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