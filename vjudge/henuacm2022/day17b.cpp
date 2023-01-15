#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int f[110][110];
const int N = 110;
int A[N], C[N];

int main()
{
    while (cin>>n>>m, n&&m)
    {
        for(int i=1;i<=n;i++) scanf("%d", &A[i]);
        for(int i=1;i<=n;i++) scanf("%d", &C[i]);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=C[i] && k*A[i]<=j;k++)
                {
                    f[i][j] = max(f[i][j], f[i-1][j-k*A[i]]+)
                }
            }
    }
    
    return 0;
}