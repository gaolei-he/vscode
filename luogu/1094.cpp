#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3e4+10;
int a[N], tmp[N];

void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];

    for(int i=l, j=0;i<=r;i++, j++) a[i] = tmp[j];
}


int main()
{
    int w, n;
    cin >> w >> n;

    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n-1);
    int sum = 0;
    for(int i=n-1, j=0;i>=0;i--)
    {
        int tmp = a[i];
        while(tmp+a[j]<=w)
        {
            if(i<=j) break;
            tmp += a[j++];
        }
        
        sum ++;
        if(i<=j) break;
        
    }
    cout << sum;
    return 0;
}