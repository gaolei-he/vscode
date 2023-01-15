#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);

    for(int i=0;i<m;i++)
    {
        int l = 0, r = n - 1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if(a[mid]>=b[i]) r = mid;
            else l = mid + 1;
        }
        if(a[l]==b[i]) cout << l+1 << " ";
        else cout << -1 << " ";
    }
    return 0;
}