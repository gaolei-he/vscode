#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[4];
        for(int i=0;i<4;i++) scanf("%d", &a[i]);
        int ans = 0;
        for(int i=1;i<4;i++) if(a[i] > a[0]) ans ++;
        cout << ans << endl;
    }
    
    return 0;
}