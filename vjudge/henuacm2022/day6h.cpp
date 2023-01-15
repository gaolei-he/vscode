#include <cstring>
#include <iostream>
using namespace std;
int n, ans;
const int N = 12;
bool st[N], stl[2*N], str[2*N];
void dfs(int k)
{
    if(k >= n)
    {
        ans ++;

        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i]&&!stl[n-k+i]&&!str[k+i-1])
        {
            st[i] = stl[n-k+i] = str[k+i-1] = true;
            dfs(k+1);
            st[i] = stl[n-k+i] = str[k+i-1] = false;
        }
    }
}

int main()
{
    
    while (1)
    {
        cin >> n;
        if(!n) break;
        else if(n>10) cout << 0 << endl;
        dfs(0);
        cout << ans << endl;
        ans = 0;
    }
    
    return 0;
}
