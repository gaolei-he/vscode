#include <iostream>
#include <cstring>
#define lowbit(x) (x & -x)
using namespace std;
const int N = 2e5+10;
int tr[N];
int n, m;
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        add(i, x);
        add(i+1, -x);
    }
    char op[2];
    int l, r, d, x;
    while (m--)
    {
        scanf("%s", op);
        if(*op == 'C')
        {
            scanf("%d %d %d", &l, &r, &d);
            add(l, d);
            add(r+1, -d);
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", sum(x));
        }
    }
    

    return 0;
}