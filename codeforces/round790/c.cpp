#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        int mi = RAND_MAX;
        scanf("%d %d", &n, &m);
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int ans = 0;
                string tmp1 = s[i], tmp2 = s[j];
                for (int k = 0; k < m; k++)
                {
                    ans += abs(tmp1[k]-tmp2[k]);
                }
                mi = min(ans, mi);
            }
            
        }
        cout << mi << endl;
        
        
    }
    
    return 0;
}