#include <iostream>
using namespace std;
typedef long long ll;
int f[500001];
int main()
{
    for(int i=1;i<=500000;i++)
    {
        int ans = 1;
        int tmp = i;
        for(int j=2;j<=tmp/j;j++)
        {
            int cnt = 0;
            if(tmp % j == 0)
            {
                
                while(tmp % j == 0) tmp /= j, cnt ++;
            }
            ll t = 1;
            while(cnt--) t = t * j + 1;
            ans *= t;
        }
        if(tmp > 1) ans *= (1 + tmp);
        f[i] = ans;
    }
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", f[n] - n);
    }
    return 0;
}
