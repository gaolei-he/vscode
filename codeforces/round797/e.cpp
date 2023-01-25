#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<PII> q;
        int n, k;
        scanf("%d %d", &n, &k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%d", &a[i]);
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] % k == 0) sum += a[i];
            else q.push_back({a[i]%k, a[i]});
        }
        sort(q.begin(), q.end());
        int cnt = 0;
        long long ans = 0;
        if(q.size() % 2 == 1)
        {
            ans = (sum + q[0].second) / k;
            q[0].first = 0;
            cnt ++;
        }
        else ans = sum / k;
        for(int i=q.size()-1;i>cnt;i--)
        {
            while(cnt < i && q[cnt].first+q[i].first < k) cnt++;
            if(cnt >= i) break;
            ans += (q[cnt].second + q[i].second) / k;
            q[cnt].first = 0, q[i].first = 0;
        }
        for(auto i:q) if(i.first) ans += i.second / k;
        cout << ans << endl;
    }
    
    return 0;
}