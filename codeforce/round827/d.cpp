#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> a;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back({x, i+1});
        }
        sort(a.begin(), a.end(), [](pii a, pii b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<pii> b;
        for(int i=0;i<a.size();i++)
        {
            if(i != a.size() - 1 && a[i].first == a[i+1].first) continue;
            b.push_back({a[i]});
        }
        int ans = -1;
        // for(auto i:b) cout << i.first << ' ' << i.second << endl;
        for(int i=0;i<b.size();i++)
        {
            for(int j=i;j<b.size();j++)
            {
                if(__gcd(b[i].first, b[j].first) == 1) ans = max(ans, b[i].second+b[j].second);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}