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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int quick_pow(int a, int b, int p)
{
    int res = 1;
    a %= p;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
void solve()
{
    cout << INT64_MAX << endl;
    cout.flush();
    string s;
    cin >> s;
    vector<int> vec;
    int ans = 0;
    stack<char> stk;
    while(s.back() != '=')
    {
        stk.push(s.back());
        s.pop_back();
    }
    while(stk.size())
    {
        ans *= 10;
        ans += stk.top() - '0';
        stk.pop();
    }
    s.pop_back();
    for (int i = 0; i < s.size(); i++)
    {
        int tmp = 0;
        while(s[i] != '?' && i < s.size()) tmp *= 10, tmp += s[i++] - '0';
        vec.push_back(tmp);
    }

    vector<int> ops;
    function<int(int, int, int)> calc = [&](int a, int b, int op) {
        if(op == 0) return a + b;
        else if(op == 1) return a - b;
        else return quick_pow(a, a, b);
    };
    bool flag = false;
    function<void(void)> work = [&]() {
        stack<int> nums;
        dec(i, vec.size()-1, 0) nums.push(vec[i]);
        for(auto i:ops)
        {
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            if((a <= 0 || b <= 0) && i == 2) return;
            nums.push(calc(a, b, i));
        }
        if(nums.top() == ans)
        {
            for(int i=0;i<vec.size();i++)
            {
                cout << vec[i];
                if(i < ops.size())
                {
                    switch (ops[i])
                    {
                    case 0: cout << "+"; break;
                    case 1: cout << "-"; break;
                    case 2: cout << "#"; break;
                    default: break;
                    }
                }
            }
            cout << "=" << ans << endl;
            flag = true;
        }
    };
    function<void(void)> dfs = [&]() {
        rep(i, 0, 2)
        {
            if(flag) return;
            ops.push_back(i);
            if(ops.size() == vec.size() - 1) work();
            else dfs();
            ops.pop_back();
        }
    };
    dfs();
    if(!flag) cout << "-1\n";
    
    
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