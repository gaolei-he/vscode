#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int w[N];
struct Node
{
    int l, r, sum, d;
} tr[N * 4];

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.d = __gcd(l.d, r.d);
}
void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        int b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
    }
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
    {
        int b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
Node query(int u, int l, int r)
{
    if (l > r)
        return {0};
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid)
            return query(u << 1, l, r);
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}
signed main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    build(1, 1, n);

    int l, r, d;
    char op[2];
    while (m--)
    {
        scanf("%s %lld %lld", op, &l, &r);
        if (*op == 'Q')
        {
            auto left = query(1, 1, l), right = query(1, l + 1, r);
            printf("%lld\n", abs(__gcd(left.sum, right.d)));
        }
        else
        {
            scanf("%lld", &d);
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        }
    }

    return 0;
}