#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
const int P = 131, N = 5e5+10;
typedef unsigned long long ll;
ll h1[N], h2[N], num[N];
char str1[N], str2[N];
ll get(ll h[], int l, int r)
{
    if(l > r) return h[r] - h[l+1] * num[l-r+1];
    return h[r] - h[l-1] * num[r-l+1];
}

int main()
{
    num[0] = 1;
    cin >> n;
    scanf("%s", str1+1);
    for(int i=1;i<=n;i++)
    {
        num[i] = num[i-1] * P;
        h1[i] = h1[i-1] * P + str1[i];
        h2[n-i+1] = h2[n-i+2] * P +(( str1[n-i+1] == '1') ? '0' : '1');
    }
    ll ans = 0;
    for(int i=1;i<n;i++)
    {
        int l = 0, r = min(i, n-i);
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if(get(h1, i-mid+1, i+mid) == get(h2, i+mid, i-mid+1)) l = mid;
            else r = mid - 1;
        }
        if(l>0) ans += l;
        
    }
    cout << ans << endl;
    return 0;

}