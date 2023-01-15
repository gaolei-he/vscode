#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define int long long
#define lowbit(x) ((x) & -(x))
#define inf 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a);i<=(n);++i)
#define dec(i, n, a) for (int i=(n);i>=(a);--i)
using namespace std;
typedef pair<int, int> pii;
const int N = 1e6+10;
int a[N];
pii b[N];
bool cmp(pii &a, pii &b)
{
    return a.first < b.first;
}
int tr[N];
int n;
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
char str[20];
int sums(int x)
{ 
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
int c[N], d[N];
int ans = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        b[i].first = a[i];
    }
    int sum = 0;
    sort(b+1, b+1+n, cmp);
    rep(i, 1, n) b[i].second = i;

    rep(i, 1, n)
    {
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(b[mid].first > a[i]) r = mid - 1;
            else l = mid;
        }
        c[i] = sums(n) - sums(l);
        add(b[l].second, 1);
    }
    memset(tr, 0, sizeof(tr));
    dec(i, n, 1)
    {
        
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(b[mid].first > a[i]) r = mid - 1;
            else l = mid;
        }
        d[i] = sums(l);
        add(b[l].second, 1);
    }
    rep(i, 1, n) ans += c[i] * d[i];
    cout << ans << endl;
    return 0;
}