/*
# [ZJOI2010] 数字计数

## 题目描述

给定两个正整数 $a$ 和 $b$，求在 $[a,b]$ 中的所有整数中，每个数码(digit)各出现了多少次。

## 输入格式

仅包含一行两个整数 $a,b$，含义如上所述。

## 输出格式

包含一行十个整数，分别表示 $0\sim 9$ 在 $[a,b]$ 中出现了多少次。

## 样例 #1

### 样例输入 #1

```
1 99
```

### 样例输出 #1

```
9 20 20 20 20 20 20 20 20 20
```

## 提示

#### 数据规模与约定

- 对于 $30\%$ 的数据，保证 $a\le b\le10^6$；
- 对于 $100\%$ 的数据，保证 $1\le a\le b\le 10^{12}$。
*/
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
int mypow(int x, int n)
{
    int res = 1;
    while(n--)
        res *= x;
    return res;
}
// 给定一个数x，求0~x的第i位上有多少个dig，位数从1开始
int calc(int x, int i, int dig)
{
    int k = 0;
    if(!dig) k = -1;
    int res = 0;
    int vr = x % mypow(10, i - 1);
    int vl = x / mypow(10, i);
    int op = x % mypow(10, i) / mypow(10, i - 1);
    if(op > dig)
        res += (vl + 1 + k) * mypow(10, i - 1);
    else if(op == dig)
        res += (vl + k) * mypow(10, i - 1) + vr + 1;
    else if(op < dig)
        res += (vl + k) * mypow(10, i - 1);
    return res;
}
// 给定一个数x，求0~x的每一位上有多少个dig
int f(int x, int dig)
{
    string s = to_string(x);
    int n = s.size();
    int res = 0;
    rep(i, 1, n)
        res += calc(x, i, dig);
    return res;
}
void solve()
{
    int a, b; cin >> a >> b;
    rep(i, 0, 9)
        cout << f(b, i) - f(a - 1, i) << ' ';
    cout << endl;
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