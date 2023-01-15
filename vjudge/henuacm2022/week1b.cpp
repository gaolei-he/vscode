#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N], n, tmp[N];
bool check(int mid)
{
    memcpy(tmp, a, sizeof(int)*n);
    tmp[0] -= mid;
    for(int i=1;i<n;i++)
    {
        if(tmp[i] <= tmp[i-1])
        {
            int t1 = tmp[i];
            tmp[i] = tmp[i-1] + 1;
            if(tmp[i] - t1 > mid) return false;
        }
        else if(tmp[i] - mid <= tmp[i-1]) tmp[i] = tmp[i-1] + 1;
        else tmp[i] -= mid;
    }
    return true;
}

int main()
{
    int t, cnt = 0;
    cin >> t;
    while (t--)
    {
        cnt ++;
        cin >> n;
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        int l = 0, r = 1e6+10;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("Case #%d:\n", cnt);
        cout << l << endl;
        
    }
    
    return 0;
}