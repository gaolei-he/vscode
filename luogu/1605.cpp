#include <cstring>
#include <iostream>
using namespace std;
int cnt = 0;
bool step[10][10];
int n, m, t;
int x1, y11, x2, y2;

void f(int x, int y)
{
    if(x==x2&&y==y2)
    {
        cnt ++;
        return;
    }
    step[x][y] = false;
    if(step[x-1][y]&&x-1>0) f(x-1, y);
    if(step[x+1][y]&&x+1<=n) f(x+1, y);
    if(step[x][y-1]&&y-1>0) f(x, y-1);
    if(step[x][y+1]&&y+1<=n) f(x, y+1);
    step[x][y] = true;
}

int main()
{
    
    cin >> n >> m >> t;
    bool ans[n+1][m+1];

    memset(ans, 1, sizeof(ans));
    memset(step, 1, sizeof(step));

    
    cin >> x1 >> y11 >> x2 >> y2;
    for(int i=0;i<t;i++)
    {
        int x, y;
        cin >> x >> y;
        step[x][y] = false;
    }
    f(x1, y11);

    cout << cnt;
    return 0;
}