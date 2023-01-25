#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0;
    int n;
    cin >> n;
    while (n--)
    {
        a = b = 0;
        for(int i=0;i<3;i++)
        {
            int x;
            scanf("%1d", &x);
            a += x;
        }
        for(int i=0;i<3;i++)
        {
            int x;
            scanf("%1d", &x);
            b += x;
        }
        if(a==b) puts("YES");
        else puts("NO");
    }
    
    return 0;
}