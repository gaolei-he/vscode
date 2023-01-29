#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N];

bool rule(int a, int b)
{
    return a > b;
}

int main()
{
    int n, L;
    cin >> n >> L;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int i = n - 1, j = n - 2;
    int h;
    for(h=n;h>0;h--)
    {
        int l = n - h, r = n - 1;
        while(l<r)
        {
            int mid = l + r + 1 >> 1;
            if(a[mid]>h-1) r = mid - 1;
            else l = mid;
        }
        int tmp1 = l;//h-1 right border
        l = n - h, r = n - 1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if(a[mid]<h-1) l = mid + 1;
            else r = mid;
        }
        int tmp2 = l;
        int ans;
        if(a[tmp2]!=h-1) ans = n - tmp2;
        else ans = n - 1 - tmp1 + min(tmp1-tmp2+1, L);
        if(ans>=h) break;
        
    }
    cout << h;
    return 0;
}