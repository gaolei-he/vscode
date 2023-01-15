#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int p[N];
typedef pair<int, int> PII;
vector<PII> ans;
int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main()
{

    int a, b;
    while (1)
    {
        bool res = false;
        for(int i=1;i<=N-5;i++) p[i] = i;
        ans.clear();
        cin >> a >> b;
        if(a == -1) break;
        else if(a == 0)
        {
            puts("Yes");
            continue;
        }
        ans.push_back({a, b});
        
        while (a)
        {
            cin >> a >> b;
            if(!a) break;
            ans.push_back({a, b});
        }

        for(auto i:ans)
        {
            if(find(i.first) == find(i.second))
            {
                res = true;
                break;
            }
            else p[find(i.first)] = find(i.second);
        }
        
        
        
        if(res) puts("No");
        else
        {
            vector<int> tmp;
            for(auto i:ans)
            {
                tmp.push_back(find(i.first));
                tmp.push_back(find(i.second));
            }
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            if(tmp.size() > 1) puts("No");
            else puts("Yes");
        }
    }
    
    
    return 0;
}