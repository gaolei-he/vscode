//O(mn)
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e5+10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x)
{
    for(int i=h[x];~i;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(1)
    {
        scanf("%d", &n1);
        if(!n1) break;
        scanf("%d %d", &n2, &m);
        memset(h, -1, sizeof(h));
        memset(match, 0, sizeof(match));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        idx = 0;
        while (m--)
        {
            int a, b;
            scanf("%d", &a);
            scanf("%d %d", &a, &b);
            add(a, b);
        }
        int res = 0;
        for(int i=1;i<=n1;i++)
        {
            memset(st, false, sizeof(st));
            if(find(i)) res ++;
        }
        cout << res << endl;
    }
    
    return 0;
}