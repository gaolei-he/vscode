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
const int N = 1e6+10;
ll phi[N];
int prime[N];
bool st[N];
void f()
{
    int cnt = 0;
    phi[1] = 0;
    for(int i=2;i<=N-5;i++)
    {
        if(!st[i])
        {
            phi[i] = i - 1;
            prime[cnt ++] = i;
        }
        for(int j=0;prime[j] <= (N-5)/i;j++)
        {
            st[prime[j]*i] = true;
            if(i % prime[j] == 0)
            {
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    for(int i=2;i<=N-5;i++) phi[i] += phi[i-1];
}
int main()
{
    int n;
    f();
    while (cin >> n)
    {
        if(!n) break;
        printf("%lld\n", phi[n]);
    }
    
    
    return 0;
}