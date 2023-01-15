#include <iostream>
int tmp[100009];
using namespace std;
void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i=l,j=0;i<=r;i++, j++) a[i] = tmp[j];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    merge_sort(a, 0, n-1);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]) a[i] = 0;
        if(a[i]) cnt ++;
    }
    cout << cnt << endl;
    for(int i=0;i<n;i++) if(a[i]) printf("%d ", a[i]);

    return 0;
}