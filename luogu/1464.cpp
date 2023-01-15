#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll ans[21][21][21];
ll w(ll a, ll b, ll c)
{
    if(a<=0||b<=0||c<=0) return 1;
    else if(ans[a][b][c]) return ans[a][b][c];
    else if(a>20||b>20||c>20)
    {
        a = b = c = 20;
        ans[a][b][c] = w(20, 20, 20);
    }
    else if(a<b&&b<c) ans[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else ans[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return ans[a][b][c];
}

int main()
{
    ll a, b, c, sum;
    
    memset(ans, 0, sizeof(ans));
    
    while(cin>>a>>b>>c)
    {
        if(a==-1&&b==-1&&c==-1) break;

        
        if(a<=0||b<=0||c<=0) sum = 1;
        else if(a>20||b>20||c>20) sum = w(20, 20, 20);
        else sum = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, sum);
    }
    return 0;
}