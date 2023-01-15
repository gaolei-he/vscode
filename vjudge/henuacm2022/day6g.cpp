#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110, M = 1e4 + 10;
int h[N], e[M], w[M], ne[M], val[M], idx;
int n, r, k;
int ans = 0x3f3f3f3f;
bool st[M];
void dfs(int u, int len, int money)
{
    if (money > k)
        return;
    else if (len > ans)
        return;
    if (u == n)
        ans = len;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        st[j] = true;
        dfs(j, len + val[i], money + w[i]);
        st[j] = false;
    }
}

void add(int a, int b, int l, int v)
{
    e[idx] = b, ne[idx] = h[a];
    val[idx] = l, w[idx] = v;
    h[a] = idx++;
}

int main()
{
    cin >> k >> n >> r;
    memset(h, -1, sizeof(h));
    while (r--)
    {
        int s, d, l, t;
        scanf("%d %d %d %d", &s, &d, &l, &t);
        add(s, d, l, t);
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}