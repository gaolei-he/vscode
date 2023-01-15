#include <iostream>
using namespace std;
const int N = 2e5+10;
char str[N];
int ans;
int dfs(int l, int r, int cnt, int total)
{
    if(l >= r)
    {
        if(str[l] != 'a' + cnt) return total+1;
        else return total;
    }
    int mid = l + r >> 1;
    int cntl = 0, cntr = 0;
    for(int i=l, j=mid+1;i<=mid;i++, j++)
    {
        if(str[i] != 'a' + cnt) cntl ++;
        if(str[j] != 'a' + cnt) cntr ++;
    }
    return min(cntl+dfs(mid+1, r, cnt+1, total)+total, cntr+dfs(l, mid, cnt+1, total)+total);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        scanf("%s", str+1);
        int cnt = 0;
        cout << dfs(1, n, cnt, 0) << endl;
    }
    
    return 0;
}