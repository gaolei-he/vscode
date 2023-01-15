
#include <iostream>
using namespace std;
const int N = 3e5+10;

int p[N];
int n, m;
int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        p[find(a-1)] = find(b);
    }
    if(find(0)==find(n)) puts("Yes");
    else puts("No");
    return 0;
}