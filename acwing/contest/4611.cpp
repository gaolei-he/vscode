#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10, M = 10000007;
typedef long long ll;
ll h[M];
int cnt[M];
int a[N];
int n, m;
int find(int r, int t)
{
    ll key = r * 100ll + t;
    int k = key % M;
    while(h[k] != -1 && h[k] != key)
        if(++ k == M)
            k = 0;
    if(h[k] == -1) h[k] = key;
    return k;
}
ll work()
{
    ll res = 0;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i++)
    {
        int r = a[i] % m;
        if(r) r = m - r;
        int t = 0, x = a[i];
        while(x) t ++, x /= 10;
        res += cnt[find(r, t)];
        for(int j=1, x=10;j<=10;j++, x = x * 10ll % m)
            cnt[find((ll)a[i]*x%m, j)] ++;
    }
    return res;
    
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    ll res = work();
    reverse(a, a+n);
    memset(cnt, 0, sizeof cnt);
    res += work();

    printf("%lld\n", res);
    return 0;
}