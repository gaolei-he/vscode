#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int N=1000010;

int cnt,primes[N];
int phi[N];
bool st[N];

ll get_eulers(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;//质数p的欧拉函数为p-1
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i% primes[j]==0)
            {
                phi[i*primes[j]]=primes[j]*phi[i];
                break;
            }
            phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++) res += phi[i] * (n / i);
    return res;
}
int main()
{
    ll n;
    cin >> n;
    cout << n * (n + 1) / 2 << endl;

}
//1 3 6 10 15 21 28
//1 2 3 4 5 6 7
/*
n = int(input())
print(int(n * (n + 1) / 2))
*/