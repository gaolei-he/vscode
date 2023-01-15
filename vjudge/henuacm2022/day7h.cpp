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

void topsort()
{
    priority_queue<int> heap;
    vector<int> ans;
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
    for(int i=ans.size()-1;i;i--) cout << ans[i] << ' ';
    cout << ans[0] << endl;
}



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(h, -1, sizeof(h));

        idx = 0;
        cin >> n >> m;
        while (m--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            add(b, a);
            d[a] ++;
        }
        topsort();
        
    }
    
    return 0;
}