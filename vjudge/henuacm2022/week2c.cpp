#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
int p[2][N];
int n, m1, m2;
typedef pair<int, int> PII;

int find(int x, int op)
{
    if(p[op][x] != x) p[op][x] = find(p[op][x], op);
    return p[op][x];
}
int main()
{
    cin >> n >> m1 >> m2;
    for(int i=1;i<=n;i++) p[0][i] = p[1][i] = i;
    while (m1--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        p[0][find(u, 0)] = find(v, 0);
    }
    while(m2--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        p[1][find(u, 1)] = find(v, 1);
    }
    int cnt = 0;
    vector<PII> a;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int i0 = find(i, 0), j0 = find(j, 0);
            int i1 = find(i, 1), j1 = find(j, 1);
            if(i0 != j0 && i1 != j1)
            {
                p[0][i0] = j0;
                p[1][i1] = j1;
                a.push_back({i, j});
                cnt ++;
            }
        }
    }
    cout << cnt << endl;
    for(auto i:a) cout << i.first << ' ' << i.second << endl;
    return 0;
}
/*
1 2 3 4 5       6 7 8 9 10
1 2 3 4 5

*/