#include <iostream>
using namespace std;
const int N = 5e5+10;
int p[N];
int n, q;
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> q;
    for(int i=1;i<=n;i++) p[i] = i;
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        p[find(l-1)] = find(r);
    }
    if(find(0) == find(n)) puts("Yes");
    else puts("No");
    return 0;
}