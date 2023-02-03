#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int p[N];
int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=2;i<=n;i++)
    {
        int a;
        scanf("%d", &a);
        p[find(i)] = a;
    }
    while (q--)
    {
        int l1, l2;
        scanf("%d %d", &l1, &l2);
        vector<int> a, b;
        for(int i=0;i<l1;i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        for(int i=0;i<l2;i++)
        {
            int x;
            scanf("%d", &x);
            b.push_back(x);
        }
        bool flag = true;
        for(auto i:b)
        {
            flag = true;
            for(auto j:a) if(find(j) != i) {flag = false; break;}
            if(flag) {puts("yes");break;}
        }
        if(!flag) puts("no");
    }
    
    
    return 0;
}