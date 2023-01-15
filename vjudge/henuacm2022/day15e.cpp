//O(mn)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 510, M = 1e5+10;

int h[N], e[M], ne[M], idx;
int match[N], match1[N];
bool st[N];
int n;
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

    while (cin >> n )
    {


        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        idx = 0;
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                if(x) add(i+1, j+1);
            }
            
        }
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            memset(st, false, sizeof(st));
            if(find(i)) res ++;
        }
        //
        if(res != n) puts("-1");
        else
        {
            for(int i=1;i<=n;i++) match1[match[i]] = i;
            int cnt = 0;
            vector<pair<int, int> > ans;
            for(int i=1;i<=n;i++)
            {
                if(i != match1[i])
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(match1[j] == i)
                        {

                            swap(match1[j], match1[i]);
                            cnt ++;
                            ans.push_back({match1[i], match1[j]});
                        }
                    }
                }
            }
            cout << cnt << endl;
            for(auto i:ans) cout << "C " << i.first << ' ' << i.second << endl;
        }
        
    }
    
    
    return 0;
}
