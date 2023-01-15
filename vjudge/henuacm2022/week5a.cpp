#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
vector<pii> v;
ll n, m;
bool check(ll mid)
{
    ll tmp = m;
    for(auto i:v)
    {
        tmp -= mid / i.second * i.first;
        if(tmp <= 0) return true;
    }
    return false;
}

int main()
{
    
    cin >> n >> m;
   
    while (n--)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        v.push_back({a, b});
        m -= a;
    }
    ll ans = 0;

    ll l = 0, r = 1e18+10;
    if(m <= 0) cout << 0 << endl;
    else
    {
        while (l < r)
        {
            ll mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}