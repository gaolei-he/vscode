#include <iostream>
using namespace std;
const int N=100000010;

int cnt,primes[N];
bool st[N];

void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;//primes[j]小于i的所有质因子，小于等于primes[j] * j的所有质因子
            if(i% primes[j]==0) break;//primes[j]一定是i的最小质因子
        }
    }
}

int main()
{
    int n;
    cin>>n;

    get_prime(n);

    cout<<cnt<<endl;
    return 0;
}