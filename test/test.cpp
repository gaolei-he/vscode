#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
int a[1000010];
using namespace std;
using ll = long long;
signed main()
{
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) ans += a[i] * (n - i);
    cout << ans << endl;
    return 0;
}
