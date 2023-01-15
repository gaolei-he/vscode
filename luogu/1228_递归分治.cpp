#include <iostream>
#include <cstring>
using namespace std;
int matrix[1023][1023];

int xi1, yi1;

int mypow(int x, int y)
{
    y--;
    while(y--)
        x *= 2;
    return x;
}
void solve(int k, int x, int y, int xi, int yi)
{
    if(k==1)
    {
        if(matrix[x+1][y+1])
        {
            matrix[x+2][y+1] = 1+4;
            matrix[x+1][y+2] = 1+4;
            matrix[x+2][y+2] = 1;
            
        }
        else if(matrix[x+2][y+1])
        {
            matrix[x+1][y+1] = 3+4;
            matrix[x+1][y+2] = 3;
            matrix[x+2][y+2] = 3+4;
        }
        else if(matrix[x+1][y+2])
        {
            matrix[x+1][y+1] = 2+4;
            matrix[x+2][y+1] = 2;
            matrix[x+2][y+2] = 2+4;
        }
        else 
        {
            matrix[x+1][y+1] = 4;
            matrix[x+2][y+1] = 4+4;
            matrix[x+1][y+2] = 4+4;
        }

        return;
    }
    if(xi<=x+mypow(2, k-1)&&yi<=y+mypow(2, k-1))
    {
        matrix[mypow(2, k-1)+x+1][mypow(2, k-1)+y] = 1+4;

        matrix[mypow(2, k-1)+x][mypow(2, k-1)+1+y] = 1+4;

        matrix[mypow(2, k-1)+1+x][mypow(2, k-1)+y+1] = 1;

        solve(k-1, x, y, xi, yi);
        solve(k-1, x+mypow(2, k-1), y, x+mypow(2, k-1)+1, y+mypow(2, k-1));
        solve(k-1, x, y+mypow(2, k-1), x+mypow(2, k-1), y+1+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y+mypow(2, k-1), x+mypow(2, k-1)+1, y+1+mypow(2, k-1));
    }
    else if(xi<=mypow(2, k-1)+x&&yi>y+mypow(2, k-1))
    {
        matrix[mypow(2, k-1)+x+1][mypow(2, k-1)+y] = 2;

        matrix[mypow(2, k-1)+x][mypow(2, k-1)+y] = 2+4;

        matrix[mypow(2, k-1)+1+x][mypow(2, k-1)+y+1] = 2+4;

        solve(k-1, x, y, x+mypow(2, k-1), y+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y, x+mypow(2, k-1)+1, y+mypow(2, k-1));
        solve(k-1, x, y+mypow(2, k-1), xi, yi);
        solve(k-1, x+mypow(2, k-1), y+mypow(2, k-1), x+mypow(2, k-1)+1, y+1+mypow(2, k-1));
    }
    else if(xi>x+mypow(2, k-1)&&yi<=y+mypow(2, k-1))
    {
        matrix[mypow(2, k-1)+x][mypow(2, k-1)+1+y] = 3;

        matrix[mypow(2, k-1)+x][mypow(2, k-1)+y] = 3+4;

        matrix[mypow(2, k-1)+1+x][mypow(2, k-1)+y+1] = 3+4;

        solve(k-1, x, y, x+mypow(2, k-1), y+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y, xi, yi);
        solve(k-1, x, y+mypow(2, k-1), x+mypow(2, k-1), y+1+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y+mypow(2, k-1), x+mypow(2, k-1)+1, y+1+mypow(2, k-1));
    }
    else
    {
        matrix[mypow(2, k-1)+x][mypow(2, k-1)+1+y] = 4+4;

        matrix[mypow(2, k-1)+x][mypow(2, k-1)+y] = 4;

        matrix[mypow(2, k-1)+1+x][mypow(2, k-1)+y] = 4+4;

        solve(k-1, x, y, x+mypow(2, k-1), y+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y, x+mypow(2, k-1)+1, y+mypow(2, k-1));
        solve(k-1, x, y+mypow(2, k-1), x+mypow(2, k-1), y+1+mypow(2, k-1));
        solve(k-1, x+mypow(2, k-1), y+mypow(2, k-1), xi, yi);
    }
}

int main()
{
    int k;
    cin >> k;
    
    cin >> xi1 >> yi1;
    

    matrix[xi1][yi1] = 5;
    solve(k, 0, 0, xi1, yi1);
    int n = mypow(2, k);
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        switch (matrix[i][j])
        {
        case 1:
            printf("%d %d %d\n", i, j, 1);
            break;
        case 2:
            printf("%d %d %d\n", i, j, 2);
            break;
        case 3:
            printf("%d %d %d\n", i, j, 3);
            break;
        case 4:
            printf("%d %d %d\n", i, j, 4);
            break;
        default:
            break;
        }
    }
    
    return 0;
}