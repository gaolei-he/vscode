#include <iostream>
using namespace std;
const int N = 33;
char maps[N][N];
int n;
void f(int i, int j)
{
    maps[i][j] = '3';
    if(maps[i-1][j-1]=='0') f(i-1, j-1);
    if(maps[i-1][j]=='0') f(i-1, j);
    if(maps[i-1][j+1]=='0') f(i-1, j+1);
    if(maps[i][j-1]=='0') f(i, j-1);
    if(maps[i][j+1]=='0') f(i, j+1);
    if(maps[i+1][j-1]=='0') f(i+1, j-1);
    if(maps[i+1][j]=='0') f(i+1, j);
    if(maps[i+1][j+1]=='0') f(i+1, j+1);
    return;

}

int main()
{
    cin >> n;
    for(int i=2;i<=n+1;i++)
        for(int j=2;j<=n+1;j++)
        {
            int x;
            scanf("%d", &x);
            if(x) maps[i][j] = '1';
            else maps[i][j] = '0';
        }
    
    for(int i=1;i<=n+2;i++) maps[1][i] = '0';
    for(int i=1;i<=n+2;i++) maps[i][1] = '0';
    for(int i=1;i<=n+2;i++) maps[i][n+2] = '0';
    for(int i=1;i<=n+2;i++) maps[n+2][i] = '0';
    f(1, 1);
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
            if(maps[i][j]=='3') cout << "0 ";
            else if(maps[i][j]=='1') cout << "1 ";
            else cout << "2 ";
        puts("");
    }
    return 0;
}