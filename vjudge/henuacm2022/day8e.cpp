#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10;
int p[N];
int n, d;
typedef pair<int, int> PII;
PII dev[N];
bool st[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
double calc(int a, int b)
{
    a --;
    b --;
    int x1 = dev[a].first, y1 = dev[a].second;
    int x2 = dev[b].first, y2 = dev[b].second;
    return (double) sqrt(pow(abs(x1-x2), 2)+pow(abs(y1-y2), 2)) - 1e-4;
}

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        dev[i].first = t1, dev[i].second = t2;
    }
    for(int i=1;i<=n;i++) p[i] = i;

    string tmp;
    while (cin >> tmp)
    {
        int a, b;
        if(tmp == "O")
        {
            cin >> a;
            st[a] = true;
            for(int i=1;i<=n;i++)
            {
                if(a == i) continue;
                else if(st[i] && calc(i, a) <= d)
                    p[find(a)] = find(i);
            }
        }
        else
        {
            cin >> a >> b;
            if(find(a) == find(b)) puts("SUCCESS");
            else puts("FAIL");
        }
    }
    
    
    
    return 0;
}