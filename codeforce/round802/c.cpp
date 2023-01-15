#include <cstdio>
using namespace std;
const int N = 2e5 + 2;
int T, n, x, y;
long long a, ans;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &x);
        a = x, ans = 0;
        for (int i = 2; i <= n; ++i, x = y)
        {
            scanf("%d", &y);
            if (x < y)
                ans += y - x;
            else
                ans += x - y, a += y - x;
        }
        ans += a > 0 ? a : -a;
        printf("%lld\n", ans);
    }
    return 0;
}