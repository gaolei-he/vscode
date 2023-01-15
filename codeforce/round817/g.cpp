#include <iostream>
using namespace std;
int main()
{
    int t1 = 0, t2 = 0;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int tmp = n % 4;
        switch (tmp)
        {
        case 0:
            for(int i=1;i<n;i++) printf("%d ", i);
            puts("0");
            break;
        case 1:
            printf("0");
            for(int i=2;i<=n;i++) printf(" %d", i);
            puts("");
            break;
        case 2:
            for(int i=1;i<=n-3;i++) printf("%d ", i);
            puts("")
        case 3:
            for(int i=1;i<=n;i++) printf("%d ", i);
            puts("");
            break;
        default:
            break;
        }
    }
    
    return 0;
}