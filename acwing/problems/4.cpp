#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 110;
int f[N];
int main()
{
    int n, V;
    cin >> n >> V;
    rep(i, 1, n)
    {
        int v, w, s;
        cin >> v >> w >> s;
        dec(j, V, 0)
            rep(k, 1, min(s, j/v))
                f[j] = max(f[j], f[j-k*v]+k*w);
    }
    cout << f[V];
    return 0;
}