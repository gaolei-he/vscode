#include <iostream>
int a[20020], tmp[20020];
using namespace std;
void merge_sort(int a[], int l, int r);
int main()
{
    int n, b;
    cin >> n >> b;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    
    merge_sort(a, 0, n-1);
    int sum = 0, cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        sum += a[i];
        cnt ++;
        if(sum>=b) break;
    }
    cout << cnt;

}
void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid&&j<=r)
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(i=l, j=0;i<=r;i++, j++) a[i] = tmp[j];
}