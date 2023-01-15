#include <iostream>

using namespace std;

#define ll long long

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
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<quick_pow(a,b,c)<<endl;
    }
    return 0;
}