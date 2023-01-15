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
const int N = 220;
int w[N], v[N], s[N];
int f[N][N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, 0 , sizeof(f));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d %d %d", &v[i], &w[i], &s[i]);

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                for(int k=0;k<=s[i]&&k*v[i]<=j;k++)
                    f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]);
        cout << f[m][n] << endl;
    }
    
    return 0;
}