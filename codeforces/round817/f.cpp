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
const int N = 60;
char str[N][N];
int dx[] = {0, 1, 2, 2, 2, 2, 1, 0, -1, -1, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 2, 2, 2, 2, 1, 0, -1};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(str, 0, sizeof(str));
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++)
            scanf("%s", str[i] + 1);
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                if(str[i][j] == '.' && str[i][j+1] == '*' && str[i+1][j] == '*' && str[i+1][j+1] == '*')
                {
                    for (int k = 0; k < 12; k++)
                    {
                        int x = i + dx[k], y = j + dy[k];
                        if(x == i-1 && y == j-1) continue;
                        else if(str[x][y] == '*') flag = false;
                        
                    }
                    str[i][j+1] = str[i+1][j] = str[i+1][j+1] = '.';
                }
                if(str[i][j] == '.') continue;
                if(str[i][j+1] == '.')
                {
                    if(str[i+1][j] == str[i+1][j+1] && str[i+1][j] == '*')
                    {
                        for (int k = 0; k < 12; k++)
                        {
                            int x = i + dx[k], y = j + dy[k];
                            if(x == i-1 && y == j + 2) continue;
                            else if(str[x][y] == '*') flag = false;
                        }
                        
                    }
                    else flag = false;
                    str[i][j] = str[i+1][j+1] = str[i+1][j] = '.';
                }
                else if(str[i+1][j] == '.')
                {
                    if(str[i][j+1] == '*' && str[i+1][j+1] == '*')
                    {
                        for (int k = 0; k < 12; k++)
                        {
                            int x = i + dx[k], y = j + dy[k];
                            if(x == i+2 && y == j-1) continue;
                            else if(str[x][y] == '*') flag = false;
                        }
                        
                    }
                    else flag = false;
                    str[i][j] = str[i+1][j+1] = str[i][j+1] = '.';
                }
                else if(str[i+1][j+1] == '.')
                {
                    if(str[i][j+1] == '*' && str[i+1][j] == '*')
                    {
                        for (int k = 0; k < 12; k++)
                        {
                            int x = i + dx[k], y = j + dy[k];
                            if(x == i+2 && y == j+2) continue;
                            else if(str[x][y] == '*') flag = false;
                        }
                        
                    }
                    else flag = false;
                    str[i][j] = str[i][j+1] = str[i+1][j] = '.';
                }
                else flag = false;
                // if(!flag) cout << i << ' ' << j << endl;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    
    return 0;
}