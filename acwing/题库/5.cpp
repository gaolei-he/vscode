#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e3+10;
int s[N], v[N], w[N];
int v1[N*11], w1[N*11];
int f[N*2];
int main()
{
    int n, V;
    cin >> n >> V;
    int cnt = 0;
    rep(i, 1, n) cin >> v[i] >> w[i] >> s[i];
    rep(i, 1, n)
    {
        int tmp = s[i];
        rep(j, 0, 12)
        {
            int t = (1 << j);
            if(tmp >= t) tmp -= t;
            else t = tmp, tmp = 0;
            cnt ++;
            v1[cnt] = t * v[i];
            w1[cnt] = t * w[i];
            if(!tmp) break;
        }
    }

    rep(i, v1[1], V) f[i] = w1[1];
    rep(i, 2, cnt)
        dec(j, V, v1[i])
            f[j] = max(f[j], f[j-v1[i]] + w1[i]);
    cout << f[V];

    return 0;
}