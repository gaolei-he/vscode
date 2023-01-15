#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        scanf("%d %d", &row, &col);
        char str[row][col+1];
        for(int i=0;i<row;i++) scanf("%s", str[i]);
        int x = 0, y = 0;

        if(str[x][y] == 'R')
        {
            puts("YES");
            continue;
        }
        while(1)
        {
            int ret = 0;
            for(int i=0;i<col;i++) if(str[x][i] == 'R') ret = 1;
            if(ret) break;
            x ++;
        }
        while(1)
        {
            bool ret = false;
            for(int i=0;i<row;i++) if(str[i][y] == 'R') ret = true;
            if(ret) break;
            y ++;
        }
        if(str[x][y] == 'R')
        {
            puts("YES");
            continue;
        }
        else puts("NO");
        
    }

    
    return 0;
}