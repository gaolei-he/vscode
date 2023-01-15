#include <iostream>
using namespace std;

const int N = 10;
int a[N], b[N];
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);

    int i = 0, j = m - 1;
    for(;i<n;i++)
    {
        
        while(a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x)
        {
            printf("%d %d", i, j);
            break;
        }
    }
    return 0;
}