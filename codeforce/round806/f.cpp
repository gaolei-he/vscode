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
const int N = 2e5+10;
int a[N], b[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(b, 0, sizeof(b));
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i] >= i) a[i] = -1;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i] == -1) continue;
            else b[a[i]] --, b[1] ++;
        }
        for(int i=1;i<=n;i++) b[i] += b[i-1];
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] == -1) continue;
            ans += b[i];
        }
        printf("%lld\n", ans);

    }
    
    return 0;
}
