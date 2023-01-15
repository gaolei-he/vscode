#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int tmp[2*N];
int ans[N];
int n, m;
int main()
{
    
    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &tmp[i]);
    }
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n + m; i++)
    {
        int x;
        scanf("%d", &x);
        if(x) b[cntb++] = tmp[i];
        else a[cnta++] = tmp[i];
    }
    b[m] = b[m-1];
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = m - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        if(l - 1 >= 0&& abs(a[i]-b[l-1]) <= abs(a[i]-b[l])) ans[l-1] ++;
        else ans[l] ++;
        
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ", ans[i]);
    }
    
    
    return 0;
}