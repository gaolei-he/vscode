#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[n+1];
        a[0] = 0;
        int s[n+1];
        s[0] = s[1] = 0;
        int ans = 0;

        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        for(int i=1;i<=n;i++)
        {
            s[i] = s[i-1];
            if(a[i-1] >= a[i] * 2) s[i] ++;
            
        }
        for(int i=1;i<=n-k;i++) if(s[i] == s[i+k]) ans ++;
            cout << ans << endl;
    }
    
    return 0;
}