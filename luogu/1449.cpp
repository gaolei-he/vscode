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
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    function<int(int, int, char)> calc = [](int a, int b, char op)
    {
        switch (op)
        {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 1ll;
        }
    };
    stack<int> stk1, stk2;
    char tmp;

    int num;
    while(true)
    {
        char op = cin.peek();
        if(op == '@') break;
        else if (op == '.') cin >> tmp;
        else if (op >= '0' && op <= '9')
        {
            cin >> num;
            stk1.push(num);
        }
        else
        {
            cin >> tmp;
            int a = stk1.top();
            stk1.pop();
            int b = stk1.top();
            stk1.pop();
            stk1.push(calc(b, a, tmp));
        }

        
    }
    cout << stk1.top();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}