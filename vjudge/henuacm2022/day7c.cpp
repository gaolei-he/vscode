#include <iostream>
#include <queue>
using namespace std;
int n, k;
int ans = 0;
bool res = false;
bool st[200000+10];
void bfs()
{
    if(n == k) return;
    st[n] = true;
    queue<int> q;
    q.push(n);
    while(q.size())
    {
        ans ++;
        queue<int> tmp;
        while(q.size())
        {
            int t = q.front();
            q.pop();
            
            if(t - 1 > 0 && !st[t-1])
            {
                tmp.push(t-1);
                st[t-1] = true;
            }
            if(!st[t+1] && t+1<1e5+10) tmp.push(t+1);
            st[t+1] = true;
            if(2*t < 2e5+10 && !st[2*t])
            {
                tmp.push(t*2);
                st[2*t] = true;
            }
            if(t-1==k || t+1==k || 2*t==k)
            {
                res = true;
                break;
            }
        }
        if(res) break;
        q = tmp;
    }
}

int main()
{
    
    cin >> n >> k;
    bfs();
    
    cout << ans;
    return 0;
}