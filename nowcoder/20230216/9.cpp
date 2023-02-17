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
const int N = 10 + 1e3, mod = 1e9 + 7;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    stack<int> stk;
    queue<int> q;
    rep(i, 1, n)
    {
        int x; cin >> x;
        q.push(x);
    }
    queue<int> obj;
    while(1)
    {
        if(stk.empty()) obj.push(q.front()), q.pop();
        else obj.push(stk.top()), stk.pop();
        while(1)
        {
            if(obj.size() == k || stk.size() == m && q.size() && q.front() > obj.back() || stk.size() && stk.top() > obj.back() && q.empty()) break;
            if(stk.size() && stk.top() <= obj.back())
            {
                obj.push(stk.top());
                stk.pop();
            }
            else
            {
                if(q.size() && q.front() <= obj.back())
                {
                    obj.push(q.front());
                    q.pop();
                }
                else
                {
                    if(stk.size() == m) break;
                    if(q.empty()) break;
                    stk.push(q.front());
                    q.pop();
                }
            }
        }
        while(obj.size())
        {
            cout << obj.front();
            obj.pop();
            if(obj.empty()) cout << endl;
            else cout << ' ';
        }
        if(q.empty() && stk.empty()) break;
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