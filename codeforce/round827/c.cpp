#include <iostream>
using namespace std;
char str[20][20];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char ans = '.';
        for(int i=1;i<=8;i++) scanf("%s", str[i] + 1);
        for(int i=1;i<=8;i++)
        {
            bool flag = true;
            for(int j=1;j<=8;j++) if(str[i][j] != 'R') flag = false;
            if(flag) ans = 'R';
        }
        for(int i=1;i<=8;i++)
        {
            bool flag = true;
            for(int j=1;j<=8;j++) if(str[j][i] != 'B') flag = false;
            if(flag) ans = 'B';
        }
        cout << ans << endl;
    }
    
    return 0;
}