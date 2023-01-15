/*
#include <cstring>
#include <iostream>
using namespace std;
int lou[1000];
bool st[1000];
int n, a, b;
const int N = 1e5+10;
int q[N], tmp[N], hh1 = 0, hh2 = 0, tt1 = -1, tt2 = -1;

int bfs()
{
    q[++tt1] = a;
    st[a] = true;
    tmp[++tt2] = a;
    int cnt = 0;
    st[a] = true;
    if(a==b) return cnt + 1;
    while (1)
    {
        cnt ++;
        if (cnt>1000) return 0;
        hh1 = 0, tt1 = -1;
        while (hh2<=tt2)
        {
            int t = tmp[hh2++];
            
            
            if (t == b) return cnt;
            if (t + lou[t] <= n && st[t+lou[t]] == false) 
            {
                q[++tt1] = t + lou[t];
                st[t + lou[t]] = true;
            }
            if (t - lou[t] >= 1 && st[t-lou[t]] == false)
            {
                q[++tt1] = t - lou[t];
                st[t - lou[t]] = true;
            }
        }
        for (int i = 0; i < tt1 - hh1 + 1; i++)
        {
            tmp[i] = q[hh1 + i];
        }
        hh2 = 0, tt2 = tt1 - hh1;
        
    }
    
    
}

int main()
{
    cin >> n >> a >> b;

    for(int i=1;i<=n;i++) scanf("%d", &lou[i]);

    cout << bfs() - 1 << endl;
    
    return 0;
}
*/
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int lou[1000];
bool st[1000];
int n, a, b;
const int N = 1e5+10;
queue<int>  q, tmp;
int bfs()
{
    q.push(a);
    st[a] = true;
    tmp.push(a);
    int cnt = 0;
    st[a] = true;
    if(a==b) return cnt + 1;
    while (1)
    {
        cnt ++;
        if (cnt>1000) return 0;

        while (!tmp.empty())
        {
            int t = tmp.front();tmp.pop();
            
            
            if (t == b) return cnt;
            if (t + lou[t] <= n && st[t+lou[t]] == false) 
            {
                q.push(t + lou[t]);
                st[t + lou[t]] = true;
            }
            if (t - lou[t] >= 1 && st[t-lou[t]] == false)
            {
                q.push(t - lou[t]);
                st[t - lou[t]] = true;
            }
        }
        tmp = q;
        q = queue<int>();
        
    }
    
    
}

int main()
{
    cin >> n >> a >> b;

    for(int i=1;i<=n;i++) scanf("%d", &lou[i]);

    cout << bfs() - 1 << endl;
    
    return 0;
}