#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=100010,mod=1e9+7;

ll fact[N],infact[N];

ll quick_pow(ll a,ll k,ll p)
{
    ll res=1%p;
    while(k)
    {
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}


int main()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        infact[i]=infact[i-1]*quick_pow(i,mod-2,mod)%mod;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}