#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, m;
double f[10010];

struct Sc
{
    int w;
    double p;
}sc[10010];

int main()
{
    while (1)
    {
        
        scanf("%d %d", &n, &m);
        for(int i=0;i<=n;i++) f[i] = 1;
        if(m == 0 && n == 0) break;
        int tmp1;
        double tmp2;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %lf", &tmp1, &tmp2);
            sc[i].w = tmp1, sc[i].p = tmp2;
        }
        for(int i=1;i<=m;i++)
            for(int j=n;j>=sc[i].w;j--)
            {
                f[j] = min(f[j], f[j-sc[i].w] * (1 - sc[i].p));
            }
        printf("%.1f%%\n", 100 - f[n]*100);
    }
    
    return 0;
}