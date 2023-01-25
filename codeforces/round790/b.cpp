#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        int a[t];
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+t);
        int ans = 0;
        for(int i=1;i<t;i++) ans += a[i] - a[0];
        cout << ans << endl;
        
    }
    
    return 0;
}