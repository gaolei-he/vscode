#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
            
        }
        sort(a.begin(), a.end());
        int ma = 0, ans = 0;
        a.push_back(2e9);
        for(int i=0;i<n;i++)
        {
            int j = i;
            while (a[j]==a[i]) j++;
            int cnt = count(a.begin(), a.end(), a[i]);
            if(cnt>=k) ma += a[j-1]-a[i];
            else
            {
                ans = max(ma, ans);
                ma = 0;
            }
            i = j;
            
        }
        cout << ma;
        
    }
    
    return 0;
}