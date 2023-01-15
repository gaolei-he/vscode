#include <iostream>
#include <cstring>
using namespace std;
const int N = 305, M = 1000;

char ans[N+3][M+3];

void f(int x, int y)
{
    
    ans[x][y] = '*';
    ans[x][y+2] = '*';
    ans[x][y+4] = '*';
    ans[x-1][y+1] = '*';
    ans[x-2][y+2] = '*';
    ans[x-1][y+3] = '*';

}


int main()
{
    int n;
    cin >> n;
    memset(ans, 32, sizeof(ans));

    int tmp = n;
    int x = N, y = 1;
    while(tmp)
    {
        int tmp_y = y;
        for(int i=1;i<=tmp;i++)
        {
            f(x, y);
            y += 6;
        }
        x -= 3;
        y = tmp_y + 3;
        tmp --;

    }
    for(int i=N-n*3+1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cout << ans[i][j];
        }
        puts("");
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3*n-1;j++) cout << ' ';
        cout << "*\n";
    }
    return 0;
}