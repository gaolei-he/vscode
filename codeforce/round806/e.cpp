#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 110;
int a[N][N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%1d", &a[i][j]);
        
        if(n & 1)
        {
            int ans = 0;
            
            for(int i=1;i<=n/2;i++)
            {
                int cnt0 = 0, cnt1 = 0;
                if(a[n/2+1][i]) cnt1++; else cnt0 ++;
                if(a[i][n/2+1]) cnt1++; else cnt0 ++;
                if(a[n/2+1][n-i+1]) cnt1 ++; else cnt0 ++;
                if(a[n-i+1][n/2+1]) cnt1 ++; else cnt0 ++;
                if(cnt0 == 0 || cnt1 == 0) continue;
                else ans += min(cnt1, cnt0);
            }

            for(int i=1;i<=n/2;i++)
            {
                for(int j=1;j<=n/2;j++)
                {
                    int t1 = 0, t0 = 0;
                    if(a[i][j]) t1 ++; else t0 ++;
                    if(a[j][n+1-i]) t1 ++; else t0 ++;
                    if(a[n-i+1][n-j+1]) t1 ++; else t0 ++;
                    if(a[n-j+1][i]) t1 ++; else t0 ++;
                    if(t0 == 0 || t1 == 0) continue;
                    else ans += min(t1, t0);
                }
            }
            printf("%d\n", ans);
            
        }
        else
        {
            int ans = 0;
            for(int i=1;i<=n/2;i++)
            {
                for(int j=1;j<=n/2;j++)
                {
                    int t1 = 0, t0 = 0;
                    if(a[i][j]) t1 ++; else t0 ++;
                    if(a[j][n+1-i]) t1 ++; else t0 ++;
                    if(a[n-i+1][n-j+1]) t1 ++; else t0 ++;
                    if(a[n-j+1][i]) t1 ++; else t0 ++;
                    if(t0 == 0 || t1 == 0) continue;
                    else ans += min(t1, t0);
                }
            }
            printf("%d\n", ans);
        }
    }
    
    return 0;
}