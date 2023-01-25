#include <iostream>
using namespace std;
const int N = 110;
char str[2][N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s%s", str[0], str[1]);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if(str[0][i] == 'G') str[0][i] = 'B';
            if(str[1][i] == 'G') str[1][i] = 'B';
            if(str[0][i] != str[1][i]) flag = false;
        }
        if(flag) puts("YES");
        else puts("NO");
        
    }
    
    return 0;
}