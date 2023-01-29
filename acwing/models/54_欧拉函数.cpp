#include <iostream>

using namespace std;
#define ll long long

const int mod=1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=n;
        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                res=res/i*(i-1);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) res=res/n*(n-1);

        cout<<res<<endl;
    }
    return 0;
}