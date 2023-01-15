#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[22], n;
bool st[22];
bool isPrime(int k)
{
    if(k < 2) return false;
    for(int i=2;i<=k/i;i++)
        if(k  % i == 0) return false;
    return true;
}
void print()
{
    for(int i=1;i<n;i++) cout << a[i] << ' ';
    cout << a[n];
    puts("");
}
void dfs(int cnt)
{
    if(cnt == n && isPrime(a[1]+a[n])) print();
    for(int i=2;i<=n;i++)
    {
        if(!st[i] && isPrime(a[cnt]+i))
        {
            a[cnt+1] = i;
            st[i] = true;
            dfs(cnt + 1);
            st[i] = false;
        }
    }
}

int main()
{
    int t = 0;
    a[1] = 1;
    while(cin>>n)
    {
        memset(st, 0, sizeof(st));
        t ++;
        cout << "Case " << t << ":\n"; 
        dfs(1);
        puts("");
    }
    return 0;
}