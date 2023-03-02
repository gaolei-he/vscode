#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3+10;
typedef pair<pair<int, int>, int> pii1;
typedef pair<pair<int, int>, double> pii2;
int p[N], ans[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n;
    cin >> n;
    vector<pii1> a;
    for(int i=1;i<=N-5;i++) p[i] = i;
    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        a.push_back({{x, y}, v});
    }
    vector<pii2> b;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = a[i].first.first, x2 = a[j].first.first;
            int y1 = a[i].first.second, y2 = a[j].first.second;
            double t = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) / (a[i].second + a[j].second);
            b.push_back({{i, j}, t});
        }
        
    }
    sort(b.begin(), b.end(), [](pii2 a, pii2 b){
        return a.second < b.second;
    });
    // for(auto i:b) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    int num = n;
    int cnt = 0;
    for(auto i:b)
    {
        if(find(i.first.first) == find(i.first.second)) continue;
        else
        {
            p[find(i.first.first)] = find(i.first.second);
            int tmp = ceil(i.second);
            tmp = min(tmp, 1005);
            for(int j=cnt;j<tmp;j++) ans[j] = num;
            num --;
            cnt = tmp;
        }
    }
    
    for(int i=cnt;i<N;i++) ans[i] = num;
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        cout << ans[t] << endl;
    }
    
    return 0;
}