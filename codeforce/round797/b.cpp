#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        int ans = 2e9;
        for (int i = 0; i < n; i++)
        {
            if(a[i] && b[i]) ans = a[i] - b[i];
        }
        bool res = true;
        for (int i = 0; i < n; i++)
        {
            if(a[i] - b[i] != ans && b[i] > 0 || ans < 0)
            {
                res = false;
                puts("NO");
                break;
            }
            else if(b[i] == 0 && a[i] > ans)
            {
                res = false;
                puts("NO");
                break;
            }
        }
        if(res) puts("YES");
        
        
    }
    
    return 0;
}