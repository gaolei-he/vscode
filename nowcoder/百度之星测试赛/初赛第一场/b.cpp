#include <set>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int N = 1e5+10;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
pii a[N];
signed main()
{
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld", &x);
        a[i].first = x;
        a[i].second = i;
    }
    sort(a+1, a+n+1, greater<pii>());
    set<int> b;
    long long sum = 0;
    for (int i = 0; i < n; i++) b.insert(i+1+k);
    for(int i=1;i<=n;i++)
    {
        auto tmp = a[i];
        auto it = b.find(tmp.second);
        if(it != b.end()) b.erase(it);
        else
        {
            for(auto i=b.begin();i!=b.end();i++)
            {
                if(*i >= tmp.second)
                {
                    sum += ((*i) * (*i) - tmp.second * tmp.second) * tmp.first;
                    b.erase(i);
                    break;
                }
            }
        }
    }
    cout << sum;
    return 0;
}