#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char str[12][12];
        memset(str, 0, sizeof(str));
        for(int i=1;i<=8;i++) scanf("%s", str[i] + 1);
        for(int i=1;i<=8;i++)
        {
            for(int j = 1;j<=8;j++)
            {
                if(str[i][j] == '#' && str[i-1][j-1] == '#' && str[i-1][j+1]=='#')
                {
                    if(str[i+1][j-1]=='#'&&str[i+1][j+1]=='#')
                    {
                        cout << i << ' ' << j << endl;
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}