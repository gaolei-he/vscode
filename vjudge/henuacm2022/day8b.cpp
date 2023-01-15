#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e3+10;
int p[N], m, n;
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++) p[i] = i;
        while (m--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            p[find(a)] = find(b);
        }
        vector<int> tmp;
        for(int i=1;i<=n;i++) tmp.push_back(find(i));
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        cout << tmp.size() << endl;
        
    }
    
    return 0;
}