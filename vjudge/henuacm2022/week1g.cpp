#include <cstring>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 500+10;
bool res = true;
int a[N], tmp[N], n, x, ans;
void quick_sort(int l, int r)
{
    if(!res) return;
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    while(i<j)
    {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(a[i] > a[j] && i < j)
        {
            if(a[i] > x)
            {
                swap(a[i], x);
                ans ++;
                if(a[i] > a[j]) swap(a[i], a[j]);
            }
            else res = false;
            if(!res) return;
        }
    }
    quick_sort(l, j), quick_sort(j+1, r);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        quick_sort(0, n-1);
        if(res) cout <<  ans << endl;
        else cout << -1 << endl;
        
    }
    
    return 0;
}
