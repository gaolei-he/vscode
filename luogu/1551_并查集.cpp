#include <iostream>
using namespace std;

const int N = 5e3+10;
int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++) p[i] = i;

    while (m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        p[find(l)] = find(r);
    }
    while (t--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        if (find(l) == find(r)) puts("Yes");
        else puts("No");
    }
    
    
}