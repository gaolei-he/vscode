#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 2e5+10;
int n;
int p[2][N];
int find(int x, int op)
{
    if(p[op][x] != x) p[op][x] = find(p[op][x], op);
    return p[op][x];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pii> a;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) p[1][i] = p[0][i] = i;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            a.push_back({l, r});
        }
        bool flag = true;
        int l = 0, r = 0;
        for(auto i:a)
        {
            int t1 = find(i.first, 0), t2 = find(i.second, 0);
            if(l != t1 && l != t2 && t1 != t2)
            {
                if(l)
                {
                    p[0][l] = t1;
                    p[0][find(i.first, 0)] = find(i.second, 0);
                    l = find(i.second, 0);
                }
                else
                {
                    p[0][t1] = t2;
                    l = find(i.second, 0);
                }
                continue;
            }
            t1 = find(i.first, 1), t2 = find(i.second, 1);
            if(r != t1 && r != t2 && t1 != t2)
            {
                if(r)
                {
                    p[1][r] = t1;
                    p[1][find(i.first, 1)] = find(i.second, 1);
                    r = find(i.second, 1);
                }
                else
                {
                    p[1][t1] = t2;
                    r = find(i.second, 1);
                }
                continue;
            }
            flag = false;
            break;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    
    return 0;
}