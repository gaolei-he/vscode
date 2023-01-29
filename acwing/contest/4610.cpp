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
const int N = 25;
int a[N][N], b[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &a[i][j]);

    bool flag = false;
    for(int i=1;i<m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(j == i && i != 1) j ++;
            memcpy(b, a, sizeof(a));
            swap(b[1][i], b[1][j]);
            int tmp = 0;
            for(int k=1;k<=m;k++) if(b[1][k] != k) tmp ++;
            if(tmp != 2 && tmp != 0) continue;
            bool flag1 = true;
            for(int k=2;k<=n;k++)
            {
                int tmp1 = 0;
                for(int l=1;l<=m;l++) if(b[k][l] != b[1][l]) tmp1 ++;
                if(tmp1 == 0 || tmp1 == 2) continue;
                else {flag1 = false; break;}
            }
            if(flag1)
            {
                puts("YES");
                return 0;
            }
        }
    }
    if(m == 1)
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}