#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
const long long N = 1550;
long long a[N];
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++) scanf("%lld", &a[i]);
    vector<pii> ans;
    for(long long i=1;i<=n;i++)
        for(long long j=i;j<=n;j++) ans.push_back({a[i]*a[j], i});
    
    sort(ans.begin(), ans.end());
    //for(auto i:ans) cout << i.first << ' ' << i.second << endl;
    long long cnt = 0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if(a[i] == 0 && a[j] == 0)
            {
                cnt ++;
                break;
            }
            else if(a[j] == 0) continue;
            if(a[i] % a[j] == 0)
            {
                pii tmp = {a[i]/a[j], 2000};
                auto it = upper_bound(ans.begin(), ans.end(), tmp);
                it --;
                if(it >= ans.begin() && (*it).second > i && (*it).first == tmp.first)
                {
                    cnt ++;
                    break;
                }

            }
        }
    }
    cout << cnt << endl;
    return 0;
}
