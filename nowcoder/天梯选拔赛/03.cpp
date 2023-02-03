#include <iostream>
#include <cstring>
bool ans[1003][1003], tmp[1003][1003];
int n, m;
using namespace std;

bool f(int x, int tmp, int y)
{
    for(int i=1;i<=n;i++)
    {
        if(tmp==y) return true;
        else if(ans[tmp][i]) f(x, i, y);
    }
}

int main()
{
    
    cin >> n >> m;
    //bool ans[n+1][n+1];
    //memset(ans, 0, sizeof(ans));
    for(int i=0;i<m;i++)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        ans[num1][num2] = true;
        ans[num2][num1] = true;
    }
    for(int i=1;i<n;i++)
    for(int j=2;j<=n;j++)
    {
        memcpy(tmp, ans, sizeof(ans));
        f(i, j);
        if(f(i, i, j))
        {
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
    return 0;
}