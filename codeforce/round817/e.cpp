#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1010;
ll st[N][N];
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(st, 0, sizeof(st));
        int n, q;
        scanf("%lld %lld", &n, &q);
        for (int i = 0; i < n; i++)
        {
            int h, w;
            scanf("%lld %lld", &h, &w);
            st[h][w] ++;
        }
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                if(st[i][j]) st[i][j] = i * j * st[i][j];
                st[i][j] += st[i-1][j] + st[i][j-1] - st[i-1][j-1];
                // cout << st[i][j] << ' ';
            }
            // puts("");
        }
        while (q--)
        {
            int h1, w1, h2, w2;
            scanf("%lld %lld %lld %lld", &h1, &w1, &h2, &w2);
            ll sum = st[h2-1][w2-1] + st[h1][w1] - st[h1][w2-1] - st[h2-1][w1];
            printf("%lld\n", sum);
        }
        
    }
    
    return 0;
}