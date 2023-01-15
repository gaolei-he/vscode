#include <iostream>
using namespace std;
char str[110][110];
char ans[110][110];
int main()
{
    char op = 'B';
    for(int i=1;i<=100;i++)
    {
        if(str[i-1][1] == 'B') op = 'W';
        else op = 'B';
        for(int j=1;j<=100;j++)
        {
            str[i][j] = op;
            if(op == 'B') op = 'W';
            else op = 'B';
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%s", ans[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j] == '-') printf("-");
            else printf("%c", str[i][j]);
        }
        puts("");
    }

    return 0;
}