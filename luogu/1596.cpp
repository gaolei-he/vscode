#include <iostream>
using namespace std;
const int N = 109;
char maps[N][N];

void f(int i, int j)
{
    maps[i][j] = '.';
    if(maps[i-1][j-1]=='W') f(i-1, j-1);
    if(maps[i-1][j]=='W') f(i-1, j);
    if(maps[i-1][j+1]=='W') f(i-1, j+1);
    if(maps[i][j-1]=='W') f(i, j-1);
    if(maps[i][j+1]=='W') f(i, j+1);
    if(maps[i+1][j-1]=='W') f(i+1, j-1);
    if(maps[i+1][j]=='W') f(i+1, j);
    if(maps[i+1][j+1]=='W') f(i+1, j+1);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i=0;i<n;i++) cin >> maps[i+1]+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(maps[i][j]=='W')
            {
                f(i, j);
                ans ++;
            }
        }
    cout << ans;
    return 0;
}