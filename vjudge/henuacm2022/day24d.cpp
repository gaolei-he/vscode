#include <iostream>
#include <cmath>
#include <algorithm>
#define lowbit(x) (x & -x)
using namespace std;
const int N = 5e5+10;
int f[N][25], g[N][25];
int lg[N];
int n, q, GCD;
bool check(int mid)
{
    for(int i=1;i<=(n>>1);i++)
    {
        int a = i, b = i + mid;
        int s = lg[b-a+1];
        if(__gcd(f[a][s], f[b-(1<<s)+1][s]) != GCD) return false;
    }
    return true;

}
int main()
{
    int t;
    cin >> t;
    lg[1] = 0, lg[2] = 1;
        for(int i=3;i<N;i++) if(lowbit(i) == i) lg[i] = lg[i-1] + 1; else lg[i] = lg[i-1];
    while (t--)
    {
        
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d", &x);
            f[i][0] = x;
            f[i+n][0] = x;
        }
        
        n <<= 1;
        int ed = 25;
        for(int j=1;j<=ed;j++)
            for(int i=1;i+(1<<j)-1 <= n;i++)
            {
                f[i][j] = __gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]);

            }
        
        {
            int a = 1, b = n / 2;
            int s = lg[b-a+1];
            GCD = __gcd(f[a][s], f[b-(1<<s)+1][s]);
            //cout << '#' << GCD << endl;
        }
        int l = 0, r = n / 2;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;

    }
    
    
    return 0;
}