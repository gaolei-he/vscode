#include <iostream>
using namespace std;
const int N = 1e4+10;
bool st[N];
int phi[N], prime[N];
void f()
{
    int cnt = 0;
    phi[1] = 1;
    for(int i=2;i<=N-5;i++)
    {
        if(!st[i])
        {
            prime[cnt ++] = i;
            phi[i] = i - 1;
        }
        for(int j=0;prime[j] <= (N-5)/i; j++)
        {
            st[prime[j]*i] = true;
            if(i % prime[j] == 0)
            {
                phi[i*prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i*prime[j]] = phi[i] * (prime[j]-1);
        }
    }
}
int main()
{
    int t, cnt = 0;
    cin >> t;
    f();
    while(t--)
    {
        cnt ++;
        int n;
        cin >> n;
        cout << cnt << ' ' << n << ' ';
        int ans = 0;
        for(int i=2;i<=n;i++) ans += phi[i];
        ans = ans * 2 + 3;
        cout << ans << endl;
    }
    return 0;
}