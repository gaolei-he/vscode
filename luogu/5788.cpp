#include <iostream>
#include <stack>
#define rep(i, a, n) for (int i=(a);i<=(n); ++i)
#define dec(i, n, a) for (int i=(n);i>=(a); --i)
using namespace std;
const int N = 3e6+10;
int f[N], a[N];
int main()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    stack<int> stk;
    dec(i, n, 1)
    {
        while(stk.size() && a[stk.top()] <= a[i]) stk.pop();
        if(stk.size()) f[i] = stk.top();
        stk.push(i);
    }
    rep(i, 1, n) cout << f[i] << ' ';
    return 0;
}