#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
int n, m;
vector<ll> ans;
inline void insert(ll x)
{
    for(auto i:ans) x = min(x, x^i);
    for(auto &i:ans) i = min(i, i^x);
    if(x) ans.push_back(x);
}
int main()
{
    ll tmp;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld", &tmp);
        insert(tmp);
    }
    cin >> m;
    sort(ans.begin(), ans.end());
    while (m--)
    {
        ll k;
        scanf("%lld", &k);
        ll res = 0;
        if(n > ans.size()) k --;
        for(auto i:ans)
        {
            if(k & 1) res ^= i;
            k >>= 1;
        }
        if(k==0) cout << res << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}