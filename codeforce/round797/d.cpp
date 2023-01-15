#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if(s[i] == 'W') ans ++;
        }
        int f[n], tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'W') tmp ++;
            f[i] = tmp;
        }
        
        for (int i = k; i < n; i++)
        {
            ans = min(ans, f[i]- f[i-k]);
        }
        cout << ans << endl;
    }
    
    return 0;
}