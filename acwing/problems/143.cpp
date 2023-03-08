// #include <iostream>
// using namespace std;
// const int N = 1e5+10;
// int son[N][2], cnt[N];
// int idx, a[N];
// char s[33];
// void insert(char str[])
// {
//     int p = 0;
//     for (int i = 0; str[i] ; i++)
//     {
//         int u = str[i] - '0';
//         if(!son[p][u]) son[p][u] = ++ idx;
//         p = son[p][u];
//     }
//     cnt[p] = true;
    
// }
// inline void get(int x)
// {
//     for(int i=0;i<32;i++)
//     {
//         if((1<<31-i)&x) s[i] = '1';
//         else s[i] = '0';
//     }
// }
// inline int f()
// {
//     int p = 0;
//     int ans = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         int u = s[i] - '0';
//         u = u ? 0 : 1;
//         if(!son[p][u]) p = son[p][u?0:1];
//         else
//         {
//             p = son[p][u];
//             ans |= (1<<31-i);
//         }
//     }
//     return ans;
    
// }

// int main()
// {
//     int n, ans = 0;
//     cin >> n;
    
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//         get(a[i]);
//         insert(s);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         get(a[i]);
//         ans = max(ans, f());
//     }
//     cout << ans;
//     return 0;
// }
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
const int N = 10 + 1e7, mod = 1e9 + 7;
int son[N][2], cnt[N], idx;
void insert(string s)
{
    int p = 0;
    for(auto c:s)
    {
        int u = c - '0';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
string query(string s)
{
    string res = "";
    int p = 0;
    for(auto c:s)
    {
        int u = c - '0';
        u = u ? 0 : 1;
        if(son[p][u]) res.push_back(u + '0'), p = son[p][u];
        else res.push_back((u ? 0 : 1) + '0'), p = son[p][u ? 0 : 1];
    }
    return res;
}
string to_binary(int x)
{
    string res = "";
    dec(i, 31, 0) res.push_back(((x >> i) & 1) + '0');
    return res;
}
int to_int(string s)
{
    int res = 0;
    for(auto c:s)
    {
        res <<= 1;
        res += c - '0';
    }
    return res;
    cerr << res << endl;
}
void solve()
{
    int n; cin >> n;
    vector<int> vec(n);
    for(auto& x:vec) cin >> x;
    for(auto& x:vec) insert(to_binary(x));
    int ans = 0;
    for(auto x:vec)
    {
        
        ans = max(ans, x ^ to_int(query(to_binary(x))));
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