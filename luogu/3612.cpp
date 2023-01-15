#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    ll n;
    cin >> s >> n;
    ll t = s.size();
    ll l = t;
    while(t<n) t <<= 1;
    while(t!=l)
    {
        t >>= 1;
        if(n<=t) continue;
        if(n==t+1) n = t;
        else n -= 1 + t;
    }
    cout << s[n-1];
    return 0;
}