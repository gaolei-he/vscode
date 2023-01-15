#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100][100];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j] = (i - 1) * m + j;
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m; j++)
            cout << a[i][j] << ' ';
        puts("");
    }
    return 0;
}