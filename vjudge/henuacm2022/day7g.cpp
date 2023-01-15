#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5+10;
int e[N], ne[N], h[N], idx;
int n, m;
int d[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx ++;
}
vector<int> ans;
void topsort()
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=1;i<=n;i++) if(!d[i]) heap.push(i);
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        ans.push_back(t);
        for(int i=h[t];~i;i=ne[i])
        {
            int j = e[i];
            d[j] --;
            if(!d[j]) heap.push(j);
        }
    }
    for(int i=0;i<ans.size()-1;i++) cout << ans[i] << ' ';
    cout << ans[n-1] << endl;
}



int main()
{
    while (cin >> n)
    {
        ans.clear();
        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        memset(d, 0, sizeof(d));
        idx = 0;
        cin >> m;
        while (m--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            add(a, b);
            d[b] ++;
        }
        topsort();
        
    }
    
    return 0;
}