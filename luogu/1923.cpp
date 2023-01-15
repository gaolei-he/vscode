#include <iostream>
#pragma GCC optimize(2)
#define N 5000009
#include <algorithm>
int a[N];
int tmp[N];
void merge_sort(int a[], int l, int r);
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    //nth_element(a, a+k, a+n);

    merge_sort(a, 0, n-1);
    //for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("%d", a[k]);
    return 0;
}

void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(i=l, j=0;i<=r;i++, j++) a[i] = tmp[j];
}