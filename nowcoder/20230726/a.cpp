#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5+10;
const int mod = 998244353;
int n, q;
int w[N];
struct Node
{
    int l, r;
    int sum, add;
}tr[2][N * 4];
void pushdown(int u, int op)
{
    auto &root = tr[op][u], &left = tr[op][u << 1], &right = tr[op][u << 1 | 1];
    if(root.add)
    {
        left.add += root.add, left.sum += (left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (right.r - right.l + 1) * root.add;
        left.add %= mod, right.add %= mod, left.sum %= mod, right.sum %= mod;
        root.add = 0;
    }
}
void pushup(int u, int op)
{
    tr[op][u].sum = tr[op][u << 1].sum + tr[op][u << 1 | 1].sum;
    tr[op][u].sum %= mod;
}
void build(int u, int l, int r, int op)
{
    if(l == r) tr[op][u] = {l, r, w[r], 0};
    else
    {
        tr[op][u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid, op), build(u << 1 | 1, mid + 1, r, op);
        pushup(u, op);
    }
}
void modify(int u, int l, int r, int d, int op)
{
    if(tr[op][u].l >= l && tr[op][u].r <= r)
    {
        tr[op][u].sum += (tr[op][u].r - tr[op][u].l + 1) * d;
        tr[op][u].add += d;
        tr[op][u].sum %= mod, tr[op][u].add %= mod;
    }
    else
    {
        pushdown(u, op);
        int mid = tr[op][u].l + tr[op][u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, d, op);
        if(r > mid) modify(u << 1 | 1, l, r, d, op);
        pushup(u, op);
    }
}
int query(int u, int l, int r, int op)
{
    if(tr[op][u].l >= l && tr[op][u].r <= r) return tr[op][u].sum % mod;
    pushdown(u, op);
    int mid = tr[op][u].l + tr[op][u].r >> 1;
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r, op) % mod;
    if (r > mid) sum += query(u << 1 | 1, l, r, op);
    return sum % mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    build(1, 1, n, 0);
    build(1, 1, n, 1);
    int t = 0;
    while(q --)
    {
        t ++;
        int op, l, r, w;
        cin >> op >> l >> r;
        if(!op) cin >> w;
        if(op == 0)
        {
            modify(1, l, r, w, op);
            modify(1, l, r, w * (t - 1), 1);
        }
        else
        {
            int val = query(1, l, r, 0) * t % mod;
            int tmp = query(1, l, r, 1);
            cout << (val - tmp + mod) % mod << endl;
        }
    }
    return 0;
}