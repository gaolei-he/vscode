#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#define int long long
#define endl "\n"
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
const int mod = 1e9+7;
int mypow(int a, int p)
{
    int res = 1;
    while(p)
    {
        if(p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}
class Node
{
private:
    map<int, int> mp;
    vector<int> val;
public:
    Node(string s, int n, int x, vector<int> &values)
    {
        val.resize(n + 1);
        rep(i, 0, n) val[i] = values[i];
        if(s.front() == 'x' and s.substr(1) == to_string(x)) mp[1] = 1;
        else if(s.front() == 'x') mp[0] = (val[stoi(s.substr(1))] + mod) % mod;
        else mp[0] = (stol(s) + mod) % mod;
    }
    int getans(int x)
    {
        int res = 0;
        for(auto p : mp)
        {
            int k = p.first;
            int v = p.second;
            if(k == 0) continue;
            else res = (res + k * v % mod * mypow(val[x], k - 1) % mod + mod) % mod;
        }
        return res;
    }
    void calc(Node &b, string op, int x)
    {
        map<int, int> tmp;
        if(op == "+")
        {
            for(auto p : mp) 
            {
                int k = p.first;
                int v = p.second;
                tmp[k] = v;
            }
            for(auto p : b.mp) 
            {
                int k = p.first;
                int v = p.second;
                tmp[k] = (tmp[k] + v + mod) % mod;
            }
        }
        else if(op == "-")
        {
            for(auto p : mp) 
            {
                int k = p.first;
                int v = p.second;
                tmp[k] = v;
            }
            for(auto p : b.mp) 
            {
                int k = p.first;
                int v = p.second;
                tmp[k] = (tmp[k] - v + mod) % mod;
            }
        }
        else
        for(auto p1 : mp)
        {
            int k1 = p1.first;
            int v1 = p1.second;
            for(auto p2 : b.mp)
            {
                int k2 = p2.first;
                int v2 = p2.second;
                int k = (k1 + k2);
                int v = v1 * v2 % mod;
                tmp[k] = (tmp[k] + v + mod) % mod;
            }
        }
        mp = tmp;
    }

};
void solve()
{
    int n, m; cin >> n >> m;
    vector<string> vec;
    string ss, tmp;
    cin.ignore();
    getline(cin, ss);
    for(auto c : ss)
    {
        if(c == ' ') vec.push_back(tmp), tmp.clear();
        else tmp.push_back(c);
    }
    if(tmp.size()) vec.push_back(tmp);

    rep(i, 1, m)
    {
        int x; cin >> x;
        vector<int> values(n + 1, 0);
        stack<Node> stk;
        rep(i, 1, n) cin >> values[i];
        for(auto s : vec)
        {
            if(s == "+" or s == "-" or s == "*")
            {
                auto a = stk.top(); stk.pop();
                auto b = stk.top(); stk.pop();
                swap(a, b);
                a.calc(b, s, x);
                stk.push(a);
            }
            else stk.push(Node(s, n, x, values));
        }
        auto ans = stk.top();
        cout << ans.getans(x) << endl;
    }
}
signed main()
{
    solve();
    return 0;
}