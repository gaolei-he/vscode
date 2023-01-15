#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n, k;
const int N = 2e5+10;
int a[N];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        vector<pair<int, int> > ans;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            ans.push_back({a[i], i});
        }
        sort(ans.begin(), ans.end(), cmp);
        while (k--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int l = 0, r = ans.size() - 1;
            while(l < r)
            {
                int mid = l + r - 1 >> 1;
                if(ans[mid].first >= a) r = mid;
                else l = mid + 1;
            }
            if(ans[l].first != a)
            {
                puts("NO");
                continue;
            }
            int t1 = l;
            l = 0, r = ans.size() - 1;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(ans[mid].first > b) r = mid - 1;
                else l = mid;
            }
            if(ans[l].first != b)
            {
                puts("NO");
                continue;
            }
            if(ans[l].second < ans[t1].second) puts("NO");
            else puts("YES");
        }
        
    }
    
    return 0;
}