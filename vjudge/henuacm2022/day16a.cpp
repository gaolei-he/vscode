#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int E, F, n;
const int N = 510;
int w[N], v[N];
int f[10010];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, 0x3f, sizeof(f));

        scanf("%d %d %d", &E, &F, &n);
        for(int i=1;i<=n;i++) scanf("%d %d", &v[i], &w[i]);
        f[0] = 0;

        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=F-E;j++)
            {
                f[j] = min(f[j], f[j-w[i]]+v[i]);
            }
        if(f[F-E] != inf) cout << "The minimum amount of money in the piggy-bank is " << f[F-E] << ".\n";
        else cout << "This is impossible.\n";
    }
    
    return 0;
}