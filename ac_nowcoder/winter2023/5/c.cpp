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
string a, b;
char check(queue<char> q1, queue<char> q2, char op)
{
    while(q1.size() && q1.front() == op) q1.pop();
    while(q2.size() && q2.front() == op) q2.pop();
    int l1 = a.size(), l2 = b.size(), l3 = q1.size(), l4 = q2.size();
    if((l1-l2)*(l3-l4) < 0) return '!';
    else if(q1.size() != q2.size()) return (q1.size() > q2.size()) ? '>' : '<';
    while(q1.size() && q2.size())
    {
        if(q1.front() == q2.front()) q1.pop(), q2.pop();
        else
        {
            if(q1.front() == op) return '<';
            else if(q2.front() == op) return '>';
            else return '!';
        }
    }
    return '!';
}
void solve()
{
    
    cin >> a >> b;
    char ans = '!';
    queue<char> q1, q2;
    for(auto i:a) q1.push(i);
    for(auto i:b) q2.push(i);
    if(a.size() == b.size())
    {
        ans = '=';
        rep(i, 0, a.size()-1) if(a[i] != b[i]) ans = '!';
    }
    else
    {
        if(a.size() > b.size()) ans = '>';
        else if(a.size() < b.size()) ans = '<';
        
        char res = check(q1, q2, q1.front());
        if(res != ans) ans = '!';
        res = check(q1, q2, q2.front());
        if(ans != '!' && res != ans) ans = '!';
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