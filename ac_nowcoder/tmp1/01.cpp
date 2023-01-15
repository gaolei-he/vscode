#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d %d", &x, &y, &n);
        int p = n % x;
        if(p>=y) printf("%d\n", n-(p-y));
        else
        {
            int ans = n + (y-p) - x;
            printf("%d\n", ans);
        }

        
    }
    
    return 0;
}