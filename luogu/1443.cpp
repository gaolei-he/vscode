#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
int n, m, x1, y11;
const int N = 410;
int tu[N][N];
int tt, hh;
typedef pair<int, int> PII;
PII q[N*N];

void bfs()
{
    q[0] = {x1, y11};
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    tu[x1][y11] = 0;
    while (hh<=tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x>=0 && x<n && y>=0 && y<m && tu[x][y]==-1)
            {
                tu[x][y] = tu[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
            
        }
        
    }
    
}

int main()
{
    memset(tu, -1, sizeof(tu));

    cin >> n >> m >> x1 >> y11;
    x1 --, y11 --;
    bfs();
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(5) << left << tu[i][j];
        }
        putchar(10);
        
    }
}