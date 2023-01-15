#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
ll n, m, x;
bool st[N];
ll dist[N], h[N], e[N*4], ne[N*4], w[N*4], idx;
void add(ll a, ll b, ll c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c;
    h[a] = idx ++;
}
void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())
    {
        ll t = q.front();
        q.pop();
        st[t] = false;
        
        for(ll i=h[t];~i;i=ne[i])
        {
            ll j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> x;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        add(v+n, u, w);
        add(u, v+n, w+x);
        add(u+n, v, w);
        add(v, u+n, w+x);
    }
    spfa();
    cout << min(dist[n], dist[2*n]);
    
    return 0;
}