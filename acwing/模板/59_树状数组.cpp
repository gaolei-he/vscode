#include <iostream>
#include <cstring>
#define lowbit(x) (x & -x)
using namespace std;
const int N = 1e5+10;
int tr[N];
int n;
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
char str[20];
int sum(int x)
{ 
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
int main()
{
    int t, cnt = 0;
    cin >> t;
    while (t--)
    {
        cnt ++;
        printf("Case %d:\n", cnt);
        memset(tr, 0, sizeof(tr));
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d", &x);
            add(i, x);
        }
        while(1)
        {
            scanf("%s", str);
            char op = str[0];
            if(op == 'E') break;
            int i, j;
            scanf("%d %d", &i, &j);
            if(op == 'A') add(i, j);
            else if(op == 'S') add(i, -j);
            else printf("%d\n", sum(j)-sum(i-1));
        }
    }
    
    return 0;
}