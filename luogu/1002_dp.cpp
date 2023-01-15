#include <iostream>
#include <cstring>
using namespace std;
int A1, A2, B1, B2;
int sum = 0;

bool pos(int x, int y)
{
    if(x==B1&&y==B2) return true;
    else if(B1-2==x&&B2-1==y) return true;
    else if(B1-2==x&&B2+1==y) return true;
    else if(B1-1==x&&B2+2==y) return true;
    else if(B1+1==x&&B2+2==y) return true;
    else if(B1+2==x&&B2+1==y) return true;
    else if(B1+2==x&&B2-1==y) return true;
    else if(B1+1==x&&B2-2==y) return true;
    else if(B1-1==x&&B2-2==y) return true;
    else return false;
}

void dfs(int x, int y)
{
    if(pos(x, y)) return;
    else if(x==A1&&y==A2)
    {
        sum ++;
        return;
    }
    else if(x>A1||y>A2) return;
    else
    {
        dfs(x+1, y);
        dfs(x, y+1);
    }
}
int main()
{
    
    cin >> A2 >> A1 >> B2 >> B1;
    long long a[A1+1][A2+1];
    memset(a, 0, sizeof(a));
    int ret = 1;
    for(int i=0;i<=A1;i++)
    {
        if(pos(i, 0)) ret = 0;
        a[i][0] = ret;
    }
    ret = 1;
    for(int i=0;i<=A2;i++)
    {
        if(pos(0, i)) ret = 0;
        a[0][i] = ret;
    }

    for(int i=1;i<=A1;i++)
        for(int j=1;j<=A2;j++)
            if(pos(i, j)) a[i][j] = 0;
            else a[i][j] = a[i-1][j] + a[i][j-1];
    //dfs(0, 0);
    cout << a[A1][A2] << endl;

    cout << sum;
    return 0;
}