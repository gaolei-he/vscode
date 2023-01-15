#include <iostream>
using namespace std;

const int N = 1e5+10;
int a[N], s[N];
int n, m;

bool check(int mid)
{
    int sum = 0, j = 0;
    for(int i=1;i<=n;i++)
    {
        while(s[i]-s[j]<=mid&&i<=n) i++;
        sum ++;
        j = i - 1;
        if(i>n) break;
        i --;
    }
    if(sum<=m) return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    int ma = 0;
    for(int i=1;i<=n;i++) ma = max(a[i], ma);
    int l = ma, r = 1e9;
    while(l<r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;

    return 0;
}