#include <iostream>
using namespace std;
const int N = 5e4+10;

int l, n, m, a[N];

bool check(int mid)
{
    int cnt = 0, now = 0;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]-now<mid)
        {
            cnt ++;
        }
        else now = a[i];
    }
    //if(l-a[n]<mid) cnt ++;
    if(cnt>m) return true;
    else return false;
}


int main()
{
    
    
    cin >> l >> n >> m;
    a[0] = 0, a[n+1] = l;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    int l = 1, r = 1e9;
    
    while(l<r)
    {
        int mid = l + r + 1>> 1;
        if(check(mid)) r = mid - 1;
        else l = mid;
    }
    //if(check(4459)) cout << "YES";
    cout << r;
    return 0;
}