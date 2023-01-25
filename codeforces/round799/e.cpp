#include <iostream>
#include <vector>
using namespace std;
vector<int> ans1, ans2;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans1.clear(), ans2.clear();
        int n, sum;
        scanf("%d %d", &n, &sum);
        int a[n+1];
        int sum1 = 0;
        
        ans1.push_back(0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i]) sum1 ++;
            if(a[i]) ans1.push_back(i);
        }
        ans1.push_back(n+1);
        ans2.push_back(0);
        for(int i=n;i>0;i--)
        {
            if(a[i]) ans2.push_back(n-i+1);
        }
        ans2.push_back(n+1);
        int ans = 0;
        if(sum1 < sum) cout << -1 << endl;
        else if(sum1 == sum) cout << 0 << endl;
        else
        {
            int mi = min(ans1[sum1-sum], ans2[sum1-sum]);
            for(int i=1;i<=sum1-sum;i++) mi = min(ans1[i]+ans2[sum1-sum-i], mi);
            cout << mi << endl;
        }
        
    }
    
    return 0;
}
