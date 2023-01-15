#include <iostream>
using namespace std;
const int N = 50010;
int a[N], s[N];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++) s[i] = (s[i-1]+a[i]) % 7;
    //for(int i=1;i<=n;i++) cout << s[i] << ' ';
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        int l = 0, r = n;
        while(s[l] != i && l <= n) l ++;
        while(s[r] != i && r >=1) r --;
        ans = max(ans, r - l);
    }
    

    cout << ans;
    return 0;
}