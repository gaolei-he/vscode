#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[22], n;
bool st[22];
void print()
{
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    puts("");
}
void dfs(int k)
{
    if(k == n+1)print();
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            a[k] = i;
            st[i] = true;
            dfs(k+1);
            st[i] = false;
        }
    }
}

int main()
{
    
    cin >> n;
    for(int i=1;i<=n;i++) a[i] = i;

    dfs(1);
    
    return 0;
}