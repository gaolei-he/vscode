#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while (cin >> m)
    {
        cin >> n;
        int ans = m % (n+1);
        if(!ans) puts("none");
        else if(n < m) cout << ans << endl;
        else 
        {
            cout << m;
            for(int i=m+1;i<=n;i++) cout << ' ' << i;
            puts("");
        }
    }
    
    return 0;
}