#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4+10;
int a[N];

int main()
{
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bool flag = true;
    sort(a, a+n);
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(a[i] + a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(a[i] + a[l] == k && l < n)
        {
            printf("%d %d\n", a[i], a[l]);
            flag = false;
        }
    }
    if(flag) puts("No Solution");
    return 0;

}