#include <iostream>
using namespace std;
int g[5010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=i;j++)
            if(i%j == 0) g[i] ++;
    }
    
    
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int ans = a;
        for(int i=a+1;i<=b;i++) if(g[i] > g[ans]) ans = i;
        cout << ans << endl;
    }
    
    return 0;
}