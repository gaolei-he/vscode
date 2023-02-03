#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 10000;
char ans[N+5][N+5];
int tmp1[10] = {0, 0, 6, 12, 24, 48, 96, 192, 384, 769};
void f(int n, int x, int y)
{
    if(n==1)
    {
        ans[x][y] = '*';
        ans[x][y+2] = '*';
        ans[x][y+4] = '*';
        ans[x-1][y+1] = '*';
        ans[x-2][y+2] = '*';
        ans[x-1][y+3] = '*';
        return;
    }
    else
    {
        f(n-1, x, y);
        f(n-1, x, y+tmp1[n-1]);
        f(n-1, x-tmp1[n-1]/2, y+tmp1[n-1]/2);
    }
}

int main()
{
    memset(ans, 32, sizeof(ans));
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "  *\n * *\n* * *\n  *\n";
        return 0;
    }
    n ++;
    f(n, N, 1);
    for(int i=N-tmp1[n-1]+1;i<=N;i++)
    {
        for(int j=1;j<=tmp1[n]-1;j++)
        {
            cout << ans[i][j];
        }
        puts("");
    }
    
    n --;
    int tmp = n;
    while(tmp--)
    {
        for(int i=0;i<3*pow(2, n-1)-1;i++) cout << ' ';
        cout << "*\n";
    }
    
    return 0;
}
