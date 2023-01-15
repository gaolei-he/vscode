//差分+贪心完美解决
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    int s[n+1];
    s[0] = 0;
    for(int i=1;i<=n;i++) s[i] = a[i] - a[i-1];
    int j = n;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>0)
        {
            while(s[j]>=0&&j!=0) j--;
            if(j==0) break;
            int tmp = s[i] + s[j];
            ans += min(abs(s[i]), abs(s[j]));
            if(tmp>0) s[i--] = tmp, s[j] = 0;
            else s[i] = 0, s[j] = tmp;
        }
    }
    for(int i=1;i<=n;i++) ans += abs(s[i]);
    cout << ans;
    return 0;
}