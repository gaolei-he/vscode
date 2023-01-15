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
const int N = 110;
int f[N];
int w[N][N];
int main()
{
    while(cin >> n >> m)
    {
        memset(f, 0, sizeof(f));
        if(n == 0 && m == 0) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d", &w[i][j]);
        
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                for(int k=1;k <= j;k++)
                    if(j>=1) f[j] = max(f[j], f[j-k]+w[i][k]);
        cout << f[m] << endl;
    }
    return 0;
}