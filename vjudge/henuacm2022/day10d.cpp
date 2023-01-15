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
            puts("Yes");
            for (int i = 0; i < m; i++)
            {
                int tmp = a[i] ^ sum;
                if(a[i] >= tmp) printf("%d %d\n", a[i], tmp);
            }
            
        }
        else puts("No");
        
    }
    
    return 0;
}