#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int n;
    cin >> n;
    vector<PII> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = a.size() - 1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if (a[mid].first >= x) r = mid;
            else l = mid + 1;
        }
        if(a[l].first != x) printf("0\n");
        else printf("%d\n", a[l].second+1);
    }
    
    
}