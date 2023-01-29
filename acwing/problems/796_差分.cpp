#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &a[i][j]);
    int b[n+1][m+1];
    memset(b, 0, sizeof(b));
    for(int i=1;i<=n;i++) b[i][1] = a[i][1] + b[i-1][1];
    for(int i=1;i<=m;i++) b[1][i] = a[1][i] + b[1][i-1];
    for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++)
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << b[x2][y2]  - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1] << endl;
    }
    return 0;
}