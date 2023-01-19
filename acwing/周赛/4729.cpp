#include <iostream>
#include <cmath>
#define int long long
using namespace std;
signed main()
{
    int k; cin >> k;
    while(k --)
    {
        int n, d, e;
        cin >> n >> d >> e;
        int a = 1, c = n, b = e * d - 1 - n;
        if(b * b - 4 * a * c <= 0) cout << "NO\n";
        else
        {
            int l = 1, r = -b / 2;
            while(l < r)
            {
                int mid = l + r >> 1;
                if(mid * mid + b * mid + c > 0) l = mid + 1;
                else r = mid;
            }
            int ans1 = l;
            l = -b / 2, r = 1e9+10;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(mid * mid + b * mid + c > 0) r = mid - 1;
                else l = mid;
            }
            int ans2 = l;
            if(ans2 < ans1) swap(ans1, ans2);
            cout << ans1 << ' ' << ans2 << endl;
        }
    }
    return 0;
}
