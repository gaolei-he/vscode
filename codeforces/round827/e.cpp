#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int a[N], s[N];

signed main()
{
    int t;
    cin >> t;
    a[0] = 1e9+10;
    while (t --)
    {
        int n, q;
        cin >> n >> q;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);
            s[i] = s[i-1] + a[i];
        }
        vector<int> lst;
        for (int i = 0; i < q; i++)
        {
            int x;
            scanf("%lld", &x);
            lst.push_back(x);
        }
        set<pii> que;
        for(auto i:lst)
        {
            pii tmp1 = {i, 1e18+10};
            auto tmp = upper_bound(que.begin(), que.end(), tmp1);
            // auto tmp = que.begin();
            int ans = 0;
            if(tmp != que.begin())
            {
                ans = (*--tmp).second;
            }

            
            // if(tmp != que.end())ans = (*tmp).second;
            for(int j=ans + 1;j<=n;j++) if(a[j] <= i) ans ++; else break;
            que.insert({i, ans});
            // if(ans > n) ans = n;
            printf("%lld ", s[ans]);
        }
        puts("");
    }
    
    return 0;
}