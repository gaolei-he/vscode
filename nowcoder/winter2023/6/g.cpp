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
    int n, k; cin >> n >> k;
    vector<int> v1, v2;
    int cnt = 0;
    rep(i, 1, n)
    {
        int x; cin >> x;
        if(x > 0) v1.push_back(x);
        else if(x < 0) v2.push_back(-x);
        else cnt ++;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    stack<int> stk1, stk2;
    for(auto i:v1) stk1.push(i);
    for(auto i:v2) stk2.push(i);
    int ans = 0;
    while(k)
    {
        int ma = 0;
        int a = 0, b = 0;
        if(stk1.size() > 1)
        {
            a = stk1.top();
            stk1.pop();
            b = stk1.top();
            stk1.pop();
        }
        int c = 0, d = 0;
        if(stk2.size() > 1)
        {
            c = stk2.top();
            stk2.pop();
            d = stk2.top();
            stk2.pop();
        }
        if(a*b && c*d)
        {
            if(a*b>c*d) ans += a * b, stk2.push(d), stk2.push(c);
            else ans += c * d, stk1.push(b), stk1.push(a);
        }
        else if(a*b)
        {
            ans += a * b;
            stk2.push(d);
            stk2.push(c);
        }
        else if(c*d)
        {
            ans += c * d;
            stk1.push(b);
            stk1.push(a);
        }
        else break;
        k --;
    }
    while(k--)
    {
        if(cnt&&stk1.size()) cnt--, stk1.pop();
        else if(cnt&&stk2.size()) cnt--, stk2.pop();
        else if(cnt > 1) cnt -= 2;
        else ans -= stk1.top() * stk2.top(), stk1.pop(), stk2.pop();
    }
    cout << ans << endl;

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