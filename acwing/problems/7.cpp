#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e5+10;
int f[N];
int n, m;

int main()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        int v, w, s;
        cin >> v >> w >> s;
        if(s == -1) dec(j, m, v)  f[j] = max(f[j], f[j-v]+w);
        else if(s == 0) rep(j, v, m) f[j] = max(f[j], f[j-v]+w);
        else
        {
            int t = 0;
            rep(j, 0, 20)
            {
                if((1<<j) <= s) s -= (1 << j), t = (1 << j);
                else t = s, s = 0;
                int v1 = t * v, w1 = t * w;
                dec(k, m, v1) f[k] = max(f[k], f[k-v1]+w1);
                if(!s) break; 
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}