//AcWing 243
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
const int N = 1e5+10;
int n, m;
int w[N];
struct Node
{
    int l, r;
    int sum, add;
}tr[N * 4];
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add)
    {
        left.add += root.add, left.sum += (left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, w[r], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, int d)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, d);
        if(r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}
int query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
signed main()
{
    scanf("%lld %lld", &n, &m);//n个数，m条操作
    for(int i=1;i<=n;i++) scanf("%lld", &w[i]);
    build(1, 1, n);
    char op[2];
    int l, r, d;
    while (m--)
    {
        scanf("%s %lld %lld", op, &l, &r);
        if(*op == 'C')
        {
            scanf("%lld", &d);
            modify(1, l, r, d);//操作 ‘C’，将区间[l,r]中的每个数加上d
        }
        else printf("%lld\n", query(1, l, r));//操作 ‘Q’，询问区间[l,r]中所有数的和
    }
    
    return 0;
}