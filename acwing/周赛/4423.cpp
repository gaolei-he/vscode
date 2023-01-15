#include <iostream>
using namespace std;
const int N = 2e5+10;
int a[N], q[N], n, cnt = -1;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] == 0) q[++cnt] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = cnt;
        while (l<r)
        {
            int mid = l + r >> 1;
            if(q[mid] >= i) r = mid;
            else l = mid + 1;
        }
        printf("%d ", min(abs(q[l]-i), abs(q[(l-1)<0?0:(l-1)]-i)));
        
    }
    
    return 0;
}