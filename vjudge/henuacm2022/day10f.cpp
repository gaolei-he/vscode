#include <iostream>
using namespace std;
const int N = 2e5+10;
int a[N];
int main()
{
    
    int m;
    while (cin >> m)
    {
        int sum = 0;
        if(!m) break;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
            sum ^= a[i];
        }
        if(sum)
        {
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                int tmp = a[i] ^ sum;
                if(a[i] >= tmp) ans ++;
            }
            printf("%d\n", ans);
        }
        else puts("0");
        
    }
    
    return 0;
}