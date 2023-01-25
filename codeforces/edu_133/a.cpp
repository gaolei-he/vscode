#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if(n == 1)
        {
            puts("2");
            continue;
        }
        int ans = n / 3;
        if(n % 3) ans ++;
        printf("%d\n", ans);
    }
    
    return 0;
}