#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int t;
    cin >> t;
    queue<PII> q;
    while (t--)
    {
        int n;
        cin >> n;
        int st[n], ed[n];
        for(int i=0;i<n;i++) scanf("%d", &st[i]);
        for(int i=0;i<n;i++) scanf("%d", &ed[i]);
        int ans[n];
        ans[0] = st[0];
        q.push({st[0], ed[0]});
        for (int i = 1; i < n; i++)
        {
            if(st[i]<q.back().second) ans[i] = q.back().second;
            else ans[i] = st[i];
            q.push({st[i], ed[i]});
        }
        for (int i = 0; i < n; i++)
        {
            cout << ed[i] - ans[i] << ' ';
        }
        puts("");
        
    }
    
    return 0;
}