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
#define lowbit(x) ((x)&(-(x)))
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int tr[N * 10];
int priority[N], a[N];
char str[N];
int p[N];
int n, m, q; 
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
void solve()
{
    cin >> n >> m >> q;
    rep(i, 1, n) p[i] = i;
    cin >> str + 1;
    vector<pii> vec(m);
    int now = 1;
    for(auto &[x, y] : vec)
    {
        cin >> x >> y;
        for(int i=x;i<=y;i++)
        {
            if(!priority[i])
            {
                int anc = 0;
                rep(j, i, y)
                {
                    if(!priority[j]) anc = j;
                    else break;
                }
                rep(j, i, y)
                {
                    if(!priority[j]) priority[j] = now, p[j] = anc, i = j;
                    else break;
                }
            }
            else i = find(i);
        }
        now ++;
    }
    rep(i, 1, n) if(!priority[i]) priority[i] = linf;
    vec.clear();
    rep(i, 1, n) vec.emplace_back(priority[i], i);
    sort(vec.begin(), vec.end());
    unordered_map<int, int> mp;
    rep(i, 1, n)
    {
        a[i] = str[vec[i-1].second] - '0';
        mp[vec[i-1].second] = i;

    }
    int tmp = 0;
    rep(i, 1, n) add(i, a[i]);
    rep(i, 1, n) if(priority[find(i)] == linf) tmp ++;
    while(q--)
    {
        int x; cin >> x;
        int pos = mp[x];
        int val;
        if(sum(pos) - sum(pos-1)) val = -1;
        else val = 1;
        add(pos, val);
        int v1 = sum(n - tmp);
        int v2 = sum(n) - sum(n - tmp);
        //cerr << v1 << ' ' << v2 << ' ' << val << endl;
        if(v1 + v2 >= n - tmp)
            cout << n - tmp - v1 << endl;
        else
        {
            int v3 = sum(v1 + v2);
            cout << v1 + v2 - v3 << endl;
        }
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