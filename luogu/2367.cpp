#include <iostream>
using namespace std;
const int N = 5e6+10;
int a[N], s[N];
int main()
{
    int n, p;
    cin >> n >> p;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        a[i] += x, a[i+1] -= x;
    }
    while (p--)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x] += z, a[y+1] -= z;
    }
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    int ans = 1e9;
    for(int i=1;i<=n;i++) ans = min(s[i], ans);
    cout << ans << endl;
    return 0;
}